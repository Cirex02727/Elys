#include "elyspch.h"
#include "Elys/Renderer/GraphicsContext.h"

#include "Elys/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Elys {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:   ELYS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		ELYS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
