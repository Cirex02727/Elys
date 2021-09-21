#pragma once

#include <glm/glm.hpp>

namespace Elys {

	class ELYS_API Utils
	{
		public:
			static glm::vec4 HSVtoRGB(const glm::vec3& hsv);

			static float lerp(float a, float b, float t);
	};
}
