#include "lspch.h"
#include "Lisa/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Lisa {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
			case RendererAPI::API::None:    LS_CORE_ASSERT(false, "RendererAPI::None is not supported yet!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
		}

		LS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}