//
// Created by Max Chartier and Marley Menard
//
// In the functions.h header, we will have all the prototypes of the functions we used, meaning what
// they take as parameters, and we will also have a big part of our project, which corresponds to the
// structures. A structure is basically a new type that we create, that within itself has different
// attributes. We are not going to spend to much times on the functions but we are going to discuss the
// structures.

#ifndef PROJECT_C_FUNCTION_H
#define PROJECT_C_FUNCTION_H


/* this first structure corresponds to the one of the point, it is therefor the easiest, it just has
 * two attributes, which will correspond to the two point of coordinates on both x and y axis.
 */
typedef struct {
    int pos_x;
    int pos_y;
}Point;

/* The second structure, is the line, here again we take two points (their structures) and we use them to
 * have the starting and ending point of the line, both attributes are pointers.
 */
typedef struct {
    Point *p1;
    Point *p2;
}Line;

/* Here for the circle, we will have a radius and a pointer p of type Point, meaning that we will have
 * it's coordinates and we will just consider radius as the radius.
 */
typedef struct {
    Point *p;
    double radius;
} Circle;

/* For the square and the rectangles, we once more have something very similar with 1 point in each case
 * but in one case only the length and in the other both the width and the length, so that we can use them
 * later to create their geometrical shapes
 */

typedef struct{
    Point *p;
    int length;
}Square;

typedef struct {
    Point *p;
    int width;
    int height;
} Rectangle;

/* The structure polygon takes a number of point and an array of points, which makes us after able to
 * go through it and have different locations without needing to directly specify the number of points.
 */
typedef struct {
    int num_points;
    Point **points;
} Polygon;

// Bellow are all the prototypes of the functions, if you pass your mouse on the function it should give
// you a small description
Point *create_point(int px, int py);
Line *create_line(Point * p1, Point * p2);
Circle *create_circle(Point * point, double radius);
Square *create_square(Point * point, int length);
Rectangle *create_rectangle(Point *point, int width, int height);
Polygon* create_polygon(int num_points, Point *points);
void print_point(Point * p);
void print_line(Line * line);
void print_circle(Circle *circle);
void print_square(Square * square);
void print_rect(Rectangle * rectangle);
void print_polygon(Polygon *poly);
void delete_line(Line * line);
void delete_point(Point * point);
void delete_circle(Circle *circle);
void delete_square(Square * square);
void delete_rect(Rectangle * rectangle);
void delete_polygon(Polygon *polygon);
typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;

/* The structure shape takes an ID that will give each shape an unique identifier, and takes a shape type
 * that will correspond to one of the geometric forms we have creates and the last attribute it has
 * corresponds to the shape we want
 */
typedef struct shape {
    int id;
    SHAPE_TYPE shape_type;
    void *ptrShape;
}Shape;

Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_polygon_shape(int lst[], int n);



struct pixel {
    int px;
    int py;
};
typedef struct pixel Pixel;

void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);



#endif //PROJECT_C_FUNCTION_H
