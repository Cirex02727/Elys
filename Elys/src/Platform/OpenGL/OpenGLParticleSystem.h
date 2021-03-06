#pragma once

#include "Elys/Renderer/ParticleSystem.h"
#include "Elys/Renderer/Shader.h"

namespace Elys {

	class OpenGLParticleSystem : public ParticleSystem
	{
		public:
			OpenGLParticleSystem(uint32_t pollSize);

			virtual void OnUpdate(Timestep ts) override;
			virtual void OnRender(OrthographicCamera& camera) override;

			virtual void Emit(const ParticleProp& particleProps) override;

		protected:
			uint32_t m_PoolIndex = 999;

		private:
			struct Particle
			{
				glm::vec2 Position;
				glm::vec2 Velocity;
				glm::vec4 ColorBegin, ColorEnd;
				float Rotation = 0.0f;
				float SizeBegin, SizeEnd;

				float LifeTime = 1.0f;
				float LifeRemaining = 0.0f;

				bool Active = false;
			};

			std::vector<Particle> m_ParticlePool;
	};
}
