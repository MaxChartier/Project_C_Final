//
// Created by Max Chartier and Marley Menard
//
// This file corresponds to the area.c file, it will be the place in which we will create all the functions
// linked to the creation of a space and the drawing inside of it
#include <malloc.h>
#include <stdio.h>
#include "area.h"


/* This will be the first structure we will create, it will simply create a zone of type area and will
 * of course create space for it using malloc it will take in parameters the width and the height of
 * the area we want to create
 */
Area* create_area(unsigned int width, unsigned int height)
{
    Area *area = (Area *) malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->nb_shape = 0;
    return area;
}

/* The void add shape to area is a function that simply adds a shape to the area, meaning that the
 * array of shapes, will become bigger, with a new shape added to it, that is given in parameter,
 * we also need to implement the number of shapes.
 */
void add_shape_to_area(Area* area, Shape* shape) {
    area->shapes[area->nb_shape] = shape;
    area->nb_shape++;
}

/* The clear function will simply take an area as parameter and will transform the matrix into a matrix
 * full of 0.
 */
void clear_area(Area* area){
    for (int i = 0; i<area->width;i++){
        for (int j = 0; j<area->height;j++){
            area->mat[i][j]=0;
        }
    }
}
/* uses the function clear area, but also frees the dynamic allocation we created and finally resets the
 * counter of the number of shapes in the area
 */
void erase_area(Area* area){
    clear_area(area);
    free(area->shapes);
    area->nb_shape = 0;
}

/* Combines the two functions above
 */
void delete_area(Area* area){
    erase_area(area);
}

/* Function that we created to draw the shape into the area
 */
void draw_area(Area* area) {
    return;
}

/* This function print area will take as a parameter an area, and will print each of the cells in the
 * 2d array, meaning that it will display something on the screen
 */
void print_area(Area* area){
    for (int i=0;i<area->width;i++){
        for(int j=0;j<area->height;j++){
            if (area->mat[i][j])
                printf("%d    ", area->mat[i][j]);
        }
        printf("\n");
    }
}


