#include "Draw.h"



Draw::Draw(int width, int height)

{

if (SDL_Init(SDL_INIT_VIDEO) < 0)

{

SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());

}

else

{

//Set texture filtering to linear

if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )

{

SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Warning: Linear texture filtering not enabled!" );

}

}

if (SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer))

{

SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());

}

else

{

SDL_SetWindowTitle(window," Ant Colony Optimization");

TTF_Init();

font = TTF_OpenFont("ap.ttf", 24);

if( font == NULL )

{

SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, TTF_GetError() );

}


}




surface = SDL_LoadBMP( "city.bmp" );

if (!surface)

{

SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());

}

cityTexture = SDL_CreateTextureFromSurface(renderer,surface);

if (!cityTexture)

{

SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());

}



text = TTF_RenderText_Solid(font, "Test Message", txtColor);

txt_texture = SDL_CreateTextureFromSurface(renderer,text);

if (!txt_texture)

{

SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());

}




}



int Draw::SetRenderDrawColor(Uint8 r,Uint8 g,Uint8 b, Uint8 a)

{

return SDL_SetRenderDrawColor(renderer, r, g, b, a);

}


int Draw::RenderClear()

{

return SDL_RenderClear(renderer);

}

void Draw::RenderPresent()

{

SDL_RenderPresent(renderer);

}


int Draw::RenderDrawLine(int x1,int y1,int x2,int y2)

{

return SDL_RenderDrawLine( renderer,x1* scale, y1 * scale, x2 * scale, y2* scale);

}

int Draw::RenderDrawLine(City first_city,City second_city)

{

return SDL_RenderDrawLine( renderer,first_city.get_x()* scale, first_city.get_y() * scale, second_city.get_x() * scale, second_city.get_y()* scale);

}

void Draw::RenderDrawCity(int x,int y)

{

x *=scale;

y*=scale;

SDL_Rect DestR;

DestR.x = x - 8;

DestR.y = y - 8;

DestR.w = 16;

DestR.h = 16;



SDL_RenderCopy(renderer, cityTexture, NULL, &DestR);


}


int Draw::draw_message(std::string sMessage, int x, int y)

{


SDL_FreeSurface(text);

SDL_DestroyTexture(txt_texture);


text = TTF_RenderText_Solid(font, sMessage.c_str(), txtColor);

txt_texture = SDL_CreateTextureFromSurface(renderer,text);

{

SDL_Rect DestR;

DestR.x = x ;

DestR.y = y;

SDL_QueryTexture(txt_texture,NULL,NULL,&DestR.w,&DestR.h);




SDL_RenderCopy(renderer, txt_texture, NULL, &DestR);

}


return 0;


}




Draw::~Draw()

{

if (renderer)

{

SDL_DestroyRenderer(renderer);

}

if (window)

{

SDL_DestroyWindow(window);

}

if(surface)

{

SDL_FreeSurface(surface);

}

if(cityTexture)

{

SDL_DestroyTexture(cityTexture);

}

if(text)

{

SDL_FreeSurface(text);

}



TTF_Quit();

/// IMG_Quit();

SDL_Quit();

}


