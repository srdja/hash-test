#include <png.h>
#include <stdlib.h>

#include "draw.h"
#include "defs.h"


static FORCE_INLINE void color_pixel(png_byte *pix, int entries, int threshold)
{
    if (entries > threshold)
        entries = threshold;

    float scale = (1 / (float) threshold) * entries;

    pix[0] = (int) (255 * scale);
    pix[1] = (int) (255 * scale);
    pix[2] = (int) (255 * scale);
}


void draw_png(char* file_path, int *buffer, int threshold)
{
    png_structp png  = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop   info = png_create_info_struct(png);
    FILE       *file = fopen(file_path, "wb");

    png_init_io(png, file);

    png_set_IHDR(
        png,
        info,
        IMG_WIDTH,
        IMG_HEIGHT,
        8,
        PNG_COLOR_TYPE_RGB,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT);

    png_write_info(png, info);

    png_bytep row = (png_bytep) malloc(3 * IMG_WIDTH * sizeof(png_byte));

    for (int y = 0 ; y < IMG_HEIGHT ; y++) {
        for (int x = 0 ; x < IMG_WIDTH ; x++) {
            color_pixel(&(row[x * 3]), buffer[y * IMG_WIDTH + x], threshold);
        }
        png_write_row(png, row);
    }
    png_write_end(png, NULL);
}
