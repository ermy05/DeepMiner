#include "ScreenRenderer.h"

ScreenRenderer::ScreenRenderer(int height, int width){
    screen = new char* [height];
    colorArray = new RenderColor * [height];
    for (int i = 0;i < height;i++) {
        screen[i] = new char[width];
        colorArray[i] = new RenderColor[width];
    }
    this->height = height;
    this->width = width;

    clearScreen();
}

void ScreenRenderer::addTextureToScreen(AsciiTexture* texture, int x, int y){
    addTextureToScreen(texture, x, y, texture->getColor());
}

void ScreenRenderer::addTextureToScreen(AsciiTexture* texture, int x, int y, RenderColor color){
    for (int i = 0;i < texture->getHeight();i++) {
        if (i + y < 0 || i + y >= height) break;

        for (int j = 0;j < texture->getWidth();j++) {
            if (j + x >= width || j + x < 0) break;

            char c = texture->getRow(i)[j];
            if (c == 'E') continue;
            screen[i + y][j + x] = c;
            colorArray[i + y][j + x] = color;
        }
    }
}

void ScreenRenderer::addStringToScreen(string content, RenderColor color, int x, int y) {
    if (y < 0 || y >= height) return;
    for (int j = 0;j < content.length();j++) {
        if (j + x >= width || j + x < 0) break;

        char c = content[j];
        screen[y][j + x] = c;
        colorArray[y][j + x] = color;
    }
}

void ScreenRenderer::addStringToScreenVertically(string content, RenderColor color, int x, int y) {
    if (x < 0 || x >= width) return;
    for (int j = 0;j < content.length();j++) {
        if (j + y >= height || j + y < 0) break;

        char c = content[j];
        screen[y + j][x] = c;
        colorArray[y + j][x] = color;
    }
}

void ScreenRenderer::clearScreen() {
    for (int j = 0;j < width;j++) {
        screen[0][j] = '-';
        colorArray[0][j] = green;
        screen[height - 1][j] = '-';
        colorArray[height - 1][j] = green;
    }

    for (int i = 1;i < height - 1;i++) {
        screen[i][0] = '|';
        colorArray[i][0] = green;
        screen[i][width - 1] = '|';
        colorArray[i][width - 1] = green;
    }

    for (int i = 1;i < height - 1;i++) {
        for (int j = 1;j < width - 1;j++) {
            screen[i][j] = ' ';
            colorArray[i][j] = normal;
        }
    }
}

void ScreenRenderer::printScreen() {
    string outputBuffer = "";
    for (int i = 0;i < height;i++) {
        for (int j = 0;j < width;j++) {
            outputBuffer += RenderColorToString(colorArray[i][j]);
            outputBuffer += screen[i][j];
        }
        outputBuffer += "\n";
    }
    cout << outputBuffer << RESET;
}
