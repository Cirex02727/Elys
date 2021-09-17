#pragma once

#include "Elys/Layer.h"

#include "Elys/Events/ApplicationEvent.h"
#include "Elys/Events/KeyEvent.h"
#include "Elys/Events/MouseEvent.h"

namespace Elys {

	class Elys_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}