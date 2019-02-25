hash: main.c fixed-hash.c broken-hash.c draw.c
	gcc -o hash main.c fixed-hash.c broken-hash.c draw.c -I. -lm -lpng
