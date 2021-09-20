#pragma once

#ifdef ELYS_PLATFORM_WINDOWS

extern Elys::Application* Elys::CreateApplication();

int main(int argc, char** argv)
{
	Elys::Log::Init();

	ELYS_PROFILE_BEGIN_SESSION("Startup", "ElysProfile-Startup.json");
	auto app = Elys::CreateApplication();
	ELYS_PROFILE_END_SESSION();

	ELYS_PROFILE_BEGIN_SESSION("Startup", "ElysProfile-Runtime.json");
	app->Run();
	ELYS_PROFILE_END_SESSION();

	ELYS_PROFILE_BEGIN_SESSION("Startup", "ElysProfile-Shutdown.json");
	delete app;
	ELYS_PROFILE_END_SESSION();
}

#endif