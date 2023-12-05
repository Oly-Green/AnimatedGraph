#include <iostream>
#include <SDL.h>
#include "Display.h"
#include "Loop.h"

int main() {
    Display display(640, 480);
    Loop loop;
    loop.start(display);
    return 0;
}
