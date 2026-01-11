#pragma once

#include "Lisa/Core/Layer.h"

#include "Lisa/Events/ApplicationEvent.h"
#include "Lisa/Events/KeyEvent.h"
#include "Lisa/Events/MouseEvent.h"

namespace Lisa {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}