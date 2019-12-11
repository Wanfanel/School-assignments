#include <SDL.h>

//#include <SDL_image.h>

#include <SDL_ttf.h>

#include <string>

#ifndef DRAW_H

#define DRAW_H

#include "city.h"

class Draw

{

public:
    Draw(int width = 640, int height = 480);

    virtual ~Draw();

    int RenderDrawLine(int x1, int y1, int x2, int y2);

    int RenderDrawLine(City, City);

    void RenderDrawCity(int, int);

    int draw_message(std::string, int x = 5, int y = 5);

    int SetRenderDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    int RenderClear();

    void RenderPresent();

    SDL_Renderer *get_renderer() { return renderer; }

    void set_scale(int s) { scale = s; }

protected:
private:
    SDL_Window *window = NULL;

    SDL_Renderer *renderer = NULL;

    SDL_Surface *surface = NULL;

    SDL_Texture *cityTexture = NULL;

    SDL_Texture *txt_texture = NULL;

    TTF_Font *font = NULL;

    SDL_Surface *text = NULL;

    int scale = 50;

    SDL_Color txtColor = {255, 255, 255};
};

#endif // DRAW_H
