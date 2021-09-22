#include <Elys.h>
#include <Elys/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Elys {

	class ElysEditor : public Application
	{
		public:
			ElysEditor()
				: Application("Elys Editor")
			{
				PushLayer(new EditorLayer());
			}

			~ElysEditor() {}
	};

	Application* CreateApplication()
	{
		return new ElysEditor();
	}
}
