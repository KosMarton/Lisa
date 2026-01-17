#include "lspch.h"
#include "Lisa/Scene/Entity.h"

namespace Lisa {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}