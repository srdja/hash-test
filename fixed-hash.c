#include "fixed-hash.h"
#include "defs.h"


#define BIG_CONSTANT(x) (x##LLU)


static FORCE_INLINE uint64_t fmix64(uint64_t k)
{
    k ^= k >> 33;
    k *= BIG_CONSTANT(0xff51afd7ed558ccd);
    k ^= k >> 33;
    k *= BIG_CONSTANT(0xc4ceb9fe1a85ec53);
    k ^= k >> 33;

    return k;
}


static FORCE_INLINE uint32_t rotl32 ( uint32_t x, int8_t r )
{
    return (x << r) | (x >> (32 - r));
}


uint64_t fixed_hash(const void *key, int len, uint32_t seed)
{
    uint32_t h1 = seed;
    uint32_t h2 = seed;

    const uint64_t c1 = BIG_CONSTANT(0x87c37b91114253d5);
    const uint64_t c2 = BIG_CONSTANT(0x4cf5ad432745937f);

    uint32_t k1 = (uint32_t)  (uintptr_t) key;
    uint32_t k2 = (uint32_t) ((uintptr_t) key >> (uint64_t) 32);

    k1 *= c1;
    k1  = rotl32(k1,31);
    k1 *= c2;
    h1 ^= k1;
    h1  = rotl32(h1,27);
    h1 += h2;
    h1  = h1 * 5 + 0x52dce729;

    k2 *= c2;
    k2  = rotl32(k2,33);
    k2 *= c1;
    h2 ^= k2;
    h2  = rotl32(h2,31);
    h2 += h1;
    h2  = h2 * 5 + 0x38495ab5;

    h1 ^= len; h2 ^= len;

    h1 += h2;
    h2 += h1;

    h1 = fmix64(h1);
    h2 = fmix64(h2);

    h1 += h2;
    h2 += h1;

    uint64_t result = ((uint64_t) h1 << 32) | (uint64_t) h2;

    return result;
}