workspace "Elys"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Elys/vendor/GLFW/include"
IncludeDir["Glad"] = "Elys/vendor/Glad/include"

include "Elys/vendor/GLFW"
include "Elys/vendor/Glad"

project "Elys"
	location "Elys"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "elyspch.h"
	pchsource "Elys/src/elyspch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs {
		"%{prj.name}/src", 
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links {
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ELYS_PLATFORM_WINDOWS",
			"ELYS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ELYS_DEBUG"
		staticruntime "off"
		symbols "On"

	filter "configurations:Release"
		defines "ELYS_RELEASE"
		staticruntime "off"
		optimize "On"

	filter "configurations:Dist"
		defines "ELYS_DIST"
		staticruntime "off"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Elys/vendor/spdlog/include",
		"Elys/src"
	}

	links {
		"Elys"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ELYS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ELYS_DEBUG"
		staticruntime "off"
		symbols "On"

	filter "configurations:Release"
		defines "ELYS_RELEASE"
		staticruntime "off"
		optimize "On"

	filter "configurations:Dist"
		defines "ELYS_DIST"
		staticruntime "off"
		optimize "On"