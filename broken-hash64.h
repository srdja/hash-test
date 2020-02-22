#ifndef __BROKEN_HASH64_H__
#define __BROKEN_HASH64_H__

#include <stdint.h>

uint64_t broken_hash64(const void *key, int len, uint32_t seed);

#endif
