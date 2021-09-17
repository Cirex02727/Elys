#include "elyspch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Elys {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ELYS_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ELYS_CORE_ASSERT(status, "Failed to initialize Glad!");

		ELYS_CORE_INFO("OpenGL Info:");
		ELYS_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		ELYS_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		ELYS_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
