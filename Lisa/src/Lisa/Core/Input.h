#pragma once

#include "Lisa/Core/Base.h"
#include "Lisa/Core/KeyCodes.h"
#include "Lisa/Core/MouseCodes.h"

namespace Lisa {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}