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
		if (Lisa::Input::IsKeyPressed(LS_KEY_TAB))
			LS_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Lisa::Event& event) override
	{
		if (event.GetEventType() == Lisa::EventType::KeyPressed)
		{
			Lisa::KeyPressedEvent& e = (Lisa::KeyPressedEvent&)event;
			if (e.GetKeyCode() == LS_KEY_TAB)
				LS_TRACE("Tab key is pressed (event)!");
			LS_TRACE("{0}", (char)e.GetKeyCode());
		}
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