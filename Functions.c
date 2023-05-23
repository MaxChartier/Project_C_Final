//
// Created by Max Chartier and Marley Menard
//

// Functions.c will be the file, in which we will store all the functions and define them.
// The first ones will always work in the same way, meaning that we will have : the function create
// that will creates the coordinates of the points, then the function print, that will take those coordinates
// and display them on the screen, followed by the function delete, that frees the space taken by the points
// the last and probably most important function is the shape one, that will associate to the coordinates
// a shape.

#include <stdio.h>
#include <malloc.h>
#include "Functions.h"

// The global_id global variable gives to a shape a unique identifier
unsigned int global_id = 0;
unsigned int get_next_id();

// We start with the creating functions that work in a pretty simple way, it allocates the space
// with the function malloc creating space for a point, then we access the pos_x and pos_y and we give
// them values
Point *create_point(int px, int py) {
    Point *p = malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;
    return p;
}

// The create point is a function that we are going to use for everything, in fact we need a point to
// create any geometric figure, in the case of the line, we will need 2 points, the starting, and the
// ending point. We also need to allocate more space, therefor we will allocate space of the size of
// the line
Line *create_line(Point * p1, Point * p2) {
    Line *line = malloc(sizeof(Line));
    line->p1 = create_point(p1->pos_x, p1->pos_y);
    line->p2 = create_point(p2->pos_x, p2->pos_y);
    return line;
}

// For the circle we will simply create a point, to which we will give coordinates in the main, the we
// will take the double radius, the will correspond to the radius and we will create the shape around
// the point.
Circle *create_circle(Point * point, double radius){
    Circle *circle = malloc(sizeof(Circle));
    circle->p = create_point(point->pos_x,point->pos_y);
    circle->radius = radius;
    return circle;
}

/*
 *The create square works in the same way as the create rectangle, we will have one or two variables
 that will be used for the length of the square/rectangle then, we allocate the space for the geometric
 form and then we return the square.
 */
Square *create_square(Point * point, int length){
    Square *square = malloc(sizeof(Square));
    square->p = create_point(point->pos_x, point->pos_y);
    square->length = length;
    return square;
}

Rectangle *create_rectangle(Point *point, int width, int height) {
    Rectangle *rectangle = malloc(sizeof(Rectangle));
    rectangle->p = create_point(point->pos_x,point->pos_y);
    rectangle->width = width;
    rectangle->height = height;
    return rectangle;
}

/*
 *
 * The polygon once again is the hardest one to create, cause it takes an array of points as a parameter
   which means it needs to have a creation of points that is repeatable, meaning that we will need to
   have a loop, in which the positions will be assigned to the point after which we will return the polygon
   */
Polygon* create_polygon(int num_points, Point *points) {
    Polygon *polygon = malloc(sizeof(Polygon));
    polygon->num_points = num_points;
    polygon->points = malloc(num_points * sizeof(Point));
    for (int i = 0; i < num_points; i++) {
        polygon->points[i]->pos_x = points[i].pos_x;
        polygon->points[i]->pos_y = points[i].pos_y;
    }
    return polygon;
}


// All the print functions are working in a simple way, we will dynamicaly access the values of the
// points (their coordinates) and then we are going to print them in the needed way.
void print_point(Point * p){
    printf("POINT[p(%d,%d)]",p->pos_x,p->pos_y);
}

void print_line(Line * line){
    printf("LINE start:[%d,%d] end:[%d,%d]",line->p1->pos_x,line->p1->pos_y,line->p2->pos_x,line->p2->pos_y);
}

void print_circle(Circle *circle){
    printf("CIRCLE of center (%d,%d) and radius %d",circle->p->pos_x,circle->p->pos_y,circle->radius);
}

void print_square(Square * square){
    printf("Square (%d, %d) of length (%d)", square->p->pos_x, square->p->pos_y,square->length);
}

void print_rect(Rectangle * rectangle){
    printf("Rectangle (%d,%d) of height %d and width %d", rectangle->p->pos_x,rectangle->p->pos_y,rectangle->height,rectangle->width);
}

// The print polygon once again uses a loop, that will display the points one by one, we will re use
// the format of the point printing.
void print_polygon(Polygon *poly) {
    printf("Polygon with %d points:\n", poly->num_points);
    for (int i = 0; i < poly->num_points; i++) {
        printf("Point %d: (%d, %d)\n", i+1, poly->points[i]->pos_x, poly->points[i]->pos_y);
    }
}

// All the delete functions will work in the same way, they will free the space that was allocated
// in the create function.
void delete_line(Line * line){
    free(line);}

void delete_point(Point * point){
    free(point);
}

void delete_circle(Circle *circle){
    free(circle);
}

void delete_square(Square * square){
    free(square);
}

void delete_rect(Rectangle * rectangle){
    free(rectangle);
}

void delete_polygon(Polygon *polygon){
    free(polygon);
}


// The second part off the functions will create what we call the shapes, they will be particularly
// useful cause they will be used for the drawing and for the display.

/* The function create_empty_shape will be used as a base for all the other shapes,
 * it will create a space for the shape, that will be initialized to NULL, after that it will say that
 * the attribute of shp shape_type will be equal to the shape type given in parameter, which makes
 * it usable for all the other shapes, the id will be the one for the first shape, therefor 1, after
 * that we will return shp.
 */
Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = 1;
    shp->shape_type = shape_type;
    return shp;
}

/* Like we mentioned earlier, we use the create_empty_shape, but we call the function with a value
 * in this case, POINT, we will add 1 to the global id, so that it has a unique number that corresponds
 * to the shape created, we will create the point, add the point in the shape and return the shp.
 */
Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    global_id+=1;
    return shp;
}

/* For the create line we do the same as for the create_point_shape meaning that we will pass by
 * the two points, then we will create the line, afer which we will give shp the shape of p in this case
 * the line
 */
Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1,py1);
    Point *p2 = create_point(px2,py2);
    Line *p = create_line(p1,p2);
    shp->ptrShape = p;
    global_id+=1;
    return shp;
}

/* For the create square we do the same as for the create_point_shape meaning that we will pass by
 * the point, then we will create the square, afer which we will give shp the shape of p in this case
 * the square
 */
Shape *create_square_shape(int px, int py, int length){
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px,py);
    Square *square = create_square(p,length);
    shp->ptrShape = square;
    global_id+=1;
    return shp;
}

/* For the create rectangle we do the same as for the create_point_shape meaning that we will pass by
 * the point, then we will create the rectangle, afer which we will give shp the shape of p in this case
 * the rectangle
 */
Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px,py);
    Rectangle *rectangle = create_rectangle(p, width, height);
    shp->ptrShape = rectangle;
    global_id +=1;
    return shp;
}

Shape *create_polygon_shape(int lst[], int n){
}

/* the pixel create_pixel function is a function we didn't use in our project ,it is ussefull for
 * the allocation of memory space of type pixel, to initialize it and returns the adress of this
 * memory.
 */
Pixel* create_pixel(int px, int py) {
    Pixel* new_pixel = (Pixel*)malloc(sizeof(Pixel));
    new_pixel->px = px;
    new_pixel->py = py;
    return new_pixel;
}

//This functions just deletes the memory allocated to the pixel.
void delete_pixel(Pixel* pixel) {
    free(pixel);
}

//This function is supposed to give you the position of the point that will be created in the array
// of pixel
void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels)
{
    Point* pt = (Point*) shape->ptrShape;
    *pixel_tab = (Pixel**) malloc (sizeof (Pixel*));
    *pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels = 1;
}
