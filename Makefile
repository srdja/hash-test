hash: main.c fixed-hash64.c broken-hash64.c broken-hash32.c fixed-hash32.c draw.c
	gcc -o hash main.c fixed-hash64.c broken-hash64.c broken-hash32.c fixed-hash32.c draw.c -I. -lm -lpng
