#include "lspch.h"
#include "Lisa/Renderer/GraphicsContext.h"

#include "Lisa/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Lisa {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    LS_CORE_ASSERT(false, "RendererAPI::None is not supported yet!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		LS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}