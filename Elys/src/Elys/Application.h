#pragma once

#include "Core.h"

#include "Window.h"
#include "Elys/LayerStack.h"
#include "Elys/Events/Event.h"
#include "Elys/Events/ApplicationEvent.h"

#include "Elys/ImGui/ImGuiLayer.h"

#include "Elys/Renderer/Shader.h"
#include <Elys/Renderer/Buffer.h>
#include <Elys/Renderer/VertexArray.h>

#include "Elys/Core/Timestep.h"

#include "Elys/Renderer/OrthographicCamera.h"

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

		private:
			std::unique_ptr<Window> m_Window;
			ImGuiLayer* m_ImGuiLayer;
			bool m_Running = true;
			LayerStack m_LayerStack;
			float m_LastFrameTime = 0.0f;

		private:
			static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}