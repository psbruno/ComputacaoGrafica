#include <stdio.h>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
# define PI 3.141592654
float tx = 0.0;
float ty = 0.0;
int n = 10;
float ang = 0;
int lado = 1;

void display_function()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Considerando um quadrado cujos vértices possuem as coordenadas
    // x1 = -0.25 y1 = 0.25
    // x2 = 0.25  y2 = 0.25
    // x3 = 0.25  y3 = -0.25
    // x4 = -0.25 y4 = -0.25

    //Lembrando que para a translação por (tx,ty)
    // x' = x + tx
    // y' = y + ty
    int i;
    float angulo;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
     glColor3f(0.0,1.0, 0.0);
         for(i=0;i<180;i++){
            glVertex2f(0.4*cos(ang)+0.5,0.4*sin(ang));
            ang = ang+(2*M_PI)/n;
        }

    glEnd();
    glBegin(GL_POLYGON);
     glColor3f(0.0,1.0, 0.0);
         for(i=0;i<180;i++){
            glVertex2f(0.4*cos(ang),0.4*sin(ang)-0.5);
            ang = ang+(2*M_PI)/n;
        }

    glEnd();
      glBegin(GL_POLYGON);
     glColor3f(0.0,1.0, 0.0);
         for(i=0;i<180;i++){
            glVertex2f(0.4*cos(ang),0.4*sin(ang)+0.5);
            ang = ang+(2*M_PI)/n;
        }

    glEnd();
      glBegin(GL_POLYGON);
     glColor3f(0.0,1.0, 0.0);
         for(i=0;i<180;i++){
            glVertex2f(0.4*cos(ang)-0.5,0.4*sin(ang));
            ang = ang+(2*M_PI)/n;
        }

    glEnd();
    glBegin(GL_POLYGON);
     glColor3f(1.0,1.0, 1.0);
         for(i=0;i<180;i++){
            glVertex2f(0.4*cos(ang)+0.35,0.4*sin(ang)+0.35);
            ang = ang+(2*M_PI)/n;
        }

    glEnd();

     glBegin(GL_POLYGON);
     glColor3f(1.0,0.0, 0.0);
         for(i=0;i<180;i++){
            glVertex2f(0.4*cos(ang)+0.35,0.4*sin(ang)-0.35);
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
     glBegin(GL_POLYGON);
     glColor3f(1.0,0.0, 0.0);
         for(i=0;i<180;i++){
            glVertex2f(0.4*cos(ang)-0.35,0.4*sin(ang)+0.35);
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
     glBegin(GL_POLYGON);
     glColor3f(1.0,1.0, 1.0);
         for(i=0;i<180;i++){
            glVertex2f(0.4*cos(ang)-0.35,0.4*sin(ang)-0.35);
            ang = ang+(2*M_PI)/n;
        }
    glEnd();

    glBegin(GL_POLYGON);
     glColor3f(1.0,1.0, 0.0);
        for(i=0;i<180;i++){
            glVertex2f(0.25*cos(ang),0.25*sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();



    glRotatef(20.0f*lado, 0.0f, 0.0f, 1.0f);
    glFlush();
}

void tecladoEspecial(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
        case GLUT_KEY_UP:
            lado=-1;
            break;
        case GLUT_KEY_LEFT:
        case GLUT_KEY_DOWN:
            lado=1;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0,1.0,1.0);
}

int main(int argc, char **argv)
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutInit(&argc, argv);
    glutCreateWindow("Flor");
    //init();
    glutDisplayFunc(display_function);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop ();
    return 0;
}
