#include "Elys.h"

#include "Elys/Events/KeyEvent.h"

class ExampleLayer : public Elys::Layer {
	public:
		ExampleLayer() 
			: Layer("Example") {}

		void OnUpdate() override {
			
			if (Elys::Input::IsKeyPressed(ELYS_KEY_TAB))
				ELYS_TRACE("Tabkey is pressed (poll)!");
		}

		void OnEvent(Elys::Event& event) override {
			if (event.GetEventType() == Elys::EventType::KeyPressed) {
				Elys::KeyPressedEvent& e = (Elys::KeyPressedEvent&)event;
				if(e.GetKeyCode() == ELYS_KEY_TAB)
					ELYS_TRACE("Tabkey is pressed (event)!");

				ELYS_TRACE("{0}", (char)e.GetKeyCode());
			}
		}
};

class Sandbox : public Elys::Application {

	public:
		Sandbox() {
			PushLayer(new ExampleLayer());
			PushOverlay(new Elys::ImGuiLayer());
		}

		~Sandbox() {

		}
};

Elys::Application* Elys::CreateApplication() {
	return new Sandbox();
}