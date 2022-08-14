project "Game"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Source/**.h",
		"Source/**.cpp",
	}

	includedirs
	{
		"%{wks.location}/CoticoEngine/Source",
		"%{wks.location}/CoticoEngine/ThirdParty/include",
	}

	libdirs
	{
		"%{wks.location}/CoticoEngine/ThirdParty/lib/SFML/"
	}

	defines
	{
		"SFML_STATIC",
	}

	links
	{
		"CoticoEngine",
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/MD"

	filter "configurations:Shipping"
		defines "SHIPPING"
		
