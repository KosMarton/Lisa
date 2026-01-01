#pragma once

#include "Core.h"

#include "Window.h"
#include "Lisa/LayerStack.h"
#include "Lisa/Events/Event.h"
#include "Lisa/Events/ApplicationEvent.h"

#include "Lisa/ImGui/ImGuiLayer.h"

#include "Lisa/Renderer/Shader.h"

namespace Lisa {

	class LISA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

