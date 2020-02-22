#ifndef __DEFS_H__
#define __DEFS_H__


#define FORCE_INLINE inline __attribute__((always_inline))


#define IMG_WIDTH  1024
#define IMG_HEIGHT 1024


#define CAPACITY (IMG_WIDTH * IMG_HEIGHT)
#define AND_MASK CAPACITY - 1


#define POINTER_CAPACITY CAPACITY


#define THRESHOLD 8


#define FILE_HASH_FIXED64  "fixed-hash64.png"
#define FILE_HASH_BROKEN64 "hash-broken64.png"
#define FILE_HASH_FIXED32  "fixed-hash32.png"
#define FILE_HASH_BROKEN32 "broken-hash32.png"


#define FILE_POINTER       "pointer.png"
#define FILE_RANDOM        "random.png"


#endif
