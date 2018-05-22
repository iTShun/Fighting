#pragma once

#include "platform/Platform.h"
#include "bx/allocator.h"

NS_BEGIN
struct NewPlaceholder {};
NS_END

inline void* operator new(size_t, NS_::NewPlaceholder, void* where)
{
	return where;
}


inline void operator delete(void*, NS_::NewPlaceholder, void*)
{
}

NS_BEGIN

#define ALIGN_OF(...) __alignof(__VA_ARGS__)
#define NEW(allocator, ...) new (NS_::NewPlaceholder(), (allocator).allocate_aligned(sizeof(__VA_ARGS__), ALIGN_OF(__VA_ARGS__))) __VA_ARGS__
#define DELETE(allocator, var) (allocator).deleteObject(var);



NS_END