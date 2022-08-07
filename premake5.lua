workspace "CoticoEngine"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release"
	}
	startproject "Game"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "CoticoEngine"
include "Game"