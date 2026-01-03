#include "lspch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Lisa {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}