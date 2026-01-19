#pragma once

#include <glm/glm.hpp>
#include "Lisa/Core/KeyCodes.h"
#include "Lisa/Core/MouseCodes.h"

namespace Lisa {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}