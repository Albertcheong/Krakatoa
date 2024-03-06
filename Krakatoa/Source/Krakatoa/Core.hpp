#pragma once

#ifdef KRAKATOA_BUILD_DLL
	#define KRAKATOA_API __declspec(dllexport)
#else
	#define KRAKATOA_API __declspec(dllimport)
#endif