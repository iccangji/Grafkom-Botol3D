#define WIN32_LEAN_AND_MEAN


#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#include <gl\freeglut.h>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include<mmsystem.h>


/* Global variables */
char title[] = "Objek Botol 3D";
GLfloat anglePyramid = 0.0f;
GLfloat glrotate = 0.0f;
int refreshMills = 15;


void initGL()
{

	glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(300, 100); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    initGL();                       // Our own OpenGL initialization
    glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
