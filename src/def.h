#ifndef _COMPATIBILITY_H_
#define _COMPATIBILITY_H_

#if __cplusplus < 202002L
	#define COMPATIBILITY "ERROR: C++ Version Incompatible. Please Use C++20 To Compile This Program"
#else
	#define COMPATIBILITY "C++ Version Compatible With This Program. (C/C++20)"
#if __linux__
	#define OS "OS Compatible With This Program. (linux)"
#else
	#define OS "ERROR: OS Incompatible. Use Linux To Compile This Program"
#endif
#endif
#endif