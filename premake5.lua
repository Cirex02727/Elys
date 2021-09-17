workspace "Elys"
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
IncludeDir["GLFW"] = "Elys/vendor/GLFW/include"
IncludeDir["Glad"] = "Elys/vendor/Glad/include"
IncludeDir["ImGui"] = "Elys/vendor/imgui"
IncludeDir["glm"] = "Elys/vendor/glm"

include "Elys/vendor/GLFW"
include "Elys/vendor/Glad"
include "Elys/vendor/imgui"

project "Elys"
	location "Elys"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "elyspch.h"
	pchsource "Elys/src/elyspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
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

		defines
		{
			"ELYS_PLATFORM_WINDOWS",
			"ELYS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "ELYS_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ELYS_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ELYS_DIST"
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
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"ELYS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ELYS_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ELYS_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ELYS_DIST"
		runtime "Release"
		optimize "On"