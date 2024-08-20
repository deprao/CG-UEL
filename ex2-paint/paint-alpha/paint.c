#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

void myInit(void){
    
    glClearColor(1.0,1.0,1.0,0.0); // cor de fundo branco
    glColor3f(0.0f, 0.0f, 0.0f); // Define cor corrente de desenho
    glPointSize(4.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // janela com resolução de 640 por 480
    gluOrtho2D(0.0, 640.0, 480.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void pinta(GLint x, GLint y){
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

void handle_cores(GLint cor){
    switch(cor){
        case 0:
            glColor3f(1.0f, 0.0f, 0.0f);
            break;
        case 1:
            glColor3f(0.0f, 1.0f, 0.0f);
            break;
        case 2:
            glColor3f(0.0f, 0.0f, 1.0f);
            break;
        case 3:
            glColor3f(0.0f, 0.0f, 0.0f);
            break;
    }
}

void handle_caneta(GLint esp){
    switch(esp){
        case 0:
            glPointSize(2.0);
            break;
        case 1:
            glPointSize(4.0);
            break;
        case 2:
            glPointSize(8.0);
            break;
        case 3:
            glPointSize(14.0);
            break;
    }
}

void handle_menus(GLint menu){
    switch(menu){
        case 0:
            glColor3f(1.0f, 1.0f, 1.0f);
            break;
    }
}

void menus(){
    GLint menu, cores, caneta, borracha;

    cores = glutCreateMenu(handle_cores);
    glutAddMenuEntry("vermelho", 0);
    glutAddMenuEntry("verde", 1);
    glutAddMenuEntry("azul", 2);
    glutAddMenuEntry("preto (std)", 3);

    caneta = glutCreateMenu(handle_caneta);
    glutAddMenuEntry("2.0", 0);
    glutAddMenuEntry("4.0 (std)", 1);
    glutAddMenuEntry("8.0", 2);
    glutAddMenuEntry("14.0", 3);

    menu = glutCreateMenu(handle_menus);
    glutAddSubMenu("cores", cores);
    glutAddSubMenu("espessura", caneta);
    glutAddMenuEntry("borracha", 0);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void handle_clear(GLubyte tec, GLint x, GLint y){
    if(tec == 'd'){
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }
}

int main(int argc, char **argv){

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("paint alpha");

    myInit();

    menus();
    glutMotionFunc(pinta);
    glutKeyboardFunc(handle_clear);

    glutMainLoop();

    return 0;
}