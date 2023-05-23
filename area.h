//
// Created by Max Chartier on 23/05/2023.
//
// This file corresponds to the head filler of the area.c file, meaning it contains all the prototypes
// of the functions and the structure used for the area part.

#ifndef PROJECT_C_AREA_H
#define PROJECT_C_AREA_H



#include "Functions.h"


// Here we have defined the SHAPE_MAX, that corresponds to the maximum size of the array we have bellow
// and BOOL will simply be a matrix in which we will put pixels in the future
#define SHAPE_MAX 100
#define BOOL int

/* The struct area is really important cause it is, obviously the starting point of all the drawings
 * it has 3 ints as attributes, with the number of shapes, already discussed and the width and the height
 * for the matrix. The bool will like we said above correspond to the matrix of pixel and the Shape array
 * will be containing all the different shapes we put into it.
 */
struct area {
    unsigned int width;
    unsigned int height;
    BOOL** mat;
    Shape* shapes[SHAPE_MAX];
    int nb_shape;
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
