#include "lspch.h"
#include "Lisa/Renderer/Texture.h"

#include "Lisa/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Lisa {

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    LS_CORE_ASSERT(false, "RendererAPI::None is not supported yet!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(width, height);
		}

		LS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    LS_CORE_ASSERT(false, "RendererAPI::None is not supported yet!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(path);
		}

		LS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}