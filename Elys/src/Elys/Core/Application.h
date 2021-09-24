#pragma once

#include "Elys/Core/Core.h"

#include "Elys/Core/Window.h"
#include "Elys/Core/LayerStack.h"
#include "Elys/Events/Event.h"
#include "Elys/Events/ApplicationEvent.h"

#include "Elys/Core/Timestep.h"

#include "Elys/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Elys {

	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			ELYS_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};

	class ELYS_API Application
	{
		public:
			Application(const std::string& name = "Elys App", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
			virtual ~Application();

			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* layer);

			Window& GetWindow() { return *m_Window; }

			void Close();

			ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

			static Application& Get() { return *s_Instance; }

			ApplicationCommandLineArgs GetCommandLineArgs() const { return m_CommandLineArgs; }

		private:
			void Run();

			bool OnWindowClose(WindowCloseEvent& e);
			bool OnWindowResize(WindowResizeEvent& e);

		private:
			ApplicationCommandLineArgs m_CommandLineArgs;

			Scope<Window> m_Window;
			ImGuiLayer* m_ImGuiLayer;
			bool m_Running = true;
			bool m_Minimized = false;
			LayerStack m_LayerStack;
			float m_LastFrameTime = 0.0f;

		private:
			static Application* s_Instance;
			friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);
}
