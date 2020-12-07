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
float a=-1000,B=1000,c=-1000,d=1000;
float pts[6]={0,0,0,0,0,0};
int i=0,j=0,k=0;
char letra='0';

/*float p1x=1,p1y=1;
float p2x=1,p2y=-1;
float p3x=0,p3y=1;*/
int NovaReta(){
    int num=0;
    while(num<100){
        num=rand()%2000;
    }
    return num-1000;
}
void Retas(){

     glClearColor(0, 0, 0, 0); //Preto
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(r,g,b);

    glBegin(GL_LINES);

    glVertex2f (a ,B);
    glVertex2f (c, d);

    glEnd();
    glFlush();
}
void SetaRetas(){
    a=NovaReta();
    B=NovaReta();
    c=NovaReta();
    d=NovaReta();
    glutDisplayFunc(Retas);
}
void triangulo(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
       glColor3f(r, g, b); glVertex2f(pts[0],pts[1]);
       glColor3f(r, g, b); glVertex2f(pts[2], pts[3]);
       glColor3f(r, g, b); glVertex2f(pts[4], pts[5]);
    glEnd();
    glFlush();
}

void MouseInt (int botao, int estado, int cx, int cy){
    switch(botao){
       case GLUT_LEFT_BUTTON:
          if(estado == GLUT_DOWN){
            x=cx;
            y=cy;
           pts[i]=(4*x/1000-1);
           pts[i+1]= (1-4*y/1000);
           i++, i++;
           for(int j=0;j<6;j++)
                printf("%f ", pts[j]);
           printf("\n\n");
            if(i==2){
                /*pts[2]=pts[0];
                pts[3]=pts[1];*/
                pts[4]=pts[0];
                pts[5]=pts[1];
            }
            if(i==6){
              i=0;
            }
            if(k==0){
                x=cx;
                y=cy;
                a=(4*x/1000-1);
                B= (1-4*y/1000);
                c=a;
                d=B;
                k++;
             }else{
                k=0;
                x=cx;
                y=cy;
                c=(4*x/1000-1);
                d= (1-4*y/1000);
             }

          }
          break;
    }

    glutPostRedisplay();
    }
    //letra='0';

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
        case 'R':
        case 'r':
            glutDisplayFunc(Retas);
            break;
        case 'T':
        case 't':
           glutDisplayFunc(triangulo);

        break;
    }
    glutPostRedisplay() ;

}



int main( int argc, char *argv[ ] ){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(500,100);
    glutInitWindowSize(500,500);
    glutInit(&argc, argv);
    glutCreateWindow("Linhas");
    glutKeyboardFunc(Teclado);
    glutDisplayFunc(Retas);
    glutMouseFunc(MouseInt);
    //glutDisplayFunc(triangulo);
    glutMainLoop ();
    return 0;
}
