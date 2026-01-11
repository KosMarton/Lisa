#include "lspch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

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

	#ifdef LS_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		LS_CORE_INFO("OpenGL version: {0}.{1}", versionMajor, versionMinor);
		LS_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Lisa requires at least OpenGL version 4.5!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		LS_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}