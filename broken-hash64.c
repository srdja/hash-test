#include "defs.h"
#include "broken-hash64.h"


FORCE_INLINE static uint64_t rotl64(uint64_t x, int8_t r)
{
    return (x << r) | (x >> (64 - r));
}


#define ROTL64(x,y) rotl64(x,y)
#define BIG_CONSTANT(x) (x##LLU)


FORCE_INLINE static uint64_t fmix64(uint64_t k)
{
    k ^= k >> 33;
    k *= BIG_CONSTANT(0xff51afd7ed558ccd);
    k ^= k >> 33;
    k *= BIG_CONSTANT(0xc4ceb9fe1a85ec53);
    k ^= k >> 33;

    return k;
}

/*
 * MurmurHash3 the 64bit variant that hashes the pointer itself
 */
uint64_t broken_hash64(const void *key, int len, uint32_t seed)
{
    const int nblocks = len / 4;

    uint64_t h1 = seed;
    uint64_t h2 = seed;

    const uint64_t c1 = BIG_CONSTANT(0x87c37b91114253d5);
    const uint64_t c2 = BIG_CONSTANT(0x4cf5ad432745937f);

    int i;
    for (i = 0; i < nblocks; i++) {
        uint64_t k1 = ((uintptr_t) key >> (2 * i)) & 0xff;
        uint64_t k2 = ROTL64(k1, 13);

        k1 *= c1;
        k1  = ROTL64(k1,31);
        k1 *= c2;
        h1 ^= k1;
        h1  = ROTL64(h1,27);
        h1 += h2;
        h1  = h1 * 5 + 0x52dce729;

        k2 *= c2;
        k2  = ROTL64(k2,33);
        k2 *= c1;
        h2 ^= k2;
        h2  = ROTL64(h2,31);
        h2 += h1;
        h2  = h2 * 5 + 0x38495ab5;
    }

    /* Since the pointers are power of two length
     * we don't need a tail mix */

    h1 ^= len; h2 ^= len;

    h1 += h2;
    h2 += h1;

    h1 = fmix64(h1);
    h2 = fmix64(h2);

    h1 += h2;
    h2 += h1;

    return h1;
}
