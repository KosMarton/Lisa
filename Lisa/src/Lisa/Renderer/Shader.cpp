#include "lspch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Lisa {

	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    LS_CORE_ASSERT(false, "RendererAPI::None is not supported yet!"); return nullptr;
			case RendererAPI::API::OpenGL:  return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		LS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}