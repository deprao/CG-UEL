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
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

void bresenham(int r){
    GLint x = 0;
    GLint y = r;
    int p = 1 - r;

    glBegin(GL_POINTS);

    glVertex2i(x, y);
    glVertex2i(y, x);
    glVertex2i(-x, y);
    glVertex2i(-y, x);
    glVertex2i(x, -y);
    glVertex2i(y, -x);
    glVertex2i(-x, -y);
    glVertex2i(-y, -x);

    while(x < y){

        x++;

        if(p < 0){
            p = p + (2*x) + 1;
        }
        else if(p > 0){
            y--;
            p = p + (2*x) + 1 - (2*y);
        }

        glVertex2i(x, y);
        glVertex2i(y, x);
        glVertex2i(-x, y);
        glVertex2i(-y, x);
        glVertex2i(x, -y);
        glVertex2i(y, -x);
        glVertex2i(-x, -y);
        glVertex2i(-y, -x);
    }
    glEnd();
    glFlush();

}