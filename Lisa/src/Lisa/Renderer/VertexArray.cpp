#include "lspch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Lisa {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    LS_CORE_ASSERT(false, "RendererAPI::None is not supported yet!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		LS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}