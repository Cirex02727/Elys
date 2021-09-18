#pragma once

#include "Elys.h"

class Sandbox2D : public Elys::Layer
{
	public:
		Sandbox2D();
		virtual ~Sandbox2D() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Elys::Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Elys::Event& e) override;

	private:
		Elys::OrthographicCameraController m_CameraController;

		// TEMP
		Elys::Ref<Elys::Shader> m_FlatColorShader;
		Elys::Ref<Elys::VertexArray> m_SquareVA;

		Elys::Ref<Elys::Texture2D> m_CheckerboardTexture;

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};
