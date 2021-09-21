#pragma once

#include <random>

namespace Elys {

	class ELYS_API Random
	{
		public:
			static void Init();

			static float Float();
			static float Float(float max);
			static float Float(float min, float max);

		private:
			static std::mt19937 s_RandomEngine;
			static std::uniform_int_distribution<std::mt19937::result_type> s_Distribution;
	};
}
