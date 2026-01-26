include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Lisa"
	architecture "x86_64"
	startproject "Lizzy"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Lisa/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Lisa/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Lisa/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Lisa/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Lisa/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Lisa/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Lisa/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Lisa/vendor/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "Lisa/vendor/GLFW"
	include "Lisa/vendor/Glad"
	include "Lisa/vendor/imgui"
	include "Lisa/vendor/yaml-cpp"
group ""

include "Lisa"
include "Sandbox"
include "Lizzy"