workspace "CoticoEngine"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CoticoEngine"
	location "CoticoEngine"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp",
		"%{prj.name}/ThirdParty/include/**.hpp",
		"%{prj.name}/ThirdParty/include/**.inl",
	}

	includedirs 
	{
		"%{prj.name}/ThirdParty/include",
	}

	libdirs
	{
		"%{prj.name}/ThirdParty/lib/SFML/"
	}

	defines
	{
		"SFML_STATIC",
	}

	links
	{
		"sfml-system-s.lib",
		"sfml-window-s.lib",
		"sfml-graphics-s.lib",
		"sfml-audio-s.lib",
		"freetype.lib",
		"winmm.lib",
		"gdi32.lib",
		"openal32.lib",
		"flac.lib",
		"vorbisenc.lib",
		"vorbisfile.lib",
		"vorbis.lib",
		"ogg.lib",
		"ws2_32.lib",
		"opengl32.lib",
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter { "system:windows"}
		buildoptions "/MD"