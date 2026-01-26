project "Lizzy"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Lisa/vendor/spdlog/include",
		"%{wks.location}/Lisa/src",
		"%{wks.location}/Lisa/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
	}

	links
	{
		"Lisa"
	}

	filter "system:windows"
		systemversion "latest" buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "LS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "LS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LS_DIST"
		runtime "Release"
		optimize "on"