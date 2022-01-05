workspace "Hasaki"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Hasaki/vendor/GLFW/include"
include "Hasaki/vendor/GLFW"

project "Hasaki"
	location "Hasaki"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "HasakiPCH.h"
	pchsource "Hasaki/src/HasakiPCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"		
	}
	
	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HSK_PLATFORM_WINDOWS",
			"HSK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HSK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HSK_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "HSK_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hasaki/vendor/spdlog/include",
		"Hasaki/src"
	}

	links
	{
		"Hasaki"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HSK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HSK_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "HSK_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "HSK_DIST"
		optimize "On"