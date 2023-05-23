//
// Created by Max Chartier on 12/05/2023.
//

#ifndef PROJECT_C_FUNCTION_H

//
// Created by Max Chartier on 23/04/2023.
//

#define PROJECT_C_FUNCTION_H



typedef struct {
    int pos_x;
    int pos_y;
}Point;

typedef struct {
    Point *p1;
    Point *p2;
}Line;

typedef struct {
    Point *p;
    double radius;
} Circle;

typedef struct{
    Point *p;
    int i;
}Square;

typedef struct {
    Point *p;
    int width;
    int height;
} Rectangle;

typedef struct {
    int num_points;
    Point *points;
} Polygon;

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



#endif //PROJECT_C_FUNCTION_H
