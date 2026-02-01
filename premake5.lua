include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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

group "Dependencies"
	include "vendor/premake"
	include "Lisa/vendor/Box2D"
	include "Lisa/vendor/GLFW"
	include "Lisa/vendor/Glad"
	include "Lisa/vendor/imgui"
	include "Lisa/vendor/yaml-cpp"
group ""

include "Lisa"
include "Sandbox"
include "Lizzy"