#ifndef ASCIITEXTURE_H
#define ASCIITEXTURE_H

#include "ColorData.h"
#include <iostream>

using namespace std;

class AsciiTexture
{
public:
    AsciiTexture(int height, int width, RenderColor color);
    
    int getHeight();
    int getWidth();
    char* getRow(int row);
    RenderColor getColor();
    void fillRow(int row, string content);
    void printTexure();

protected:

private:
    char** texture;
    RenderColor color;
    int height;
    int width;
};

#endif // ASCIITEXTURE_H
