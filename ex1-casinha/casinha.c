#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>


void myInit(void){
    
    glClearColor(1.0,1.0,1.0,0.0); // cor de fundo branco
    glColor3f(0.0f, 0.0f, 0.0f); // Define cor corrente de desenho
    glPointSize(4.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // janela com resolução de 640 por 480
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void houseQuads(void){
    
    glClear(GL_COLOR_BUFFER_BIT); // limpa a janela
    glColor3f(127/255.0f, 127/255.0f, 127/255.0f);
    glBegin(GL_QUADS);
    
        glVertex2f(100.0, 100.0);
        glVertex2f(100.0, 300.0);
        glVertex2f(300.0, 300.0);
        glVertex2f(300.0, 100.0);

    glEnd();

    glColor3f(30/255.0f, 235/255.0f, 246/255.0f);
    glBegin(GL_QUADS);

        glVertex2f(130.0, 100.0);
        glVertex2f(130.0, 200.0);
        glVertex2f(180.0, 200.0);
        glVertex2f(180.0, 100.0);

        glVertex2f(200.0, 170.0);
        glVertex2f(200.0, 250.0);
        glVertex2f(270.0, 250.0);
        glVertex2f(270.0, 170.0);
    
    glEnd();
}

void houseRoof(void){
    
    glColor3f(235/255.0f, 63/255.0f, 10/255.0f);
    glBegin(GL_TRIANGLES);
    
        glVertex2f(100.0, 300.0);
        glVertex2f(300.0, 300.0);
        glVertex2f(200.0, 400.0);
    
    glEnd();
}

void houseChimney(void){
    
    glColor3f(105/255.0f, 47/255.0f, 22/255.0f);
    glBegin(GL_POLYGON);
    
        glVertex2f(120.0, 320.0);
        glVertex2f(120.0, 450.0);
        glVertex2f(150.0, 450.0);
        glVertex2f(150.0, 350.0);
    
    glEnd();
}


void myInit(void); // inicialização do OpenGL
void houseQuads(void); // desenho da cena gráfica
void houseRoof(void);
void houseChimney(void);

void myDisplay(void){
    houseQuads();
    houseRoof();
    houseChimney();
    glFlush();
}

void myDisplay(void);

int main(int argc, char **argv){

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("lar doce lar");

    myInit();

    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;

}