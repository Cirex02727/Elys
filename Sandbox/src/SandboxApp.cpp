#include <Elys.h>

#include "imgui/imgui.h"

class ExampleLayer : public Elys::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Elys::Input::IsKeyPressed(HZ_KEY_TAB))
			ELYS_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Elys::Event& event) override
	{
		if (event.GetEventType() == Elys::EventType::KeyPressed)
		{
			Elys::KeyPressedEvent& e = (Elys::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HZ_KEY_TAB)
				ELYS_TRACE("Tab key is pressed (event)!");
			ELYS_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Elys::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Elys::Application* Elys::CreateApplication()
{
	return new Sandbox();
}