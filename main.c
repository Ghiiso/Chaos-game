#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h> 
#include <time.h>
#include "constants.h"
#include "Vector2.h"
#include "types.h"
#include "scene.h"
#include "fractal.h"

int main(void) {
    scene_t scene;
    point_t center = (point_t) {(Vector2) {SCREEN_WIDTH/2,SCREEN_HEIGHT/2}, 0xFFFFFF};
    point_t lastPoint = center;
    point_t* shape = createShape(SIDES, SIZE, center.position);

    
    if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) printf("Error during initialization: %s",SDL_GetError());
    initScene(&scene);
    srand(time(NULL));
    
    // main loop
    while(!scene.exit) {
        const Uint8* keyboard = SDL_GetKeyboardState(NULL);
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0) { // event handler
            switch (event.type) {
                case SDL_QUIT:
                    scene.exit = 1;
                    break;
                default:
                    break;
            }
        }
        if(keyboard[SDL_SCANCODE_ESCAPE]) scene.exit = 1;

        for(int i = 0; i < SIDES; i++) {
            drawPoint(&scene, shape[i]);
        }

        drawPoint(&scene, lastPoint);
        lastPoint = getNextPoint(lastPoint, shape, SIDES);

        SDL_UpdateTexture(scene.texture,NULL,scene.pixels,SCREEN_WIDTH*4);
        SDL_RenderCopyEx(scene.renderer,scene.texture,NULL,NULL,0,NULL,SDL_FLIP_VERTICAL);
        SDL_RenderPresent(scene.renderer);
    }
    return 0;
}
