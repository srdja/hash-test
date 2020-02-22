#ifndef __FIXED_HASH32_H__
#define __FIXED_HASH32_H__

#include <stdint.h>
#include <stdlib.h>

size_t fixed_hash32(const void *key, int len, uint32_t seed);

#endif
