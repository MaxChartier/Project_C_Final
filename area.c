//
// Created by Max Chartier on 23/05/2023.
//
//
// Created by Max Chartier on 23/05/2023.
//
#include <malloc.h>
#include <stdio.h>
#include "area.h"



Area* create_area(unsigned int width, unsigned int height)
{
    int i = 0, j = 0;
    Area *area = (Area *) malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->nb_shape = 0;
    return area;
}

void add_shape_to_area(Area* area, Shape* shape) {
    area->shapes[area->nb_shape] = shape;
    area->nb_shape++;
}

void clear_area(Area* area){
    for (int i = 0; i<area->width;i++){
        for (int j = 0; j<area->height;j++){
            area->mat[i][j]=0;
        }
    }
}

void erase_area(Area* area){
    clear_area(area);
    free(area->shapes);
    area->nb_shape = 0;
}

void delete_area(Area* area){
    erase_area(area);
}

void draw_area(Area* area) {
    return;
}

void print_area(Area* area){
    for (int i=0;i<area->width;i++){
        for(int j=0;j<area->height;j++){
            if (area->mat[i][j])
                printf("%d", area->mat[i][j]);
        }
        printf("\n");
    }
}

struct pixel {
    int px;
    int py;
};
typedef struct pixel Pixel;

Pixel* create_pixel(int px, int py) {
    Pixel* new_pixel = (Pixel*)malloc(sizeof(Pixel));
    new_pixel->px = px;
    new_pixel->py = py;
    return new_pixel;
}

void delete_pixel(Pixel* pixel) {
    free(pixel);
}
