workspace "CoticoEngine"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Shipping"
	}
	startproject "CoticoEditor"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "CoticoEngine"
include "Game"
include "CoticoEditor"