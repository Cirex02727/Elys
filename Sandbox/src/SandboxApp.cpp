#include <Elys.h>
#include <Elys/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class ExampleLayer : public Elys::Layer
{
	public:
		ExampleLayer()
			: Layer("Example"), m_CameraController(1280.0f / 720.0f, true)
		{
			m_VertexArray = Elys::VertexArray::Create();

			float vertices[3 * 7] = {
				-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
				 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
				 0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			};

			Elys::Ref<Elys::VertexBuffer> m_VertexBuffer;
			m_VertexBuffer = Elys::VertexBuffer::Create(vertices, sizeof(vertices));
			Elys::BufferLayout layout = {
				{ Elys::ShaderDataType::Float3, "a_Position" },
				{ Elys::ShaderDataType::Float4, "a_Color" },
			};

			m_VertexBuffer->SetLayout(layout);
			m_VertexArray->AddVertexBuffer(m_VertexBuffer);

			uint32_t indices[3] = { 0, 1, 2 };
			Elys::Ref<Elys::IndexBuffer> m_IndexBuffer;
			m_IndexBuffer = Elys::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
			m_VertexArray->SetIndexBuffer(m_IndexBuffer);


			m_SquareVA = Elys::VertexArray::Create();

			float squareVertices[5 * 4] = {
				-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
				 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
				 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
				-0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
			};

			Elys::Ref<Elys::VertexBuffer> squareVB;
			squareVB = Elys::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
			squareVB->SetLayout({
				{ Elys::ShaderDataType::Float3, "a_Position" },
				{ Elys::ShaderDataType::Float2, "a_TexCoord" },
			});
			m_SquareVA->AddVertexBuffer(squareVB);

			uint32_t sqareIndices[6] = { 0, 1, 2, 2, 3, 0 };
			Elys::Ref<Elys::IndexBuffer> squareIB;
			squareIB = Elys::IndexBuffer::Create(sqareIndices, sizeof(sqareIndices) / sizeof(uint32_t));
			m_SquareVA->SetIndexBuffer(squareIB);

			std::string vertexSrc = R"(
				#version 330 core
				
				layout(location = 0) in vec3 a_Position;
				layout(location = 1) in vec4 a_Color;
				
				uniform mat4 u_ViewProjection;
				uniform mat4 u_Transform;
				
				out vec3 v_Position;
				out vec4 v_Color;
				
				void main()
				{
					v_Position = a_Position;
					v_Color = a_Color;
					gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
				}
			)";

			std::string fragmentSrc = R"(
				#version 330 core
				
				layout(location = 0) out vec4 color;
				
				in vec3 v_Position;
				in vec4 v_Color;
				
				void main()
				{
					color = v_Color;
				}
			)";

			m_Shader= Elys::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

			std::string flatColorVertexSrc = R"(
				#version 330 core
				
				layout(location = 0) in vec3 a_Position;
				
				uniform mat4 u_ViewProjection;
				uniform mat4 u_Transform;
				
				out vec3 v_Position;
				
				void main()
				{
					v_Position = a_Position;
					gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
				}
			)";

			std::string flatColorFragmentSrc = R"(
				#version 330 core
			
				layout(location = 0) out vec4 color;
			
				in vec3 v_Position;
				
				uniform vec3 u_Color;
			
				void main()
				{
					color = vec4(u_Color, 1.0);
				}
			)";

			m_FlatColorShader = Elys::Shader::Create("FloatColor", flatColorVertexSrc, flatColorFragmentSrc);

			auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

			m_Texture = Elys::Texture2D::Create("assets/textures/Checkerboard.png");
			m_ChernoLogoTexture = Elys::Texture2D::Create("assets/textures/ChernoLogo.png");

			std::dynamic_pointer_cast<Elys::OpenGLShader>(textureShader)->Bind();
			std::dynamic_pointer_cast<Elys::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
		}

		void OnUpdate(Elys::Timestep ts) override
		{
			// Update
			m_CameraController.OnUpdate(ts);

			// Render
			Elys::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			Elys::RenderCommand::Clear();

			Elys::Renderer::BeginScene(m_CameraController.GetCamera());

			glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

			std::dynamic_pointer_cast<Elys::OpenGLShader>(m_FlatColorShader)->Bind();
			std::dynamic_pointer_cast<Elys::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

			for (int y = 0; y < 20; y++)
			{
				for (int x = 0; x < 20; x++) {
					glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
					glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
					Elys::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
				}
			}

			auto textureShader = m_ShaderLibrary.Get("Texture");

			m_Texture->Bind(0);
			Elys::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
			m_ChernoLogoTexture->Bind(0);
			Elys::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

			// Triangle
			//Elys::Renderer::Submit(m_Shader, m_VertexArray);

			Elys::Renderer::EndScene();
		}

		virtual void OnImGuiRender(Elys::Timestep ts) override
		{
			ImGui::Begin("Settings");
			ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
			ImGui::End();
		}

		void OnEvent(Elys::Event& e) override
		{
			m_CameraController.OnEvent(e);
		}

	private:
		Elys::ShaderLibrary m_ShaderLibrary;
		Elys::Ref<Elys::Shader> m_Shader;
		Elys::Ref<Elys::VertexArray> m_VertexArray;

		Elys::Ref<Elys::Shader> m_FlatColorShader;
		Elys::Ref<Elys::VertexArray> m_SquareVA;

		Elys::Ref<Elys::Texture2D> m_Texture, m_ChernoLogoTexture;

		Elys::OrthographicCameraController m_CameraController;
		glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public Elys::Application
{
	public:
		Sandbox(Elys::ApplicationCommandLineArgs args)
			: Application("Elys Sandbox", args)
		{
			//PushLayer(new ExampleLayer());
			PushLayer(new Sandbox2D());
		}

		~Sandbox() {}
};

Elys::Application* Elys::CreateApplication(ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}
