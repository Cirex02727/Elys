include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Elys"
	architecture "x86_64"
	startproject "Elysnut"

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
	include "Elys/vendor/GLFW"
	include "Elys/vendor/Glad"
	include "Elys/vendor/imgui"
	include "Elys/vendor/yaml-cpp"
group ""

include "Elys"
include "Sandbox"
include "Elysnut"
