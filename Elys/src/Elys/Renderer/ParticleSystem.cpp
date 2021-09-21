#include "elyspch.h"
#include "ParticleSystem.h"

#include "Elys/Utils/Random.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLParticleSystem.h"

#include <numbers>

namespace Elys {

	Ref<ParticleSystem> ParticleSystem::Create(uint32_t pollSize)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				ELYS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
				return nullptr;

			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLParticleSystem>(pollSize);
		}

		ELYS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
