#include "elyspch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Elys {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
