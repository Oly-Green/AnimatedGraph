//
// Created by olive on 12/5/2023.
//

#ifndef ANIMATEDGRAPH_LOOP_H
#define ANIMATEDGRAPH_LOOP_H
#include <SDL.h>
#include "Display.h"

class Loop {
private:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    bool quit = false;
    SDL_Event event;

public:
    void start(Display display);
};


#endif //ANIMATEDGRAPH_LOOP_H
