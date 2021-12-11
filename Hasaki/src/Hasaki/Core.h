#pragma once

#ifdef HSK_PLATFORM_WINDOWS
	#ifdef HSK_BUILD_DLL
		#define HSK_API _declspec(dllexport)
    #else 
		#define HSK_API _declspec(dllimport)
	#endif
#else 
	#error Hasaki only support for windows for now!
#endif
