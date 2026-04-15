#include "AsciiTexture.h"

AsciiTexture::AsciiTexture(int height, int width, RenderColor color){
    this->color = color;
    texture = new char* [height];
    for (int i = 0;i < height;i++) {
        texture[i] = new char[width];
    }
    this->height = height;
    this->width = width;

    for (int i = 0;i < height;i++) {
        for (int j = 0;j < width;j++) {
            texture[i][j] = 'E';
        }
    }
}

int AsciiTexture::getHeight() {
    return height;
}

int AsciiTexture::getWidth() {
    return width;
}

char* AsciiTexture::getRow(int row) {
    return texture[row];
}

RenderColor AsciiTexture::getColor() {
    return color;
}

void AsciiTexture::fillRow(int row, string content) {
    for (int j = 0;j < width;j++) {
        texture[row][j] = content[j];
    }
}

void AsciiTexture::printTexure() {
    for (int i = 0;i < height;i++) {
        for (int j = 0;j < width;j++) {
            if (texture[i][j] != 'E')
                cout << texture[i][j];
        }
        cout << endl;
    }
}
