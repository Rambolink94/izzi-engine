workspace "Izzi"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Izzi"
	location "Izzi"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"IZ_PLATFORM_WINDOWS",
			"IZ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "IZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IZ_DIST"
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
		"Izzi/vendor/spdlog/include",
		"Izzi/src"
	}

	links
	{
		"Izzi"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"IZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "IZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IZ_DIST"
		optimize "On"