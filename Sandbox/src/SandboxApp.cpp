#include <Elys.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Elys::Layer
{
	public:
		ExampleLayer()
			: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
		{
			m_VertexArray.reset(Elys::VertexArray::Create());

			float vertices[3 * 7] = {
				-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
				 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
				 0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			};

			Elys::Ref<Elys::VertexBuffer> m_VertexBuffer;
			m_VertexBuffer.reset(Elys::VertexBuffer::Create(vertices, sizeof(vertices)));
			Elys::BufferLayout layout = {
				{ Elys::ShaderDataType::Float3, "a_Position" },
				{ Elys::ShaderDataType::Float4, "a_Color" },
			};

			m_VertexBuffer->SetLayout(layout);
			m_VertexArray->AddVertexBuffer(m_VertexBuffer);

			uint32_t indices[3] = { 0, 1, 2 };
			Elys::Ref<Elys::IndexBuffer> m_IndexBuffer;
			m_IndexBuffer.reset(Elys::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
			m_VertexArray->SetIndexBuffer(m_IndexBuffer);


			m_SquareVA.reset(Elys::VertexArray::Create());

			float squareVertices[5 * 4] = {
				-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
				 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
				 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
				-0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
			};

			Elys::Ref<Elys::VertexBuffer> squareVB;
			squareVB.reset(Elys::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
			squareVB->SetLayout({
				{ Elys::ShaderDataType::Float3, "a_Position" },
				{ Elys::ShaderDataType::Float2, "a_TexCoord" },
			});
			m_SquareVA->AddVertexBuffer(squareVB);

			uint32_t sqareIndices[6] = { 0, 1, 2, 2, 3, 0 };
			Elys::Ref<Elys::IndexBuffer> squareIB;
			squareIB.reset(Elys::IndexBuffer::Create(sqareIndices, sizeof(sqareIndices) / sizeof(uint32_t)));
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

			m_Shader.reset(Elys::Shader::Create(vertexSrc, fragmentSrc));

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

			m_FlatColorShader.reset(Elys::Shader::Create(flatColorVertexSrc, flatColorFragmentSrc));

			m_TextureShader.reset(Elys::Shader::Create("assets/shaders/Texture.glsl"));

			m_Texture = Elys::Texture2D::Create("assets/textures/Checkerboard.png");
			m_ChernoLogoTexture = Elys::Texture2D::Create("assets/textures/ChernoLogo.png");

			std::dynamic_pointer_cast<Elys::OpenGLShader>(m_TextureShader)->Bind();
			std::dynamic_pointer_cast<Elys::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);
		}

		void OnUpdate(Elys::Timestep ts) override
		{
			if (Elys::Input::IsKeyPressed(ELYS_KEY_LEFT))
				m_CameraPosition.x -= m_CameraMoveSpeed * ts;
			else if (Elys::Input::IsKeyPressed(ELYS_KEY_RIGHT))
				m_CameraPosition.x += m_CameraMoveSpeed * ts;

			if (Elys::Input::IsKeyPressed(ELYS_KEY_UP))
				m_CameraPosition.y += m_CameraMoveSpeed * ts;
			else if (Elys::Input::IsKeyPressed(ELYS_KEY_DOWN))
				m_CameraPosition.y -= m_CameraMoveSpeed * ts;

			if (Elys::Input::IsKeyPressed(ELYS_KEY_A))
				m_CameraRotation += m_CameraRotationSpeed * ts;
			else if (Elys::Input::IsKeyPressed(ELYS_KEY_D))
				m_CameraRotation -= m_CameraRotationSpeed * ts;


			Elys::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			Elys::RenderCommand::Clear();

			m_Camera.SetPosition(m_CameraPosition);
			m_Camera.SetRotation(m_CameraRotation);

			Elys::Renderer::BeginScene(m_Camera);

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

			m_Texture->Bind(0);
			Elys::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
			m_ChernoLogoTexture->Bind(0);
			Elys::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

			// Triangle
			//Elys::Renderer::Submit(m_Shader, m_VertexArray);

			Elys::Renderer::EndScene();
		}

		virtual void OnImGuiRender() override
		{
			ImGui::Begin("Settings");
			ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
			ImGui::End();
		}

		void OnEvent(Elys::Event& event) override
		{

		}

	private:
		Elys::Ref<Elys::Shader> m_Shader;
		Elys::Ref<Elys::VertexArray> m_VertexArray;

		Elys::Ref<Elys::Shader> m_FlatColorShader, m_TextureShader;
		Elys::Ref<Elys::VertexArray> m_SquareVA;

		Elys::Ref<Elys::Texture2D> m_Texture, m_ChernoLogoTexture;

		Elys::OrthographicCamera m_Camera;
		glm::vec3 m_CameraPosition;
		float m_CameraMoveSpeed = 5.0f;

		float m_CameraRotation = 0.0f;
		float m_CameraRotationSpeed = 180.0f;

		glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public Elys::Application
{
	public:
		Sandbox()
		{
			PushLayer(new ExampleLayer());
		}

		~Sandbox() {}
};

Elys::Application* Elys::CreateApplication()
{
	return new Sandbox();
}