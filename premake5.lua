include "./vendor/premake/premake_customization/solution_items.lua"

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

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Elys/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Elys/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Elys/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Elys/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Elys/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Elys/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Elys/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Elys/vendor/ImGuizmo"

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
