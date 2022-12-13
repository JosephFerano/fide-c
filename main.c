#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("SDL Text Editor", 0, 0, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    /* FILE *font_file = fopen("./fira.ttf", "r"); */
    TTF_Font *font = TTF_OpenFont("./fira.ttf", 8);
    
    SDL_Surface *surface = SDL_CreateRGBSurface(0, 256, 256, 0, 255, 0 , 0, 255);

    SDL_Texture *texture = SDL_CreateTexture(renderer, 0, 0, 800, 600);

    bool quit = false;
    
    while (!quit) {
        SDL_Event event = {0};

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    return 0;
}
