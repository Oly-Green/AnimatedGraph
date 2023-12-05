//
// Created by olive on 12/5/2023.
//

#include "../include/Display.h"

Display::Display(int width, int height) : SCREEN_HEIGHT(height), SCREEN_WIDTH(width) {

}

bool Display::init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else{
        gameWindow = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gameWindow == nullptr){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else{
            gameScreenSurface = SDL_GetWindowSurface(gameWindow);
            gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if (gameRenderer == nullptr){
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else{
                SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
    }

    return success;
}

SDL_Renderer *Display::getRenderer() {
    return gameRenderer;
}

void Display::closeDisplay() {
    SDL_DestroyRenderer(gameRenderer);
    gameRenderer = nullptr;
    SDL_FreeSurface( gameCurrentSurface);
    SDL_DestroyWindow(gameWindow);
    gameWindow = nullptr;
    SDL_Quit();
}
