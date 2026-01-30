#include <Lisa.h>
#include <Lisa/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Lisa {

	class Lizzy : public Application
	{
	public:
		Lizzy(ApplicationCommandLineArgs args)
			: Application("Lizzy", args)
		{
			PushLayer(new EditorLayer());
		}

		~Lizzy()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Lizzy(args);
	}

}