#pragma once

#include "Elys/Core/Core.h"
#include "Elys/Core/Timestep.h"
#include "Elys/Events/Event.h"

namespace Elys {

	class ELYS_API Layer
	{
		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer();

			virtual void OnAttach() {}
			virtual void OnDetach() {}
			virtual void OnUpdate(Timestep ts) {}
			virtual void OnImGuiRender(Timestep ts) {}
			virtual void OnEvent(Event& e) {}

			const std::string& GetName() const { return m_DebugName; }

		protected:
			std::string m_DebugName;
	};

}
