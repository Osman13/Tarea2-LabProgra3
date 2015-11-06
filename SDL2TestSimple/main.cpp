
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<iostream>

#include "Jugador.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character;
SDL_Rect rect_background,rect_character;
Mix_Music *music = NULL;

using namespace std;

int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }
    //Initialize SDL_Mixer
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout << "SDL_Mixer could not initialize! SDL_Mixer Error: " << Mix_GetError();
    }
    //Load music
    music = Mix_LoadMUS("darkmoon.wav");

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    Jugador jugador(renderer,1);
    Jugador jugador2(renderer,2);

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
                if(Event.type == SDL_KEYDOWN)
                {
                    switch(Event.key.keysym.sym)
                    {
                       case SDLK_p:
                            if( Mix_PlayingMusic() == 0 )
                            {
                                Mix_PlayMusic(music, -1 );
                            }
                            else
                            {
                                if( Mix_PausedMusic() == 1 )
                                {
                                    Mix_ResumeMusic();
                                }
                                else
                                {
                                    Mix_PauseMusic();
                                }
                            }
                            break;

                            case SDLK_SPACE:
                            Mix_HaltMusic();
                            break;
                    }
                }
        }

    jugador.logica();
    jugador2.logica();
    SDL_RenderCopy(renderer, background, NULL, &rect_background);
    jugador.dibujar();
    jugador2.dibujar();
    SDL_RenderPresent(renderer);

    }

	return 0;
}
