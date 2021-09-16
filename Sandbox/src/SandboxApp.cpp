#include "Elys.h"

class ExampleLayer : public Elys::Layer {
	public:
		ExampleLayer() 
			: Layer("Example") {}

		void OnUpdate() override {
			ELYS_INFO("ExampleLayer::Update");
		}

		void OnEvent(Elys::Event& event) override {
			ELYS_TRACE("{0}", event);
		}
};

class Sandbox : public Elys::Application {

	public:
		Sandbox() {
			PushLayer(new ExampleLayer());
		}

		~Sandbox() {

		}
};

Elys::Application* Elys::CreateApplication() {
	return new Sandbox();
}