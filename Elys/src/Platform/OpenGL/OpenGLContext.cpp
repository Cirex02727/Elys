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

#ifdef ELYS_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		ELYS_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Elys requires at least OpenGL version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		ELYS_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}
