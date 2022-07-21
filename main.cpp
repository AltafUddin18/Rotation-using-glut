#include<windows.h>
#include <GL/glut.h>


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);	// Set display window colour to white

    glMatrixMode(GL_PROJECTION);		// Set projection parameters
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void drawShapes(void)
{
    float point_one[]= {50,150};
    float point_two[]= {150,150};
    float point_three[]= {100,300};

    float scaling_factor_x =2;
    float scaling_factor_y =2;

    float transform_factor_x=60;
    float transform_factor_y=-50;

    glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

    //Set colour to black

    glColor3f(0.0, 0.0, 0.0);
    //Adjust the point size
    glPointSize(10.0);

    // Draw a couple of points

    //Set colour to white
    glColor3f(1.0, 1.0, 1.0);

    // Draw a line
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,0,0);
    glVertex2i(point_one[0], point_one[1]); //corner line
    glVertex2i(point_two[0], point_two[1]); //corner line
    glVertex2i(point_three[0], point_three[1]);  //corner line
    glEnd();


    float new_point_one1[]= {point_one[0]+transform_factor_x, point_one[1]+ transform_factor_y};
    float new_point_two1[]= {point_two[0]+transform_factor_x, point_two[1]+ transform_factor_y};
    float new_point_three1[]= {point_three[0]+transform_factor_x, point_three[1]+transform_factor_y};

    float new_point_one[]= {new_point_one1[0]*scaling_factor_x, new_point_one1[1]*scaling_factor_y};
    float new_point_two[]= {new_point_two1[0]*scaling_factor_x, new_point_two1[1]*scaling_factor_y};
    float new_point_three[]= {new_point_three1[0]*scaling_factor_x, new_point_three1[1]*scaling_factor_y};

    glColor3f(1.0, 1.0, 1.0);


    // Draw a line
    glColor3f(0,1.0,0);
    glRotatef (-20.0, 0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(new_point_one[0], new_point_one[1]); //corner line
    glVertex2i(new_point_two[0], new_point_two[1]); //corner line
    glVertex2i(new_point_three[0], new_point_three[1]);  //corner line


    glEnd();
    glFlush();	// Process all OpenGL routines
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);						// Initalise GLUT
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	// Set display mode

    glutInitWindowPosition(100, 100);				// Set window position
    glutInitWindowSize(700, 400);					// Set window size
    glutCreateWindow("193001412-Altaf Uddin");	// Create display window

    init();							// Execute initialisation procedure
    glutDisplayFunc(drawShapes);		// Send graphics to display window
    glutMainLoop();					// Display everything and wait

    return 0;
}
