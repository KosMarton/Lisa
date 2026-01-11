#include "lspch.h"
#include "Lisa/Renderer/RenderCommand.h"

namespace Lisa {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}