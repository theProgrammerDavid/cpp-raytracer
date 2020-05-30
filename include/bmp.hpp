#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>

class Pixel
{
public:
    double r, g, b;
};

class Image
{
public:
    Pixel *data;
    int width, height;
    int dpi;
    void saveBMP(const char *filename);
};
