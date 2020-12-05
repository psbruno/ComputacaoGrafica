#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
# define PI 3.141592654
int n = 50;
float ang = 50;
float x,y;
float r=0,g=0,b=1;
float a=0,B=0,c=0,d=0;
int NovaReta(){
    int num=0;
    while(num<100){
        num=rand()%1000;
    }
}
void Retas(){
    printf("%f %f %f %f\n",a,B,c,d);
     glClearColor(0, 0, 0, 0); //Preto
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(r,g,b);

    glBegin(GL_LINES);

    glVertex2f (a/1000 ,B/1000);
    glVertex2f (c/1000, d/1000);

    glEnd();
    glFlush();
}
void Teclado(unsigned char key, int x, int y){
    switch (key){
        case '0' :
            r=0.243;
            g=0.5478;
            b=0.789;
            break;


        case '1' :
            r=0;
            g=0.8;
            b=0;
        break;


        case '2' :
            r=1;
            g=0.27;
            b=0.7;
        break;

        case '3' :
            r=0.8;
            g=0.2;
            b=1;
        break;

        case '4' :
            r=1.7;
            g=0.4;
            b=0.2;
        break;

        case '5' :
            r=0.4;
            g=1;
            b=1;
        break;

        case '6' :
            r=1;
            g=1;
            b=1;
        break;

        case '7' :
            r=1;
            g=1;
            b=0;
        break;

        case '8' :
            r=0.718;
            g=0.61;
            b=0.748;
        break;

        case '9' :
            r=0;
            g=1;
            b=0.6;
        break;
    }
    glutPostRedisplay() ;

}
void MouseInt (int botao, int estado, int xl, int yl){

    switch(botao){
       case GLUT_LEFT_BUTTON:
          if(estado == GLUT_DOWN){
             a=NovaReta();
             B=NovaReta();
             c=NovaReta();
             d=NovaReta();
             glutDisplayFunc(Retas);
          }
          break;
    }
    glutPostRedisplay();
}


int main( int argc, char *argv[ ] ){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(500,100);
    glutInitWindowSize(500,500);
    glutInit(&argc, argv);
    glutCreateWindow("Linhas");
    glutDisplayFunc(Retas);
    glutMouseFunc(MouseInt);
    glutKeyboardFunc(Teclado);
    glutMainLoop ();
    return 0;
}
