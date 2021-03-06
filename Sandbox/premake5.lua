project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Elys/vendor/spdlog/include",
		"%{wks.location}/Elys/src",
		"%{wks.location}/Elys/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
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

		postbuildcommands
		{
			"{COPYDIR} \"%{LibraryDir.VulkanSDK_DebugDLL}\" \"%{cfg.targetdir}\""
		}

	filter "configurations:Release"
		defines "ELYS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ELYS_DIST"
		runtime "Release"
		optimize "on"
