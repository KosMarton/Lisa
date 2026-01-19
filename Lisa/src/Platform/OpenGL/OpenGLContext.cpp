#include "lspch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Lisa {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		LS_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		LS_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LS_CORE_ASSERT(status, "Failed to initialize Glad!");

		LS_CORE_INFO("OpenGL Info:");
		LS_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		LS_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		LS_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

		LS_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Lisa requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		LS_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}