#ifndef __DEFS_H__
#define __DEFS_H__


#define FORCE_INLINE inline __attribute__((always_inline))


#define IMG_WIDTH  1024
#define IMG_HEIGHT 1024


#define CAPACITY (IMG_WIDTH * IMG_HEIGHT)
#define AND_MASK CAPACITY - 1


#define POINTER_CAPACITY CAPACITY


#define THRESHOLD 8


#define FILE_HASH_FIXED  "fixed-hash.png"
#define FILE_HASH_BROKEN "hash-broken.png"
#define FILE_POINTER     "pointer.png"
#define FILE_RANDOM      "random.png"


#endif
