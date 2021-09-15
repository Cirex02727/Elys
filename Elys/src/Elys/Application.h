#pragma once

#include "Core.h"

namespace Elys {

	class ELYS_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	// To be defined in Client
	Application* CreateApplication();
}
