#include <Lisa.h>
#include <Lisa/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Lisa::Application
{
public:
	Sandbox(Lisa::ApplicationCommandLineArgs args)
		: Application("Sandbox", args)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Lisa::Application* Lisa::CreateApplication(Lisa::ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}