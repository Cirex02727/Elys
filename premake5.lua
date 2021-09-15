workspace "Elys"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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

	includedirs {
		"%{prj.name}/src", 
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ELYS_PLATFORM_WINDOWS",
			"ELYS_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ELYS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ELYS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ELYS_DIST"
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
		symbols "On"

	filter "configurations:Release"
		defines "ELYS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ELYS_DIST"
		optimize "On"