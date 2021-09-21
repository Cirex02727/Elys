#pragma once

#include "Elys.h"

#include <vector>

#include <Platform/OpenGL/OpenGLParticleSystem.h>

class Sandbox2D : public Elys::Layer
{
	public:
		Sandbox2D();
		virtual ~Sandbox2D() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Elys::Timestep ts) override;
		virtual void OnImGuiRender(Elys::Timestep ts) override;
		void OnEvent(Elys::Event& e) override;

	private:
		Elys::OrthographicCameraController m_CameraController;

		// TEMP
		Elys::Ref<Elys::Shader> m_FlatColorShader;
		Elys::Ref<Elys::VertexArray> m_SquareVA;

		Elys::Ref<Elys::Texture2D> m_CheckerboardTexture;

		std::vector<Elys::QuadVertex> m_Grid;

		Elys::ParticleProp m_Particle;
		Elys::Ref<Elys::ParticleSystem> m_ParticleSystem;

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};
