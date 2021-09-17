#pragma once

#include "Core.h"

#include "Window.h"
#include "Elys/LayerStack.h"
#include "Elys/Events/Event.h"
#include "Elys/Events/ApplicationEvent.h"

#include "Elys/ImGui/ImGuiLayer.h"

namespace Elys {

	class Elys_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}