#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include "Elys/Utils/Utils.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static const uint32_t s_MaWidth = 24;
static const char* s_MapTiles =
	"WWWWWWWWWWWWWWWWWWWWWWWW"
	"WWWWWWWWWDDDDDDWWWWWWWWW"
	"WWWWWWWDDDDDDDDDDWWWWWWW"
	"WWWWWWDDDDDDDDDDDDWWWWWW"
	"WWWWWDDDDDDDDDDDCDDWWWWW"
	"WWWWDDDWWWDDDDDDDDDDWWWW"
	"WWWDDDDWWWDDDDDDDDDDDWWW"
	"WWWWDDDDDDDDDDDDDDDDWWWW"
	"WWWWWDDDDDDDDDDDDDDWWWWW"
	"WWWWWWDDDDDDDDDDDDWWWWWW"
	"WWWWWWWDDDDDDDDDDWWWWWWW"
	"WWWWWWWWWDDDDDDWWWWWWWWW"
	"WWWWWWWWWWWWWWWWWWWWWWWW";


Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f }) {}

void Sandbox2D::OnAttach()
{
	ELYS_PROFILE_FUNCTION();

	m_CheckerboardTexture = Elys::Texture2D::Create("assets/textures/Checkerboard.png");
	m_SpriteSheet = Elys::Texture2D::Create("assets/spriteSheets/RPGpack_sheet_2X.png");
	
	m_TextureBarrel = Elys::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 9, 2 }, { 128, 128 }, { 1, 1 });

	s_TextureMap['D'] = Elys::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 6, 11 }, { 128, 128 });
	s_TextureMap['W'] = Elys::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 11, 11 }, { 128, 128 });

	m_MapWidth = s_MaWidth;
	m_MapHeight = strlen(s_MapTiles) / m_MapWidth;

	m_ParticleSystem = Elys::OpenGLParticleSystem::Create(10000);

	m_Particle.Position = { 0.0f, 0.75f };
	m_Particle.Velocity = { -0.5f, 1.0f }, m_Particle.VelocityVariation = { -1.0f, -1.0f };
	m_Particle.SizeBegin = 0.2f, m_Particle.SizeEnd = 0.0f, m_Particle.SizeVariation = 0.1f;
	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 0 / 255.0f, 0 / 255.0f, 255 / 255.0f , 1.0f };
	m_Particle.LifeTime = 2.0f;

	{
		ELYS_PROFILE_SCOPE("Init Grid");

		const glm::vec4 poses[4] = {
			{ -0.5f, -0.5f, 0.0f, 1.0f },
			{ 0.5f, -0.5f, 0.0f, 1.0f },
			{ 0.5f,  0.5f, 0.0f, 1.0f },
			{ -0.5f,  0.5f, 0.0f, 1.0f }
		};
		const glm::vec2 texCords[4] = {
			{ 0.0f, 0.0f },
			{ 1.0f, 0.0f },
			{ 1.0f, 1.0f },
			{ 0.0f, 1.0f }
		};

		float Size = 15.0f, Steps = 0.35f;
		for (float y = -Size; y < Size; y += Steps)
		{
			for (float x = -Size; x < Size; x += Steps)
			{
				glm::vec4 color = { (x + (Size / 2)) / Size, 0.4f, (y + (Size / 2)) / Size, 0.7f };

				glm::mat4 transform = glm::translate(glm::mat4(1.0f), { x, y, -0.9f })
					* glm::scale(glm::mat4(1.0f), { 0.45f, 0.45f, 1.0f });

				for (int i = 0; i < 4; i++) {
					Elys::QuadVertex quad = Elys::QuadVertex();
					quad.Position = transform * poses[i];
					quad.Color = color;
					quad.TexCoord = texCords[i];
					quad.TexIndex = 0.0f;
					quad.TilingFactor = glm::vec2(1.0f);

					m_Grid.push_back(quad);
				}
			}
		}
	}

	m_CameraController.SetZoomLevel(4.0f);
}

void Sandbox2D::OnDetach()
{
	ELYS_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Elys::Timestep ts)
{
	ELYS_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	//Render
	Elys::Renderer2D::ResetStats();
	{
		ELYS_PROFILE_SCOPE("Pre-Renderer");
		Elys::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Elys::RenderCommand::Clear();
	}

	for(int i = 0; i < 5; i++)
		m_ParticleSystem->Emit(m_Particle);

	{
		static float rotation = 0.0f;
		rotation += ts * 20.0f;

		ELYS_PROFILE_SCOPE("Renderer Draw");
		Elys::Renderer2D::BeginScene(m_CameraController.GetCamera());

		Elys::Renderer2D::DrawRotatedQuad({ 1.5f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Elys::Renderer2D::DrawQuad({ -1.0f, -1.5f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Elys::Renderer2D::DrawQuad({ 0.5f, -1.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Elys::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.99f }, { 30.0f, 30.0f }, m_CheckerboardTexture, glm::vec2(10.0f));
		Elys::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, glm::vec2(20.0f));

		Elys::Renderer2D::EndScene();


		{
			ELYS_PROFILE_SCOPE("Renderer Grid");
			Elys::Renderer2D::BeginScene(m_CameraController.GetCamera());

			for (size_t i = 0; i < m_Grid.size(); i += 4)
			{
				Elys::QuadVertex* quads[] = {
					&m_Grid[i], &m_Grid[i + (unsigned long long)1], &m_Grid[i + (unsigned long long)2], &m_Grid[i + (unsigned long long)3]
				};

				Elys::Renderer2D::DrawQuad(*quads);
			}

			Elys::Renderer2D::EndScene();
		}
	}

	m_ParticleSystem->OnUpdate(ts);
	m_ParticleSystem->OnRender(m_CameraController.GetCamera());

	Elys::Renderer2D::BeginScene(m_CameraController.GetCamera());

	for (uint32_t y = 0; y < m_MapHeight; y++)
	{
		for (uint32_t x = 0; x < m_MapWidth; x++)
		{
			char tileType = s_MapTiles[x + y * m_MapWidth];
			Elys::Ref<Elys::SubTexture2D> texture;
			if (s_TextureMap.find(tileType) != s_TextureMap.end())
				texture = s_TextureMap[tileType];
			else
				texture = m_TextureBarrel;

			Elys::Renderer2D::DrawQuad({ x - m_MapWidth / 2.0f, m_MapHeight / 2.0f - y, -0.5f }, { 1.0f, 1.0f }, texture);
		}
	}

	
	//Elys::Renderer2D::DrawQuad({ 0.5f, 0.0f, 0.5f }, glm::vec2(1.0f), m_TextureBarrel);
	//Elys::Renderer2D::DrawQuad({ -0.5f, 0.0f, 0.5f }, { 1.0f, 2.0f }, m_TextureTree);

	Elys::Renderer2D::EndScene();
}

float fpsRetard = 0.1f, currRetard = 0.0f, prevFps = 0.0f;
void Sandbox2D::OnImGuiRender(Elys::Timestep ts)
{
	ELYS_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

	if (currRetard < fpsRetard) {
		currRetard += ts.GetSeconds();
	}
	else {
		currRetard = 0.0f;
		prevFps = 1 / ts.GetSeconds();
	}

	ImGui::Text("Fps: %.5fms (%f fps)", ts.GetSeconds(), prevFps);

	ImGui::Spacing();

	auto stats = Elys::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::Spacing();

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

	ImGui::End();
}

void Sandbox2D::OnEvent(Elys::Event& e)
{
	m_CameraController.OnEvent(e);
}