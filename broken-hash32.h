#ifndef __BROKEN_HASH32_H__
#define __BROKEN_HASH32_H__

#include <stdint.h>
#include <stdlib.h>

size_t broken_hash32(const void *key, int len, uint32_t seed);

#endif
