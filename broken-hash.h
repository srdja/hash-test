#ifndef __BROKEN_HASH_H__
#define __BROKEN_HASH_H__

#include <stdint.h>

uint64_t broken_hash(const void *key, int len, uint32_t seed);

#endif
