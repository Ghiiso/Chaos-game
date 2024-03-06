#ifndef _FRACTAL_H
#define _FRACTAL_H

/**
 * Creates a new regular shape with specified sides
 * @param sides number of sides
 * @param size distance between center and vertex
 * @param center position of shape center
*/
point_t* createShape(int sides, int size, Vector2 center);

/**
 * returns a new point following the chaos game rule given the list of shape's 
 * vertices and the last used point
*/
point_t getNextPoint(point_t oldPoint, point_t* vertices, int length);

#endif