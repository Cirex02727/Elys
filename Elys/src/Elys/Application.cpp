#include "elyspch.h"

#include "Application.h"

#include "Elys/Events/ApplicationEvent.h"
#include "Elys/Log.h"

namespace Elys {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		ELYS_TRACE(e);

		while (true);
	}
}