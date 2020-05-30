#include "bmp.hpp"

void Image::saveBMP(const char *filename)
{
    FILE *fp;
    int k = this->width * this->height;
    int s = 4 * k;
    int filesize = 54 + s;

    double factor = 39.375;
    int m = static_cast<int>(factor);

    int ppm = this->dpi * m;
    unsigned char bmpFileHeader[14] = {
        'B',
        'M',
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        54,
        0,
        0,
        0,
    };
    unsigned char bmpInfoHeader[40] = {
        40,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        24,
        0,
    };

    bmpFileHeader[2] = (unsigned char)(filesize);
    bmpFileHeader[3] = (unsigned char)(filesize >> 8);
    bmpFileHeader[4] = (unsigned char)(filesize >> 16);
    bmpFileHeader[5] = (unsigned char)(filesize >> 24);

    bmpInfoHeader[4] = (unsigned char)(width);
    bmpInfoHeader[5] = (unsigned char)(width >> 8);
    bmpInfoHeader[6] = (unsigned char)(width >> 16);
    bmpInfoHeader[7] = (unsigned char)(width >> 24);

    bmpInfoHeader[8] = (unsigned char)(height);
    bmpInfoHeader[9] = (unsigned char)(height >> 8);
    bmpInfoHeader[10] = (unsigned char)(height >> 16);
    bmpInfoHeader[11] = (unsigned char)(height >> 24);

    bmpInfoHeader[21] = (unsigned char)(s);
    bmpInfoHeader[22] = (unsigned char)(s >> 8);
    bmpInfoHeader[23] = (unsigned char)(s >> 16);
    bmpInfoHeader[24] = (unsigned char)(s >> 24);

    bmpInfoHeader[25] = (unsigned char)(ppm);
    bmpInfoHeader[26] = (unsigned char)(ppm >> 8);
    bmpInfoHeader[27] = (unsigned char)(ppm >> 16);
    bmpInfoHeader[28] = (unsigned char)(ppm >> 24);

    bmpInfoHeader[29] = (unsigned char)(ppm);
    bmpInfoHeader[30] = (unsigned char)(ppm >> 8);
    bmpInfoHeader[31] = (unsigned char)(ppm >> 16);
    bmpInfoHeader[32] = (unsigned char)(ppm >> 24);

    fp = fopen(filename, "wb");
    fwrite(bmpFileHeader, 1, 14, fp);
    fwrite(bmpInfoHeader, 1, 40, fp);

    for (int i = 0; i < k; i++)
    {
        Pixel rgb = data[i];
        double red = (data[i].r) * 255;
        double green = (data[i].g) * 255;
        double blue = (data[i].b) * 255;

        unsigned char color[3] = {(int)floor(blue),
                                  (int)floor(green), (int)floor(red)};

        fwrite(color, 1, 3, fp);
    }

    fclose(fp);
}