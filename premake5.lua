workspace "Lisa"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Lisa/vendor/GLFW/include"
IncludeDir["Glad"] = "Lisa/vendor/Glad/include"
IncludeDir["ImGui"] = "Lisa/vendor/imgui"

include "Lisa/vendor/GLFW"
include "Lisa/vendor/Glad"
include "Lisa/vendor/imgui"

project "Lisa"
	location "Lisa"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lspch.h"
	pchsource "Lisa/src/lspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"LS_PLATFORM_WINDOWS",
			"LS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LS_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "LS_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "LS_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Lisa/vendor/spdlog/include",
		"Lisa/src"
	}

	links
	{
		"Lisa"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"LS_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "LS_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "LS_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "LS_DIST"
		runtime "Release"
		optimize "On"