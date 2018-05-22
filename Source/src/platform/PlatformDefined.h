#pragma once

#ifdef __cplusplus
#	define NS_BEGIN                     namespace Fighting {
#	define NS_END                       }
#	define USING_NS                     using namespace Fighting
#	define NS_                          Fighting
#	define NS_NAME						"Fighting"
#else
#	define NS_BEGIN
#	define NS_END
#	define USING_NS
#	define NS_
#	define NS_NAME						""
#endif

#define Assert(con)	