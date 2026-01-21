#pragma once

#include "Lisa/Core/Base.h"
#include "Lisa/Core/Log.h"
#include "Lisa/Scene/Scene.h"
#include "Lisa/Scene/Entity.h"

namespace Lisa {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}