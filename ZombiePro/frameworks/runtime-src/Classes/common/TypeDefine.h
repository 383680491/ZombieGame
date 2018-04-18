#pragma once


#include <sys/types.h>

#if defined(_MSC_VER)
	//
	// Windows/Visual C++
	//
	typedef signed __int8			int8;
	typedef unsigned __int8			uint8;
	typedef signed __int16			int16;
	typedef unsigned __int16		uint16;
	typedef signed __int32			int32;
	typedef unsigned __int32		uint32;
	typedef signed __int64			int64;
	typedef unsigned __int64		uint64;
#endif


#ifdef _STLP_HASH_MAP
	#define HashMap ::std::hash_map
#else
	#define HashMap ::stdext::hash_map
#endif
