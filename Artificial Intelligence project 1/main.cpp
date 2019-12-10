#include "aso.h"


#include <string>






//Screen dimension constants

const int SCREEN_WIDTH = 840;

const int SCREEN_HEIGHT = 680;


int main( int argc, char* args[] )

{

bool pause = 1;

const int FPS = 30;

const int frameDelay = 1000/FPS;

Uint32 frameStart;

int frameTime;


Draw * draw = new Draw(SCREEN_WIDTH,SCREEN_HEIGHT);

Aso aso(draw);

std::string aso_console = "add 1 1 add 3 3 add 7 6 add 2 8 add 10 1 beginning 2 start";

std::string message_i;

int i = 0;

{

SDL_bool done = SDL_FALSE;

SDL_StartTextInput();

while (!done)

{

frameStart = SDL_GetTicks();


SDL_Event event;


draw->SetRenderDrawColor(0,0,0,SDL_ALPHA_OPAQUE);

draw->RenderClear();

aso.Draw_cities();

draw->SetRenderDrawColor( 255, 255, 255,SDL_ALPHA_OPAQUE );

if(!pause)

{

aso.run(draw);

i++;


draw->SetRenderDrawColor( 255, 0, 0,SDL_ALPHA_OPAQUE );

aso.draw_best();

}

else if (aso.best_distance()>0)

{

draw->SetRenderDrawColor( 255, 0, 0,SDL_ALPHA_OPAQUE );

aso.draw_best();

}

draw->draw_message(aso_console, 5,SCREEN_HEIGHT-30);

draw->draw_message(to_string(i)+"\tbest way:\t"+ aso.best_way()+"\tleaght:\t"+ to_string(aso.best_distance()),5,5);

draw->RenderPresent();

SDL_StartTextInput();


while (SDL_PollEvent(&event))

{

if( event.key.keysym.sym == SDLK_ESCAPE ){done = SDL_TRUE;}

else if(event.key.keysym.sym == SDLK_RETURN)

{

std::istringstream iss(aso_console);

std::string arg;


while(iss >> arg )

if (arg == "add")

{

float city_x;

float city_y;

iss>>city_x;

iss>>city_y;

aso.add_city(city_x,city_y);

i = 0;


}

else if(arg == "start")

{

pause = 0;

}

else if(arg == "stop")

{

pause = 1;

}

else if(arg == "beginning")

{

int beginning;

iss>>beginning;

aso.set_city_beginning(beginning);

i = 0;

}

else if(arg == "scale")

{

int scale;

iss>>scale;

draw->set_scale(scale);

i = 0;

}


aso_console = "";

}

else if (event.type == SDL_QUIT)

{

done = SDL_TRUE;

}

else if( event.type == SDL_KEYDOWN )

{

if( event.key.keysym.sym == SDLK_BACKSPACE)

{

if(!aso_console.empty())

aso_console.pop_back();

}

//Handle copy

else if( event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )

{

SDL_SetClipboardText( aso_console.c_str() );

}

//Handle paste

else if( event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )

{

aso_console = SDL_GetClipboardText();

}

}

if( event.type == SDL_TEXTINPUT )

{

if( !( ( event.text.text[ 0 ] == 'c' || event.text.text[ 0 ] == 'C' ) && ( event.text.text[ 0 ] == 'v' || event.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )

{

aso_console += event.text.text;

}

}

}

frameTime = frameStart-SDL_GetTicks();

if(frameDelay>frameTime)

SDL_Delay(frameDelay - frameTime);

}

SDL_StopTextInput();

}

delete draw;

return 0;

}
