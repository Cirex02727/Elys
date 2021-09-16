#pragma once

#ifdef ELYS_PLATFORM_WINDOWS

extern Elys::Application* Elys::CreateApplication();

int main(int argc, char** argv) {

	Elys::Log::Init();
	ELYS_CORE_WARN("Initialize Log!");

	auto app = Elys::CreateApplication();
	app->Run();
	delete app;
}

#endif // ELYS_PLATFORM_WINDOWS
