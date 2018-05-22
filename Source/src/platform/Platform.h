#pragma once

#include "platform/PlatformDefined.h"

#if defined(__x86_64__)    || \
	defined(_M_X64)        || \
	defined(__aarch64__)   || \
	defined(__64BIT__)     || \
	defined(__mips64)      || \
	defined(__powerpc64__) || \
	defined(__ppc64__)     || \
	defined(__LP64__)
#	undef  ARCH_64BIT
#	define ARCH_64BIT 64
#else
#	undef  ARCH_32BIT
#	define ARCH_32BIT 32
#endif //

NS_BEGIN

typedef char i8;
typedef unsigned char u8;
typedef short i16;
typedef unsigned short u16;
typedef int i32;
typedef unsigned int u32;

#ifdef _WIN32
	typedef long long i64;
	typedef unsigned long long u64;
#	define ALIGN_BEGIN(_align) __declspec(align(_align))
#	define ALIGN_END(_align)
#elif defined __EMSCRIPTEN__
	typedef long long i64;
	typedef unsigned long long u64;
#	define ALIGN_BEGIN(_align)
#	define ALIGN_END(_align) __attribute__( (aligned(_align) ) )
#else
#	ifdef ARCH_64BIT
		typedef long i64;
		typedef unsigned long u64;
#	else
		typedef long long i64;
		typedef unsigned long long u64;
#	endif
#	define ALIGN_BEGIN(_align)
#	define ALIGN_END(_align) __attribute__( (aligned(_align) ) )
#endif

#ifdef ARCH_64BIT
	typedef u64 uintptr;
#else
	typedef u32 uintptr;
#endif

static_assert(sizeof(uintptr) == sizeof(void*), "Incorrect size of uintptr");
static_assert(sizeof(i64) == 8, "Incorrect size of i64");
static_assert(sizeof(i32) == 4, "Incorrect size of i32");
static_assert(sizeof(i16) == 2, "Incorrect size of i16");
static_assert(sizeof(i8) == 1, "Incorrect size of i8");

const u32 MAX_PATH_LENGTH = 260;

NS_END

#ifdef _MSC_VER
#	pragma warning(disable : 4251)
#	pragma warning(disable : 4996)
#	if _MSC_VER == 1900 
#		pragma warning(disable : 4091)
#	endif
#endif