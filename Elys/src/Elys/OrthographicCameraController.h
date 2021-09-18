#pragma once

#include "Elys/Renderer/OrthographicCamera.h"
#include "Elys/Core/Timestep.h"

#include "Elys/Events/ApplicationEvent.h"
#include "Elys/Events/MouseEvent.h"

namespace Elys {

	class OrthographicCameraController
	{
		public:
			OrthographicCameraController(float aspectRatio, bool rotation = false);

			void OnUpdate(Timestep ts);
			void OnEvent(Event& e);

			OrthographicCamera& GetCamera() { return m_Camera; }
			const OrthographicCamera& GetCamera() const { return m_Camera; }

			float GetZoomLevel() const { return m_ZoomLevel; }
			void SetZoomLevel(float level) { m_ZoomLevel = level; }

		private:
			bool OnMouseScrolled(MouseScrolledEvent& e);
			bool OnWindowResized(WindowResizeEvent& e);

		private:
			float m_AspectRatio;
			float m_ZoomLevel = 1.0f;
			OrthographicCamera m_Camera;

			bool m_Rotation = false;

			glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
			float m_CameraRotation = 0.0f;
			float m_CameraTranslationSpeed = 1.0f, m_CameraRotationSpeed = 180.0f;
	};
}