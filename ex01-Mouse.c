#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
# define PI 3.141592654
int n = 50;
float ang = 50;
float x,y;
void desenharCirculo() { }



void setajanela(){
}
void primeiro(){
   int i;
   float angulo =0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        for(i=0;i<50;i++){
            glVertex2f(0.05*cos(angulo)-1,0.05*sin(angulo)+1);
            angulo = angulo+(2*M_PI)/n;
        }
    glEnd();
    glFlush();
}
void desenha(){
    printf("%f %f\n", x/1000,y/1000);
    int i;
    float angulo=0;
//glClearColor(0, 0, 0, 0); //Preto
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);

    glBegin(GL_POLYGON);
        for(i=0;i<50;i++){
            angulo = 2* PI * i / 50;
            //if(i==1 || i==100)printf("__%f %f\n",0.05*cos(angulo), 0.05*sin(angulo) );
            glVertex2f(0.05*cos(angulo)+(4*x/1000-1),0.05*sin(angulo)+(1-4*y/1000));
            //glVertex2f(0.05*cos(angulo)+ x/1000+0.3,0.05*sin(angulo)+y/1000-0.3);
        }
        //printf("--%f %f\n",0.05*cos(angulo)-0.7, 0.05*sin(angulo)-0.7 );
    glEnd();
    glFlush();
}
void MouseInt (int botao, int estado, int xl, int yl){

    switch(botao){
       case GLUT_LEFT_BUTTON:
          if(estado == GLUT_DOWN)
              glutDisplayFunc (desenha);
              x=xl;
              y=yl;

          break;
       case GLUT_RIGHT_BUTTON:
          if(estado == GLUT_DOWN){

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
    glutCreateWindow("Circulo em torno do click");
    glutDisplayFunc(setajanela);
    glutDisplayFunc (primeiro);
    glutMouseFunc(MouseInt);
    glutMainLoop ();
    return 0;
}
