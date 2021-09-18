#include <Elys.h>

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>

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

			std::shared_ptr<Elys::VertexBuffer> m_VertexBuffer;
			m_VertexBuffer.reset(Elys::VertexBuffer::Create(vertices, sizeof(vertices)));
			Elys::BufferLayout layout = {
				{ Elys::ShaderDataType::Float3, "a_Position" },
				{ Elys::ShaderDataType::Float4, "a_Color" },
			};

			m_VertexBuffer->SetLayout(layout);
			m_VertexArray->AddVertexBuffer(m_VertexBuffer);

			uint32_t indices[3] = { 0, 1, 2 };
			std::shared_ptr<Elys::IndexBuffer> m_IndexBuffer;
			m_IndexBuffer.reset(Elys::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
			m_VertexArray->SetIndexBuffer(m_IndexBuffer);


			m_SquareVA.reset(Elys::VertexArray::Create());

			float squareVertices[3 * 7] = {
				-0.5f, -0.5f, 0.0f,
				 0.5f, -0.5f, 0.0f,
				 0.5f,  0.5f, 0.0f,
				-0.5f,  0.5f, 0.0f
			};

			std::shared_ptr<Elys::VertexBuffer> squareVB;
			squareVB.reset(Elys::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
			squareVB->SetLayout({
				{ Elys::ShaderDataType::Float3, "a_Position" }
			});
			m_SquareVA->AddVertexBuffer(squareVB);

			uint32_t sqareIndices[6] = { 0, 1, 2, 2, 3, 0 };
			std::shared_ptr<Elys::IndexBuffer> squareIB;
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

			m_Shader.reset(new Elys::Shader(vertexSrc, fragmentSrc));


			std::string blueVertexSrc = R"(
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

			std::string blueFragmentSrc = R"(
				#version 330 core
			
				layout(location = 0) out vec4 color;
			
				in vec3 v_Position;
			
				void main()
				{
					color = vec4(0.2, 0.3, 0.8, 1.0);
				}
			)";

			m_BlueShader.reset(new Elys::Shader(blueVertexSrc, blueFragmentSrc));
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

			for (int y = 0; y < 20; y++)
			{
				for (int x = 0; x < 20; x++) {
					glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
					glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
					Elys::Renderer::Submit(m_BlueShader, m_SquareVA, transform);
				}
			}

			Elys::Renderer::Submit(m_Shader, m_VertexArray);

			Elys::Renderer::EndScene();
		}

		virtual void OnImGuiRender() override
		{

		}

		void OnEvent(Elys::Event& event) override
		{

		}

	private:
		std::shared_ptr<Elys::Shader> m_Shader;
		std::shared_ptr<Elys::VertexArray> m_VertexArray;

		std::shared_ptr<Elys::Shader> m_BlueShader;
		std::shared_ptr<Elys::VertexArray> m_SquareVA;

		Elys::OrthographicCamera m_Camera;
		glm::vec3 m_CameraPosition;
		float m_CameraMoveSpeed = 5.0f;

		float m_CameraRotation = 0.0f;
		float m_CameraRotationSpeed = 180.0f;
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