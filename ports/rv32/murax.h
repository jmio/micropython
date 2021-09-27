#ifndef __MURAX_H__
#define __MURAX_H__

#include <stdint.h>

// System Call Entry
#define MY_SYSCALL_GETSYMPTR (4000) // Only Supported

extern int syscall0(int callno);

// Flash DataCache Call
extern void flushDataCache(uint32_t dummy);

#endif /* __MURAX_H__ */
