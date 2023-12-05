//
// Created by olive on 12/5/2023.
//

#include "Loop.h"

void Loop::start(Display display) {
    if( !display.init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else {
        int animationRate = 6;
        int animationLength = 4;
        int startTime = SDL_GetTicks();
        int frame = 0;
        //Game Loop
        while (!quit) {
            SDL_SetRenderDrawColor(display.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(display.getRenderer());
            SDL_RenderPresent(display.getRenderer());
            frame = ((SDL_GetTicks() - startTime) * animationRate / 1000) % animationLength;
            SDL_RenderPresent(display.getRenderer());

            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
            }
        }
    }
    display.closeDisplay();
}
