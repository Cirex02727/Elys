#pragma once

#include "Elys/Core/Layer.h"

#include "Elys/Events/ApplicationEvent.h"
#include "Elys/Events/KeyEvent.h"
#include "Elys/Events/MouseEvent.h"

namespace Elys {

	class ELYS_API ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer();
			~ImGuiLayer() = default;

			virtual void OnAttach() override;
			virtual void OnDetach() override;

			virtual void OnEvent(Event& e) override;

			void Begin();
			void End();

			void BlockEvents(bool block) { m_BlockEvents = block; }

			void SetDarkThemeColors();

		private:
			bool m_BlockEvents = true;
	};

}
