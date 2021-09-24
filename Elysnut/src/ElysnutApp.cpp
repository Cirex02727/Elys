#include <Elys.h>
#include <Elys/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Elys {

	class Elysnut : public Application
	{
		public:
			Elysnut(ApplicationCommandLineArgs args)
				: Application("Elysnut", args)
			{
				PushLayer(new EditorLayer());
			}

			~Elysnut() {}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Elysnut(args);
	}
}
