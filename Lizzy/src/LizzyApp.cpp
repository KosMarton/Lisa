#include <Lisa.h>
#include <Lisa/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Lisa {

	class Lizzy : public Application
	{
	public:
		Lizzy(const ApplicationSpecification& specification)
			: Application(specification)
		{
			PushLayer(new EditorLayer());
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "Lizzy";
		spec.CommandLineArgs = args;

		return new Lizzy(spec);
	}

}