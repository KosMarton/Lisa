#include <Lisa.h>

class ExampleLayer : public Lisa::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		LS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Lisa::Event& event) override
	{
		LS_TRACE("{0}", event);
	}

};

class Sandbox : public Lisa::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Lisa::ImGuiLayer());
	}

	~Sandbox()
	{

	}
	
};

Lisa::Application* Lisa::CreateApplication()
{
	return new Sandbox();
}