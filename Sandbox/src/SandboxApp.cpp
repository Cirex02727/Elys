#include "Elys.h"

class Sandbox : public Elys::Application {

	public:
		Sandbox() {

		}

		~Sandbox() {

		}
};

Elys::Application* Elys::CreateApplication() {
	return new Sandbox();
}