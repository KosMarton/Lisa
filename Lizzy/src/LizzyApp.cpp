#include <Lisa.h>
#include <Lisa/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Lisa {

	class Lizzy : public Application
	{
	public:
		Lizzy()
			: Application("Lizzy")
		{
			PushLayer(new EditorLayer());
		}

		~Lizzy()
		{
		}
	};

	Application* CreateApplication()
	{
		return new Lizzy();
	}

}