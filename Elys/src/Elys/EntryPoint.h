#pragma once

#ifdef ELYS_PLATFORM_WINDOWS

extern Elys::Application* Elys::CreateApplication();

int main(int argc, char** argv) {

	Elys::Log::Init();
	ELYS_CORE_WARN("Initialize Log!");

	int a = 5;
	ELYS_INFO("Hello Var={0}!", a);

	auto app = Elys::CreateApplication();
	app->Run();
	delete app;
}

#endif // ELYS_PLATFORM_WINDOWS
