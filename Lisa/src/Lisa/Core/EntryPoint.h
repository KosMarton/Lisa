#pragma once

#ifdef LS_PLATFORM_WINDOWS

extern Lisa::Application* Lisa::CreateApplication();

int main(int argc, char** argv)
{
	Lisa::Log::Init();
	LS_CORE_WARN("Initialized Log!");
	int a = 5;
	LS_INFO("Hello! Var={0}", a);

	auto app = Lisa::CreateApplication();
	app->Run();
	delete app;
}

#endif