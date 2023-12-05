//
// Created by olive on 12/5/2023.
//

#ifndef ANIMATEDGRAPH_DISPLAY_H
#define ANIMATEDGRAPH_DISPLAY_H
#include <SDL.h>

class Display {
private:
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;

    SDL_Window* gameWindow = nullptr;
    SDL_Surface* gameScreenSurface = nullptr;
    SDL_Surface * gameCurrentSurface = nullptr;
    SDL_Renderer* gameRenderer = nullptr;

public:
    Display(int width, int height);

//Starts up SDL and creates window
    bool init();

//Frees media and shuts down SDL
    void closeDisplay();

//Getter
    SDL_Renderer* getRenderer();

};


#endif //ANIMATEDGRAPH_DISPLAY_H
