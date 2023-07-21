#pragma once

#ifdef TL_PLATFORM_WINDOWS
	#ifdef	TL_BUILD_DLL
		#define	TRILOBAL_API __declspec(dllexport)
	#else
		#define TRILOBAL_API __declspec(dllimport)
	#endif
#else
	#error Trilobal only support Windows!
#endif


#ifdef TL_ENABLED_ASSERTS
	#define TL_ASSERT(x, ... ){if(!(x)){TL_ERROR("Assertion Failed : {0}",__VA_ARGS__);__debugbreak;}}
	#define TL_CORE_ASSERT(x, ... ){if(!(x)){TL_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak;}};
#else
	#define TL_ASSERT(x, ...)
	#define TL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x) //1 * 2^x