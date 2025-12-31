#pragma once

#include "Lisa/Layer.h"

#include "Lisa/Events/ApplicationEvent.h"
#include "Lisa/Events/KeyEvent.h"
#include "Lisa/Events/MouseEvent.h"

namespace Lisa {

	class LISA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}