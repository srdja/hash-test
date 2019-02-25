#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>


#include "fixed-hash.h"
#include "broken-hash.h"
#include "defs.h"
#include "draw.h"


/**
 * Make a heap array of heap allocatd ints
 */
int **alloc_array_of_ints()
{
    int **pointers = malloc(POINTER_CAPACITY * sizeof(int*));

    for (int i = 0; i < POINTER_CAPACITY; i++) {
        pointers[i] = malloc(sizeof(int));
    }
    return pointers;
}


size_t no_hash(const void *ptr, int len, uint32_t seed)
{
    return (uintptr_t) ptr;
}


size_t random_hash(const void *ptr, int len, uint32_t seed)
{
    return rand();
}


int *get_collision_map(
    int **int_array,
    size_t (*hash) (const void *k, int l, uint32_t s))
{
    int *buffer = calloc(CAPACITY, sizeof(int));

    for (int i = 0; i < CAPACITY; i++) {
        int index = hash(int_array[i], sizeof(int*), 0) & AND_MASK;
        buffer[index]++;
    }
    return buffer;
}


int main(int argc, char *argv[])
{
    srand(time(NULL));

    int **heap_ints      = alloc_array_of_ints();

    int *fixed_hash_map  = get_collision_map(heap_ints, fixed_hash);
    int *pointer_map     = get_collision_map(heap_ints, no_hash);
    int *random_map      = get_collision_map(heap_ints, random_hash);
    int *broken_hash_map = get_collision_map(heap_ints, broken_hash);

    printf("Writing fixed hash image...\n");
    draw_png(FILE_HASH_FIXED, fixed_hash_map, THRESHOLD);

    printf("Writing broken hash image...\n");
    draw_png(FILE_HASH_BROKEN, broken_hash_map, THRESHOLD);

    printf("Writing plain pointer image...\n");
    draw_png(FILE_POINTER, pointer_map, THRESHOLD);

    printf("Writing rand image...\n");
    draw_png(FILE_RANDOM, random_map, THRESHOLD);

    return 0;
}
