#pragma once

#include <glm/glm.hpp>

#include "Elys/Core/KeyCodes.h"
#include "Elys/Core/MouseCodes.h"

namespace Elys {

	class ELYS_API Input
	{
		public:
			static bool IsKeyPressed(KeyCode key);

			static bool IsMouseButtonPressed(MouseCode button);
			static glm::vec2 GetMousePosition();
			static float GetMouseX();
			static float GetMouseY();
	};

}
