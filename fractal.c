#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "Vector2.h"
#include "types.h"
#include "constants.h"
#include "fractal.h"

point_t createPoint(int x, int y, int color) {
    return (point_t) {x, y, color};
}

point_t getRandomVertex(point_t* vertices, int length) {
    return vertices[rand() % length];
}

point_t* createShape(int sides, int size, Vector2 center) {
    int sideColors[] = {RED, GREEN, YELLOW, LBLUE, FUCHSIA, BLUE, RED, GREEN, YELLOW, LBLUE, FUCHSIA, BLUE}; // lenght must equal the number of sides


    if(sizeof(sideColors) / sizeof(int) < sides) {
        printf("sideColors array inside constant.h is too short!\n");
        exit(1);
    }
    double angle = (PI*2 / (double) sides);
    point_t* result = (point_t*) malloc((size_t) sizeof(point_t)*sides);
    double rotation = 0;

    for(int vertex=0; vertex < sides; vertex++) {
        rotation = angle * (double) vertex + PIhalf;
        result[vertex] = (point_t) createPoint( center.x + (int) (size * cos(rotation)), 
                                                center.y + (int) (size * sin(rotation)),
                                                sideColors[vertex]
                                    );
    }
    return result;
}

point_t getNextPoint(point_t oldPoint, point_t* vertices, int length) {
    point_t vertex = getRandomVertex(vertices, length);
    Vector2 distance = sub(vertex.position, oldPoint.position);
    distance = add(dot(distance, RATIO), oldPoint.position);
    return createPoint(distance.x, distance.y, vertex.color);
}