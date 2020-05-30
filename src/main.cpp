#include <iostream>
#include "bmp.hpp"

int main(int argc, char **argv)
{
    int thisone;
    Image i;
    int dpi = 72;
    int width = 640;
    int height = 480;
    int n = width * height;

    Pixel *pixels = new Pixel[n];

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            thisone = y * width + x;
            pixels[thisone].r=23;
            pixels[thisone].g=222;
            pixels[thisone].b=10;
        }
    }

    i.height=480;
    i.width=640;
    i.data=pixels;
    i.saveBMP("test.bmp");
    free(pixels);

    return 0;
}