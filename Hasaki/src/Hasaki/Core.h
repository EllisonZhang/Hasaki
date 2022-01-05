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

#ifdef HSK_ENABLE_ASSERTS 
	#define HSK_ASSERT(x, ...) 
		{
			if (!(x)) 
			{
				HSK_CLIENT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();
			}
		}
	#define HSK_CORE_ASSERT(x, ...) 
		{
			if (!(x))
			{
				HSK_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();
			}
		}
#else
	#define HSK_ASSERT(x, ...)
	#define HSK_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) 1<<(x)