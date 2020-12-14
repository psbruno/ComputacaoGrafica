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
float theta = 0.0;
float r=0.0,g=0.0,b=0.0;
void rodaT(){
    glTranslatef(-0.25,-0.17,0.0);
    glRotatef(theta,-0.3,-0.17,1.0);
    glBegin(GL_POLYGON);
     glColor3f(r,g, b);
         for(int i=0;i<10;i++){
            glVertex2f(0.1*cos(ang),0.1*sin(ang));
            ang = ang+(2*M_PI)/10;
        }

    glEnd();


}
void rodaD(){
    glTranslatef(+0.25,-0.17,0.0);
    glRotatef(theta,-0.3,-0.17,1.0);
    glBegin(GL_POLYGON);
     glColor3f(r,g, b);
         for(int i=0;i<10;i++){
            glVertex2f(0.1*cos(ang),0.1*sin(ang));
            ang = ang+(2*M_PI)/10;
        }

    glEnd();


}
void carro(){
    glBegin(GL_POLYGON);
    //corpo do carro
    glColor3f(0.75,0.75,0.75);

        glVertex2f(-0.4,0.0);
        glVertex2f(0.4,0.0);
        glVertex2f(0.4,-0.2);
        glVertex2f(-0.4,-0.2);
    glEnd();

}
void vidro(){

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.78,1.0);
        glVertex2f(-0.3,0.0);
        glVertex2f(-0.2,0.0);
        glVertex2f(-0.2,0.2);
    glEnd();

    glBegin(GL_POLYGON);
     glColor3f(0.0,0.78,1.0);
        glVertex2f(-0.2,0.2);
        glVertex2f(0.2,0.2);
        glVertex2f(0.2,0.0);
        glVertex2f(-0.2,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.78,1.0);
        glVertex2f(0.2,0.2);
          glVertex2f(0.3,0.0);
          glVertex2f(0.2,0.0);
    glEnd();
    //vidros
}
void display_function()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glTranslatef(tx,0.0,0.0);
    carro();
    vidro();
    glPushMatrix();
        rodaT();
    glPopMatrix();

    glPushMatrix();
        rodaD();
    glPopMatrix();
    glFlush();
}

void tecladoEspecial(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
            tx+=0.05;
            theta+=5;
            break;
        case GLUT_KEY_LEFT:
            tx-=0.05;
            theta-=5;
            break;
        case GLUT_KEY_UP:
             r+=0.05;
            if(g<0.3)
                g+=0.025;
            theta+=5;
            break;
        case GLUT_KEY_DOWN:
             r+=0.05;
            if(g<0.3)
                g+=0.025;
            theta-=5;
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
