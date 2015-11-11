#include "Jugador.h"

Jugador::Jugador(SDL_Renderer* renderer, int jugador)
{
    this->renderer = renderer;
    this->jugador = jugador;
    this->textures.push_back(IMG_LoadTexture(renderer, "Personaje/down1.png"));
    this->textures.push_back(IMG_LoadTexture(renderer, "Personaje/down2.png"));

    SDL_QueryTexture(this->textures[0], NULL, NULL, &rect.w, &rect.h);
    if(jugador == 1)
    {
        rect.x = 50;
        rect.y = 50;
    }
    else
    {
        rect.x = 150;
        rect.y = 150;
    }
    current_texture=0;
}

Jugador::~Jugador()
{
    //dtor
}

void Jugador::dibujar()
{
    SDL_RenderCopy(renderer, textures[current_texture], NULL, &rect);
}

void Jugador::logica()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

    if(jugador == 1){
        if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
        {
        rect.x+=1;
        }
        if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
        {
            rect.x-=1;
        }
        if( currentKeyStates[ SDL_SCANCODE_UP ] )
        {
            rect.y-=1;
        }
        if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
        {
            rect.y+=1;
        }
    }
     else{
        if( currentKeyStates[ SDL_SCANCODE_F ] )
        {
        rect.x+=1;
        }
        if( currentKeyStates[ SDL_SCANCODE_D ] )
        {
            rect.x-=1;
        }
        if( currentKeyStates[ SDL_SCANCODE_S ] )
        {
            rect.y-=1;
        }
        if( currentKeyStates[ SDL_SCANCODE_A ] )
        {
            rect.y+=1;
        }
    }

    if(frames%500==0)
    {
        current_texture++;
        if(current_texture>=textures.size())
            current_texture=0;
    }

    frames++;
    if(frames == 500)
        frames = 0;
}
