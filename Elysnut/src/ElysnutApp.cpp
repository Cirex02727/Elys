#include <Elys.h>
#include <Elys/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Elys {

	class Elysnut : public Application
	{
		public:
			Elysnut()
				: Application("Elysnut")
			{
				PushLayer(new EditorLayer());
			}

			~Elysnut() {}
	};

	Application* CreateApplication()
	{
		return new Elysnut();
	}
}
