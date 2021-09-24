#pragma once

#include "Elys/Core/Core.h"
#include "Elys/Core/Application.h"

#ifdef ELYS_PLATFORM_WINDOWS

extern Elys::Application* Elys::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Elys::Log::Init();
	Elys::Random::Init();

	ELYS_PROFILE_BEGIN_SESSION("Startup", "ElysProfile-Startup.json");
	auto app = Elys::CreateApplication({ argc, argv });
	ELYS_PROFILE_END_SESSION();

	ELYS_PROFILE_BEGIN_SESSION("Runtime", "ElysProfile-Runtime.json");
	app->Run();
	ELYS_PROFILE_END_SESSION();

	ELYS_PROFILE_BEGIN_SESSION("Shutdown", "ElysProfile-Shutdown.json");
	delete app;
	ELYS_PROFILE_END_SESSION();
}

#endif
