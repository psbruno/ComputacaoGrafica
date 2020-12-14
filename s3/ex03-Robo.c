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
float theta = 0;
float r=0.0,g=0.0,b=0.0;
float sx = 1.0;
float sy = 1.0;

void tronco(){
    glBegin(GL_POLYGON);
        glColor3f(0.75,0.75,0.75);
        //tronco
        glVertex2f(-0.1,0.4);
        glVertex2f(0.1,0.4);
        glVertex2f(0.1,-0.2);
        glVertex2f(-0.1,-0.2);
    glEnd();

}
void pernas(){
        glBegin(GL_POLYGON);
    //perna esquerda
        glColor3f(0.4,0.4,0.4);
        glVertex2f(-0.1,-0.2);
        glVertex2f(-0.05,-0.2);
        glVertex2f(-0.05,-0.8);
        glVertex2f(-0.1,-0.8);
    glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.4,0.4,0.4);
     //perna direita
        glVertex2f(0.1,-0.2);
        glVertex2f(0.05,-0.2);
        glVertex2f(0.05,-0.8);
        glVertex2f(0.1,-0.8);
    glEnd();

}
void bracod(){
      glBegin(GL_POLYGON);
     //braco direito
     glColor3f(0.4,0.4,0.4);
        glVertex2f(0.1,0.3);
        glVertex2f(0.35,0.2);
        glVertex2f(0.35,0.1);
        glVertex2f(0.1,0.2);
    glEnd();

}
void cabeca(){
     glBegin(GL_POLYGON);
    //cabeca
        glColor3f(0.4,0.4,0.4);
        glVertex2f(-0.07,0.6);
        glVertex2f(0.07,0.6);
        glVertex2f(0.07,0.4);
        glVertex2f(-0.07,0.4);
    glEnd();
    glBegin(GL_LINES);
    //boca
        glColor3f(1.0,1.0,1.0);
        glVertex2f(0.05, 0.45);
        glVertex2f(-0.05, 0.45);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-0.04,0.53);
        glVertex2f(-0.02,0.53);
        glVertex2f(-0.02,0.52);
        glVertex2f(-0.04,0.52);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(0.05,0.53);
        glVertex2f(0.03,0.53);
        glVertex2f(0.03,0.52);
        glVertex2f(0.05,0.52);
    glEnd();

}
void bracoe(){


    glBegin(GL_POLYGON);
    //braco esquerdo
     glColor3f(0.4,0.4,0.4);
        glVertex2f(-0.1,0.3);
        glVertex2f(-0.35,0.2);
        glVertex2f(-0.35,0.1);
        glVertex2f(-0.1,0.2);
    glEnd();

}

    void display_function()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);


    tronco();

    glPushMatrix();
        glTranslatef(tx,ty,1.0);
    pernas();
    glPopMatrix();



    glPushMatrix();

    glRotatef(theta*4,0.1,0.25,0.0);
    bracod();
    glPopMatrix();

    glPushMatrix();
        glRotatef(theta*4,-0.1,0.25,0.0);
        bracoe();
    glPopMatrix();

    cabeca();


    glFlush();

}

void tecladoEspecial(int tecla, int x, int y){


    switch (tecla) {
        case GLUT_KEY_UP:
            if(ty<0.6)
                ty+=0.05;
            theta+=5;
            break;
        case GLUT_KEY_DOWN:
            if(ty>0.05)
            ty-=0.05;
            theta-=5;
            break;
        default:
            break;
    }

    printf("%f %f\n",tx,ty );
    glutPostRedisplay();

}

int main(int argc, char **argv)
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutInit(&argc, argv);
    glutCreateWindow("Robo");
    //init();
    glutDisplayFunc(display_function);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop ();
    return 0;
}
