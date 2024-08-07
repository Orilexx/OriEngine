#pragma once


#ifdef ORI_PLATFORM_WINDOWS
	#ifdef ORI_BUILD_DLL
		#define ORI_API __declspec(dllexport)
	#else
		#define ORI_API __declspec(dllimport)
	#endif
#else
	#error Ori only supports Windows!
#endif