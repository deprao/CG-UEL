#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void myInit(void){
    
    glClearColor(1.0,1.0,1.0,0.0); // cor de fundo branco
    glColor3f(0.0f, 0.0f, 0.0f); // Define cor corrente de desenho
    glPointSize(4.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 50.0); //ajuste o tamanho para make conforme
    glClear(GL_COLOR_BUFFER_BIT);
}

float lx1, ly1, lx2, ly2;

float inclinacao(){
    float Dx = lx2 - lx1;
    float Dy = ly2 - ly1;

    float m = Dy/Dx;

    return m;
}

void DDA(){
    float m = inclinacao();
    printf("%f\n", m);
    float B = ly1 - (m*lx1);
    printf("%f\n", B);
    GLfloat x = round(lx1);
    GLfloat y = round(ly1);
    
    while(x < lx2 || y < ly2){
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
        glFlush();

        x++;
        y = (m*x) + B;
        y = round(y);
    }
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

int main(int argc, char **argv){

    printf("Para traçar a reta, determine as coordenadas de início e fim:\n(separe eixos por espaço, x e y respectivamente)\n\n");
    printf("Coordenadas de início: "); scanf("%f %f", &lx1, &ly1);
    printf("\nCoordenadas de fim: "); scanf("%f %f", &lx2, &ly2);

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(150,150);
    glutInitWindowPosition(100,100);
    glutCreateWindow("reta DDA");

    myInit();

    glutDisplayFunc(DDA);

    glutMainLoop();

    return 0;
}