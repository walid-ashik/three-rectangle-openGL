/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
//#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init()
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glOrtho(-10,10,-10,10,-10,10);
}

void displayRed(){
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
        glVertex3d(6.0,6.0,0.0);
        glVertex3d(6.0,2.0,0.0);
        glVertex3d(2.0,2.0,0.0);
        glVertex3f(2.0,6.0,0.0);
    glEnd();
}

void displayYellow(){
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
        glVertex3d(4.0,4.0,0.0);
        glVertex3d(4.0,-4.0,0.0);
        glVertex3d(-4.0,-4.0,0.0);
        glVertex3f(-4.0,4.0,0.0);
    glEnd();
}

void displayGreen(){

    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
        glVertex3d(0.0,0.0,0.0);
        glVertex3d(0.0,-7.0,0.0);
        glVertex3d(-7.0,-7.0,0.0);
        glVertex3f(-7.0,0.0,0.0);
    glEnd();
}

void drawLinesBetweenRedAndYellow(){
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3d(4.0,4.0,0.0);
        glVertex3d(6.0,6.0,0.0);
    glEnd();
}

void drawLinesBetweenYellowAndGreen(){

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3d(4.0,4.0,0.0);
        glVertex3d(-7.0,-7.0,0.0);
    glEnd();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    displayRed();
    displayYellow();
    displayGreen();
    drawLinesBetweenRedAndYellow();
    drawLinesBetweenYellowAndGreen();

    glFlush();
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(400,200);
    glutCreateWindow("DEMO");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
