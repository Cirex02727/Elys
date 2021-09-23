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
		ELYS_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ELYS_CORE_ASSERT(status, "Failed to initialize Glad!");

		ELYS_CORE_INFO("OpenGL Info:");
		ELYS_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		ELYS_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		ELYS_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		ELYS_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		ELYS_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}
