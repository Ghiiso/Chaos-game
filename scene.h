#ifndef _SCENE_H
#define _SCENE_H

typedef struct scene {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    struct camera{
        Vector2 position;
        float angle;
    }camera;
    uint32_t pixels[SCREEN_WIDTH*SCREEN_HEIGHT];
    void (*init)(struct scene*);
    int exit;
}scene_t;

/**
 * Initialise this scene by adding parameters to all struct fields
*/
void initScene(scene_t* this);

/**
 * Converts the passed Vector2 in 1 dimensional coordinates of scene
*/
int vectorToSceneCoords(Vector2 v);

/**
 * Draws a point inside specified scene 
*/
void drawPoint(scene_t* scene, point_t point);

#endif