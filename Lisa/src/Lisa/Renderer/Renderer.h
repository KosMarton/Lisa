#pragma once

namespace Lisa {

	enum class RendererAPI
	{
		None = 0, OpenGL = 1
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; }
		inline static void SetAPI(RendererAPI rendererAPI) { s_RendererAPI = rendererAPI; }
	private:
		static RendererAPI s_RendererAPI;
	};

}