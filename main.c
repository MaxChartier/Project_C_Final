// This will be the main function, in which we can find the use of the different functions in a loop
// that will make everything work together. We start by including the different files, starting with
// functions header which contains all the definition of the functions and the structures used in this
// program. After that we include the area header which contain all the code part for the creation of the
//area and the drawing inside of it. We will have a big loop that countains all the different parts of
// our code meaning the add a shape, the display the list of shape, etc.

#include <stdio.h>
#include <malloc.h>
#include "Functions.h"
#include "area.h"

unsigned int global_ID = 0;

int main() {
    Area* draw_zone = create_area(12, 14);
    Shape* shape1 = create_line_shape(5, 5 , 10, 10);
    add_shape_to_area (draw_zone, shape1);
    print_area (draw_zone);
    // Here we defined the different variables used in the main, the choice and choice2 are going to be
    // used so that the user can make a choice between the options, if he writes 'P' at any moment, he
    // will stop the program.
    int nb_shape;
    char choice;
    int choice2;
    int run = 1;
    while (run=1){
        printf("Please select an action:\n"
               "A- Add a shape\n"
               "B- Display the list of shapes\n"
               "C- Delete a shape\n"
               "D- Drawing the shapes\n"
               "E- Help\n"
               "P- To exit\n");
        scanf("%c",&choice);
        if (choice=='P' || choice2=='P'){
            break;
        }
        if (choice=='A'){
     // here we have the second choice that allows the user to choose between the different geometrical
     // shapes
            printf("Please select an action:\n"
                   "1- Add a point\n"
                   "2- Add a line\n"
                   "3- Add circle\n"
                   "4- Add a square\n"
                   "5- Add a rectangle\n"
                   "6- Add a polygon\n"
                   "7- Return to previous menu\n");
            scanf("%d",&choice2);
            if (choice2==1){
                //using the function we created, we here ask for the coordinates and then we proceed
                // to create the point after which we add 1 to the number of SHAPE.
                int x,y;
                printf("Give the coordinates in the form x y");
                scanf("%d %d",&x,&y);
                Point *Point1 = create_point(x,y);
                // use of the function print_point that will display the coordinates chose by the user
                print_point(Point1);
                // use of the function create_point_shape, that will create an empty shape then adds
                // the point coordinates to it.
                create_point_shape(x,y);
                printf("%d",global_ID);
                nb_shape+=1;
            }
            if (choice2==2){
                int x1, y1, x2, y2;
                //using the functions create point and create line , we here ask for the
                // coordinates and then we proceed to use both functions to create the line.
                printf("Enter the x and y coordinates for the start point:\n");
                scanf("%d %d", &x1, &y1);
                Point *p1 = create_point(x1, y1);
                //creation of the first point using the create_point function
                printf("Enter the x and y coordinates for the end point:\n");
                scanf("%d %d", &x2, &y2);
                Point *p2 = create_point(x2, y2);
                //creation of the second point using the same function
                Line *line = create_line(p1, p2);
                //printing the coordinates of the line with the function print_line
                print_line(line);
                nb_shape+=1;
            }
            if (choice2==3){
                //here, since we need to create a cirlce, we need to define 3 variables, the coordinates
                //of the center of the circle, and it's radius
                int x5,y5;
                double rad;
                printf("Enter the x and y coordinates for the center of your circle:\n");
                scanf("%d %d", &x5, &y5);

                printf("Now choose a radius for your circle:\n");
                scanf("%d",&rad);
                //Since it's a circle we need to first create a point
                Point *point = create_point(x5,y5);
                // Then using the point and the radius as parameters, we create the circle
                Circle *circle = create_circle(point,rad);
                // We then display the result on the screen
                print_circle(circle);
                nb_shape+=1;
            }
            if (choice2==4){
                int x3,y3,length;
                // The choice 4 corresponds to a square, which was not the hardest form to create,
                // since we only have to take coordinates of a point, and then ask for a length
                printf("Enter the x and y coordinates of your top left point:\n");
                scanf("%d %d",&x3,&y3);

                printf("Now enter the length of the square\n ");
                scanf("%d",&length);
                // After that we create the point around which we create the square, they will all be
                // length distant from the point we initialized
                Point *point = create_point(x3,y3);
                Square *square = create_square(point,length);
                // We can now create our square and display it on the screen
                print_square(square);
                nb_shape+=1;

            }
            if (choice2 == 5){
                int x4,y4,height,width;
                // The rectangle works pretty much in the same way as the square, but we will need to
                // have 2 variables, height and width
                printf("Enter the x and y coordinates of your top left point:\n");
                scanf("%d %d",&x4,&y4);
                printf("Now enter the width of the square\n");
                scanf("%d",&width);
                printf("Now enter the height of the square\n");
                scanf("%d",&height);
                // We create the point like we did for the square, then we use the create_rectangle
                // function with the point, the width and the height as parameters
                Point *point = create_point(x4,y4);
                Rectangle *rectangle = create_rectangle(point,width,height);
                // We can now print the coordinates of our rectangle
                print_rect(rectangle);
                nb_shape+=1;
            }
            if (choice2==6){
                // The polygon was the hardest form to create, since it takes a different number of points
                //depending on the call, we have created the numb variable that will be an int.
                int numb;
                printf("Enter the number of points in the polygon: ");
                scanf("%d", &numb);
                // We ask the user for the number of points in his polygon
                Point * points = malloc(numb * sizeof(Point));
                // Here we create the space needed to save the points we will need
                for (int i = 0; i < numb; i++) {
                    int x, y;
                    printf("Enter the x and y coordinates of point %d: ", i+1);
                    scanf("%d %d", &x, &y);
                    points[i] = *create_point(x, y);
                }
                //The loop above makes it possible to have a different number of points everytime we call
                //the function, in fact it will be a loop creating a number of point, from 0 to numb.
                Polygon *polygon = create_polygon(numb, points);
                // We can now call the function polygon that will create taking as parameters the numb and
                // points that will correspond to a array of points
                print_polygon(polygon);
                // We print the polygon points one by one
                nb_shape+=1;
            }
            if (choice=='B'){
                //The choice B will correspond to the number of shape present in the memory.
                printf("The number of shape is : %d",nb_shape);
            }
            if (choice=='E'){
                printf("Hello!\n Welcome to our Vector Text-Based Editor!\n Here you can create "
                       "any geometric shape you want, the square, the line ,the point or even any polygon you would dream of!"
                       "\nTo do that you need to press A then you will have the menu of shapes you can create with"
                       "the coordinates you need to enter\n If you want to have access to the number of shapes you have created"
                       " press B!\n");
            }
        }}
    return 0;
}



