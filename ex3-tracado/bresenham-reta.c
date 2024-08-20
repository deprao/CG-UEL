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
    glClear(GL_COLOR_BUFFER_BIT);
}

int lx1, int ly1, int lx2, int ly2;

void bres_X(int x1, int y1, int x2, int y2, int Dx, int Dy){
    GLint x = x1;
    GLint y = y1;
    int p = (2*Dy) - Dx;

    glBegin(GL_POINTS);
    while(x < x2 || y < y2){
        glVertex2i(x, y);

        if(p > 0){
            x++;
            y++;
            p = p + (2*Dy) - (2*Dx);
        }
        else if(p < 0){
            x++;
            p = p + (2*Dy);
        }
    }
    glEnd();
    glFlush();
}

void bres_Y(int x1, int y1, int x2, int y2, int Dx, int Dy){
    GLint x = x1;
    GLint y = y1;
    int p = (2*Dx) - Dy;

    glBegin(GL_POINTS);
    while(x < x2 || y < y2){
        glVertex2i(x, y);

        if(p > 0){
            x++;
            y++;
            p = p + (2*Dx) - (2*Dy);
        }
        else if(p < 0){
            y++;
            p = p + (2*Dx);
        }
    }
    glEnd();
    glFlush();
}

void bresenham(){
    int Dx = x2 - x1;
    int Dy = y2 - y1;
    float m = ((float)Dy)/((float)Dx);
    int 

    if(m < 1){  //m<1 análise em x
        //bres_X(Dx, Dy);

    }
    else if(m > 1){ //m>1 análise em y
        //bres_Y(Dx, Dy);
    }
}

int main(int argc, char **argv){

    printf("Para traçar a reta, determine as coordenadas de início e fim:\n(separe eixos por espaço, x e y respectivamente)\n\n");
    printf("Coordenadas de início: "); scanf("%f %f", &lx1, &ly1);
    printf("\nCoordenadas de fim: "); scanf("%f %f", &lx2, &ly2);

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(150,150);
    glutInitWindowPosition(100,100);
    glutCreateWindow("reta Bresenham");

    myInit();

    glutDisplayFunc(DDA);

    glutMainLoop();

    return 0;
}