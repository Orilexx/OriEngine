workspace "Ori"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ori"
	location "Ori"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ORI_PLATFORM_WINDOWS",
			"ORI_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ORI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ORI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ORI_DIST"
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
		"Ori/vendor/spdlog/include",
		"Ori/src"
	}

	links
	{
		"Ori"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ORI_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "ORI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ORI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ORI_DIST"
		optimize "On"