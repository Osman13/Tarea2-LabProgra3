#ifndef JUGADOR_H
#define JUGADOR_H

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<vector>

using namespace std;

class Jugador
{
    public:
        SDL_Renderer* renderer;
        vector<SDL_Texture*>textures;
        SDL_Rect rect;
        int current_texture;
        int frames;
        int jugador;
        Jugador(SDL_Renderer* renderer, int jugador);
        virtual ~Jugador();
        void dibujar();
        void logica();
    protected:
    private:
};

#endif // JUGADOR_H
