#include "defs.h"
#include "fixed-hash32.h"


FORCE_INLINE uint32_t rotl32(uint32_t x, int8_t r)
{
    return (x << r) | (x >> (32 - r));
}


FORCE_INLINE uint32_t fmix32(uint32_t h)
{
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;

    return h;
}


#define ROTL32(x,y) rotl32(x,y)
#define BIG_CONSTANT(x) (x##LLU)


size_t fixed_hash32(const void *key, int len, uint32_t seed)
{
    uint32_t h1 = seed;

    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    uint32_t k1 = (uint32_t) (uintptr_t) key;

    k1 *= c1;
    k1 = ROTL32(k1,15);
    k1 *= c2;

    h1 ^= k1;
    h1 = ROTL32(h1,13);
    h1 = h1*5+0xe6546b64;

    /* Since the pointers are power of two length
    * we don't need a tail mix */

    h1 ^= len;
    h1  = fmix32(h1);

    return (size_t) h1;
}
