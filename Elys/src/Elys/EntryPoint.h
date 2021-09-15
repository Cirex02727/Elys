#pragma once

#ifdef ELYS_PLATFORM_WINDOWS

extern Elys::Application* Elys::CreateApplication();

int main(int argc, char** argv) {
	auto app = Elys::CreateApplication();
	app->Run();
	delete app;
}

#endif // ELYS_PLATFORM_WINDOWS
