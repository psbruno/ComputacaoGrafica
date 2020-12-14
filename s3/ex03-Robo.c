#include <stdio.h>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
# define PI 3.141592654
float tx =0.0;
float ty = 0.0;
int n = 10;
float ang = 0;
int lado = 1;
float r=0.0,g=0.0,b=0.0;

void display_function()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
        glColor3f(0.75,0.75,0.75);
        glVertex2f(-0.1,0.4);
        glVertex2f(0.1,0.4);
        glVertex2f(0.1,-0.2);
        glVertex2f(-0.1,-0.2);
    glEnd();



    glBegin(GL_POLYGON);
        glColor3f(0.4,0.4,0.4);
        glVertex2f(-0.1,-0.2);
        glVertex2f(-0.05,-0.2);
        glVertex2f(-0.05,-0.8);
        glVertex2f(-0.1,-0.8);
    glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.4,0.4,0.4);
        glVertex2f(0.1,-0.2);
        glVertex2f(0.05,-0.2);
        glVertex2f(0.05,-0.8);
        glVertex2f(0.1,-0.8);
    glEnd();

     glBegin(GL_POLYGON);
     //braco direito
     glColor3f(0.4,0.4,0.4);
        glVertex2f(0.1,0.3);
        glVertex2f(0.35+tx/2,0.2+ty/2);
        glVertex2f(0.35+tx/2,0.1+ty/2);
        glVertex2f(0.1,0.2);
    glEnd();


     glBegin(GL_POLYGON);
        glColor3f(0.6,0.2,0.6);
        glVertex2f(0.05,-0.2);
        glVertex2f(-0.05,-0.2);
        glVertex2f(0.0+tx,-0.8+tx);
    glEnd();


    glBegin(GL_POLYGON);
    //braco esquerdo
     glColor3f(0.4,0.4,0.4);
        glVertex2f(-0.1,0.3);
        glVertex2f(-0.35+tx/2,0.2+ty/2);
        glVertex2f(-0.35+tx/2,0.1+ty/2);
        glVertex2f(-0.1,0.2);
    glEnd();
     glBegin(GL_POLYGON);
        glColor3f(0.4,0.4,0.4);
        glVertex2f(-0.07,0.6);
        glVertex2f(0.07,0.6);
        glVertex2f(0.07,0.4);
        glVertex2f(-0.07,0.4);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(0.05, 0.45);
        glVertex2f(-0.05, 0.45);
        glVertex2f(0.0, 0.43);
    glEnd();

    glFlush();
}

void tecladoEspecial(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
            tx+=0.5;
            break;
        case GLUT_KEY_LEFT:
            tx-=0.5;
            break;
        case GLUT_KEY_UP:
            ty=0.5;
            break;
        case GLUT_KEY_DOWN:
            ty=-0.5;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutInit(&argc, argv);
    glutCreateWindow("Carro");
    //init();
    glutDisplayFunc(display_function);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop ();
    return 0;
}
