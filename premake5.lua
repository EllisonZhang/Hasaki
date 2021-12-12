workspace "Hasaki"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%cfg.architecture"

project "Hasaki"
	location "Hasaki"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	targetdir ("bin-inter/" .. outputdir .. "/%{prj.name}")

	files
	{
		"{prj.name}/src/**.h",
		"{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "10.0"

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
		symbols "On"
	filter "configurations:Dist"
		defines "HSK_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	targetdir ("bin-inter/" .. outputdir .. "/%{prj.name}")

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
		cppdialect "c++17"
		staticruntime "On"
		systemversion "10.0.17134.0"

		defines
		{
			"HSK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HSK_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "HSK_RELEASE"
		symbols "On"
	filter "configurations:Dist"
		defines "HSK_DIST"
		symbols "On"