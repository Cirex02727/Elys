workspace "Elys"
	architecture "x86_64"
	startproject "Elysnut"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Elys/vendor/GLFW/include"
IncludeDir["Glad"] = "Elys/vendor/Glad/include"
IncludeDir["ImGui"] = "Elys/vendor/imgui"
IncludeDir["glm"] = "Elys/vendor/glm"
IncludeDir["stb_image"] = "Elys/vendor/stb_image"

group "Dependencies"
	include "Elys/vendor/GLFW"
	include "Elys/vendor/Glad"
	include "Elys/vendor/imgui"

group ""

project "Elys"
	location "Elys"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "elyspch.h"
	pchsource "Elys/src/elyspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "ELYS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ELYS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ELYS_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Elys/vendor/spdlog/include",
		"Elys/src",
		"Elys/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Elys"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "ELYS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ELYS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ELYS_DIST"
		runtime "Release"
		optimize "on"

project "Elysnut"
	location "Elysnut"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Elys/vendor/spdlog/include",
		"Elys/src",
		"Elys/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Elys"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "ELYS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ELYS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ELYS_DIST"
		runtime "Release"
		optimize "on"