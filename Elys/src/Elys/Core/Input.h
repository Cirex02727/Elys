#pragma once

#include "Elys/Core/Core.h"
#include "Elys/Core/KeyCodes.h"
#include "Elys/Core/MouseCodes.h"

namespace Elys {

	class ELYS_API Input
	{
		public:
			static bool IsKeyPressed(KeyCode key);

			static bool IsMouseButtonPressed(MouseCode button);
			static std::pair<float, float> GetMousePosition();
			static float GetMouseX();
			static float GetMouseY();
	};

}