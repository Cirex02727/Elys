#include "Sandbox2D.h"

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true) {}

void Sandbox2D::OnAttach()
{
	ELYS_PROFILE_FUNCTION();

	m_CheckerboardTexture = Elys::Texture2D::Create("assets/textures/Checkerboard.png");
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
	{
		ELYS_PROFILE_SCOPE("Pre-Renderer");
		Elys::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Elys::RenderCommand::Clear();
	}

	{
		ELYS_PROFILE_SCOPE("Renderer Draw");
		Elys::Renderer2D::BeginScene(m_CameraController.GetCamera());

		Elys::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, glm::vec2(0.8f), glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Elys::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Elys::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, glm::vec2(10.0f), m_CheckerboardTexture, glm::vec2(10.0f));

		Elys::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	ELYS_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Elys::Event& e)
{
	m_CameraController.OnEvent(e);
}