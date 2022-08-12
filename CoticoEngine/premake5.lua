project "CoticoEngine"
	kind "StaticLib"
	language "C++"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Source/**.h",
		"Source/**.cpp",
		"ThirdParty/include/ImGUI/**.h",
		"ThirdParty/include/ImGUI/**.cpp",
		"ThirdParty/include/**.hpp",
		"ThirdParty/include/**.inl",
	}

	includedirs 
	{
		"ThirdParty/include",
		"ThirdParty/include/ImGUI",
		"Source",
		"%{wks.location}/CoticoEditor/Source"
	}

	libdirs
	{
		"ThirdParty/lib/SFML/"
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