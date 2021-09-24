#pragma once

#include "Elys/Core/Core.h"
#include "Elys/Scene/Scene.h"
#include "Elys/Scene/Entity.h"

namespace Elys {

	class SceneHierarchyPanel
	{
		public:
			SceneHierarchyPanel() = default;
			SceneHierarchyPanel(const Ref<Scene>& context);

			void SetContext(const Ref<Scene>& context);

			void OnImGuiRender();

			Entity GetSelectedEntity() const { return m_SelectionContext; }
			void SetSelectedEntity(Entity entity);

		private:
			void DrawEntityNode(Entity entity);
			void DrawComponents(Entity entity);

		private:
			Ref<Scene> m_Context;
			Entity m_SelectionContext;
	};
}
