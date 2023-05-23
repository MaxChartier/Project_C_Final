//
// Created by Max Chartier on 23/05/2023.
//

#ifndef PROJECT_C_AREA_H
#define PROJECT_C_AREA_H

#include "Functions.h"



#define SHAPE_MAX 100 // Maximum number of shapes
#define BOOL int

struct area {
    unsigned int width; // Number of pixels in width or number of columns (y-axis)
    unsigned int height; // Number of pixels in height or number of lines (x axis)
    BOOL** mat; // pixel size matrix (width * height)
    Shape* shapes[SHAPE_MAX]; // array of shapes
    int nb_shape; // number of shapes in the shapes array (logical size)
};
typedef struct area Area;

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(struct area* Area, Shape* shape);
void print_area(Area* area);
void draw_area(Area* area);
void delete_area(Area* area);
void erase_area(Area* area);
void clear_area(Area* area);
void add_shape_to_area(Area* area, Shape* shape);
#endif //PROJECT_C_AREA_H
