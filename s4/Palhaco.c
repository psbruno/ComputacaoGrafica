#include <GL/glut.h>

GLUquadricObj *obj;

int objId = 1;
float angX = 0;
float angY = 0;
int x=100,inty=100;

void init(){
     glClearColor(0.0,0.0,0.0,0.0);
     glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glOrtho(-7,7,-7,7,-7,7);
     glPushMatrix();
}

void cabelod(){
    glColor3f(1.0,0.0,0.0);
    glTranslatef(-2.8,2.9,0);
    glutWireSphere(2,50,50);

    glColor3f(1.0,0.0,0.0);
    glTranslatef(-0.5,-0.5,0);
    glutWireSphere(2,50,50);

    glColor3f(1.0,0.0,0.0);
    glTranslatef(-0.5,-0.75,0);
    glutWireSphere(2,50,50);

}
void cabeloe(){
        glColor3f(1.0,0.0,0.0);
    glTranslatef(2.8,2.9,0);
    glutWireSphere(2,50,50);

    glColor3f(1.0,0.0,0.0);
    glTranslatef(0.5,-0.5,0);
    glutWireSphere(2,50,50);

    glColor3f(1.0,0.0,0.0);
    glTranslatef(0.5,-0.75,0);
    glutWireSphere(2,50,50);

}

void olhoe(){
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-1.35,1.1,2);
    glutWireSphere(0.8,50,50);
}
void pupilae(){
    glColor3f(0.41,0.29,0.0);
    glTranslatef(-1.35,1.1,2.7);
    glutWireSphere(0.3,50,50);
}
void olhod(){
    glColor3f(1.0,1.0,1.0);
    glTranslatef(1.35,1.1,2);
    glutWireSphere(0.8,50,50);
}
void pupilad(){
    glColor3f(0.41,0.29,0.0);
    glTranslatef(1.35,1.1,2.7);
    glutSolidSphere(0.3,50,50);
}

void nariz(){
    glColor3f(1.0,0.0,0.0);
    glTranslatef(0.0,0.0,2.9);
    glutSolidCone(0.5,2,10,4);
}

void boca(){
    glColor3f(1.0,0.0,0.0);
    glTranslatef(-0.2,-1.4,2.7);
    glScalef(5,0.9,1);
    glutSolidSphere(0.3,50,50);


     glPopMatrix();
    glPushMatrix();
    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);


    glColor3f(1.0,1.0,1.0);
    glTranslatef(-0.2,-1.4,2.8);
    glScalef(4,0.3,1);
    glutSolidSphere(0.3,50,50);

}

void display(){
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
     glColor3f(1.0,1.0,1.0);

    glPopMatrix();
    glPushMatrix();

     glRotatef(angX,1,0,0);
     glRotatef(angY,0,1,0);
     glutWireSphere(3,50,50);

    glPopMatrix();
    glPushMatrix();

    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    cabeloe();


    glPopMatrix();
    glPushMatrix();

    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    cabelod();

    glPopMatrix();
    glPushMatrix();

    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    olhoe();

    glPopMatrix();
    glPushMatrix();

    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    cabeloe();


    glPopMatrix();
    glPushMatrix();

    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    cabelod();

    glPopMatrix();
    glPushMatrix();

    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    pupilae();

    glPopMatrix();
    glPushMatrix();

    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    olhod();

    glPopMatrix();
    glPushMatrix();

    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    pupilad();


    glPopMatrix();
    glPushMatrix();

    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    nariz();

    glPopMatrix();
    glPushMatrix();

    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    boca();

    glPopMatrix();
    glPushMatrix();


    glFlush();

}
void transformacoes(int key, int x, int y){
     switch (key){
        case GLUT_KEY_UP :
           angX+=15;
           break ;
        case GLUT_KEY_DOWN :
           angX-=15;
           break ;
        case GLUT_KEY_RIGHT :
           angY+=15;
           break ;
        case GLUT_KEY_LEFT :
           angY-=15;
           break ;
     }
     glutPostRedisplay() ;
}
void anima(){
    angY+=0.1;
    glutPostRedisplay();
}
void mouseFunc(int button, int state, int x, int y){
     switch (button)    {
        case GLUT_LEFT_BUTTON:
           if (state == GLUT_DOWN)
              glutIdleFunc(anima);
           break;
        case GLUT_RIGHT_BUTTON:
           if (state == GLUT_DOWN)
              glutIdleFunc(NULL);
           break;
        default:
           break;
     }
}
int main(int argc, char *argv[])
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowPosition(50,50);
     glutInitWindowSize(600,600);
     glutCreateWindow("Objetos 3D - OpenGL");
     glutSpecialFunc(transformacoes);
     glutDisplayFunc(display);
     glutMouseFunc(mouseFunc);
     init();
     glutMainLoop();
}
