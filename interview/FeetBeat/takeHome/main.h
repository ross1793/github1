#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdarg.h>

#if 1
#define DBG(...)    printf(__VA_ARGS__)
#else
#define DBG(...)
#endif

#define BUFFER_SIZE    32


#endif
