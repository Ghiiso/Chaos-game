#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h> 
#include "constants.h"
#include "Vector2.h"
#include "types.h"
#include "fractal.h"
#include "scene.h"

void initScene(scene_t* this) {
    this->window = SDL_CreateWindow (
                        "window",
                        SDL_WINDOWPOS_CENTERED,
                        SDL_WINDOWPOS_CENTERED,
                        SCREEN_WIDTH,
                        SCREEN_HEIGHT,
                        0
                    );
    this->renderer = SDL_CreateRenderer (
                        this->window,
                        -1,
                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
                    );
    this->texture = SDL_CreateTexture (
                        this->renderer,
                        SDL_PIXELFORMAT_ABGR8888,
                        SDL_TEXTUREACCESS_STREAMING,
                        SCREEN_WIDTH,
                        SCREEN_HEIGHT
                    );
    this->camera.position = (Vector2) {0,0}; 
    this->camera.angle = 0;
    this->exit = 0;
}

int vectorToSceneCoords(Vector2 v) {
    return ((SCREEN_WIDTH * v.y) + v.x) % (SCREEN_WIDTH*SCREEN_HEIGHT);
}

void drawPoint(scene_t* scene, point_t point) {
    scene->pixels[vectorToSceneCoords(point.position)] = point.color;
}
