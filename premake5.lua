workspace "Emerald"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Emerald"
	location "Emerald"
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
		"%{prj.name}/thirdparty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EMERALD_PLATFORM_WINDOWS",
			"EMERALD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		architecture "x64"
		defines "EMERALD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		architecture "x64"
		defines "EMERALD_RELEASE"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "COnsoleApp"
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
		"Emerald/thirdparty/spdlog/include",
		"Emerald/src"
	}

	links
	{
		"Emerald"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EMERALD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		architecture "x64"
		defines "EMERALD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		architecture "x64"
		defines "EMERALD_RELEASE"
		optimize "On"