#include <GL/glut.h>
#include <stdio.h>

int side=1;
int objId = 1;
int input=1;
float angX = 0;
float angY = 0;
float angZ = 0;
int x=100,inty=100;
void anima();
void init(){
     glClearColor(0.0,0.0,0.0,0.0);
     glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glOrtho(-7,7,-7,7,-7,7);
     glPushMatrix();
}
void Centro(){
     glRotatef(angX,1,0,0);
     glRotatef(angY,0,1,0);
     glutWireSphere(1,50,50);
}
void Haste(){

    glColor3f(0.0,1.0,0.0);
     glTranslatef(0,-3,0);
     glScalef(1,-25,1);
     glutWireCube(0.25);
}
void Helice1(){
     glColor3f(1.0,0.0,0.0);
     glScalef(1,1.75,1);
     glTranslatef(0.7,0.6,0);
     glutWireOctahedron();
}
void Helice2(){
     glColor3f(0.0,0.0,1.0);
     glScalef(1.75,1,1);
     glTranslatef(0.7,-0.6,0);
     glutWireOctahedron();
}
void Helice3(){
     glColor3f(0.5,0.5,0.5);
     glScalef(1,1.75,1);
     glTranslatef(-0.7,-0.6,0);
     glutWireOctahedron();
}
void Helice4(){
     glColor3f(0.0,1.0,0.0);
     glScalef(1.75,1,1);
     glTranslatef(-0.7,0.6,0);
     glutWireOctahedron();
}
void display(){
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
     glColor3f(1.0,1.0,1.0);

    glPopMatrix();
    glPushMatrix();
    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    Centro();

    glPopMatrix();
    glPushMatrix();
    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    Haste();

    glPopMatrix();
    glPushMatrix();
    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    glRotatef(angZ,0,0,1);
    Helice1();

    glPopMatrix();
    glPushMatrix();
    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    glRotatef(angZ,0,0,1);
    Helice2();

    glPopMatrix();
    glPushMatrix();
    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    glRotatef(angZ,0,0,1);
    Helice3();

    glPopMatrix();
    glPushMatrix();
    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    glRotatef(angZ,0,0,1);
    Helice4();

    glFlush();

}
void transformacoes(int key, int x, int y){
     switch (key){
        case GLUT_KEY_UP :
           angY+=15;
           break ;
        case GLUT_KEY_DOWN :
           angY-=15;
           break ;
        case GLUT_KEY_RIGHT :
            glutIdleFunc(anima);
            input++;

           break ;
        case GLUT_KEY_LEFT :
            if(input>0)
                input--;
           break ;
     }
     glutPostRedisplay() ;
}
void anima(){

    angZ+=0.1*input;
    glutPostRedisplay();
}
void timer(int value){
    if(input==0 && side == -1)
        return;
    if(input==5 && side==1)
        return;
    printf("%d\n",input);
    input=input+1*side;

    glutPostRedisplay();
    glutTimerFunc(1000,timer,1);
}
void mouseFunc(int button, int state, int x, int y){
     switch (button)    {
        case GLUT_LEFT_BUTTON:
           if (state == GLUT_DOWN){
                side=1;
                glutTimerFunc(10,timer,1);
           }
           break;
        case GLUT_RIGHT_BUTTON:
           if (state == GLUT_DOWN){
                side=-1;
                glutTimerFunc(10,timer,1);
           }
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
     //glutTimerFunc(10,timer,1);
     glutIdleFunc(anima);
     init();
     glutMainLoop();
}
