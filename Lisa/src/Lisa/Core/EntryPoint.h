#pragma once
#include "Lisa/Core/Base.h"
#include "Lisa/Core/Application.h"

#ifdef LS_PLATFORM_WINDOWS

extern Lisa::Application* Lisa::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Lisa::Log::Init();

	LS_PROFILE_BEGIN_SESSION("Startup", "LisaProfile-Startup.json");
	auto app = Lisa::CreateApplication({ argc, argv });
	LS_PROFILE_END_SESSION();

	LS_PROFILE_BEGIN_SESSION("Runtime", "LisaProfile-Runtime.json");
	app->Run();
	LS_PROFILE_END_SESSION();

	LS_PROFILE_BEGIN_SESSION("Shutdown", "LisaProfile-Shutdown.json");
	delete app;
	LS_PROFILE_END_SESSION();
}

#endif