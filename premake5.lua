--premake5.lua
workspace "Krakatoa"
    architecture "x64"
    configurations
    {
        "Debug", 
        "Release", 
        "Distribution"
    }

    startproject "SandBox"

project "Krakatoa"
    location "Krakatoa"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}-main")
    objdir ("bin-intermediate/%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")

    files 
    {
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.cpp"
    }

    includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

    cppdialect "C++20"
    staticruntime "On"
    systemversion "latest"

    defines { "KRAKATOA_BUILD_DLL" }

    postbuildcommands 
    {
        "{RMDIR} ../bin/%{cfg.buildcfg}-%{cfg.architecture}/SandBox",
        "{MKDIR} ../bin/%{cfg.buildcfg}-%{cfg.architecture}/SandBox",
        "{COPYFILE} ../bin/%{cfg.buildcfg}-%{cfg.architecture}/Krakatoa-main/Krakatoa.dll ../bin/%{cfg.buildcfg}-%{cfg.architecture}/SandBox"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter "configurations:Distribution"
        defines { "DIST" }
        optimize "On"


project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")
    objdir ("bin-intermediate/%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")

    files
    {
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.cpp"
    }

	includedirs
	{
		"Krakatoa/vendor/spdlog/include",
		"Krakatoa/Source"
	}

	links
	{
		"Krakatoa"
	}

    cppdialect "C++20"
    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter "configurations:Distribution"
        defines { "DIST" }
        optimize "On"

