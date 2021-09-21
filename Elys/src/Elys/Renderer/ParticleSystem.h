#pragma once

#include "Elys/Core/Timestep.h"
#include "Elys/Renderer/OrthographicCamera.h"

namespace Elys {

	struct ParticleProp
	{
		glm::vec2 Position;
		glm::vec2 Velocity, VelocityVariation;
		glm::vec4 ColorBegin, ColorEnd;
		float SizeBegin, SizeEnd, SizeVariation;
		float LifeTime = 1.0f;
	};

	class ParticleSystem
	{
		public:
			virtual void OnUpdate(Timestep ts) = 0;
			virtual void OnRender(OrthographicCamera& camera) = 0;

			virtual void Emit(const ParticleProp& particleProps) = 0;

			static Ref<ParticleSystem> Create(uint32_t pollSize);

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
