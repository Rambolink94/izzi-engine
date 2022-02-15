#pragma once

#ifdef IZ_PLATFORM_WINDOWS
	#ifdef IZ_BUILD_DLL
		#define IZZI_API __declspec(dllexport)
	#else
		#define IZZI_API __declspec(dllimport)
	#endif
#else
	#error izzi only supports Windows!
#endif