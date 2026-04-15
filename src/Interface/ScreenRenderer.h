#ifndef SCREENRENDERER_H
#define SCREENRENDERER_H

#include <iostream>
#include <src/Interface/AsciiTexture.h>

using namespace std;



class ScreenRenderer
{
    public:
        ScreenRenderer(int height,int width);

        void addTextureToScreen(AsciiTexture* texture,int x,int y);
        void addTextureToScreen(AsciiTexture* texture, int x, int y,RenderColor color);
        void addStringToScreen(string content,RenderColor color,int x,int y);
        void addStringToScreenVertically(string content,RenderColor color,int x,int y);
        void clearScreen();
        void printScreen();

    protected:

    private:
        char** screen;
        RenderColor** colorArray;
        int height;
        int width;
};

#endif // SCREENRENDERER_H