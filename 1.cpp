#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>
#define round(x) x+0.5
float x1,y1,x2,y2,x,y,dx,dy,steps,xinc,yinc;

void init(){
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(4);
    glBegin(GL_POINTS);
        dx = x2-x1,dy = y2-y1;
        if(abs(dx)>abs(dy)){
            steps = abs(dx);
        }
        else{
            steps = abs(dy);
        }
        x = x1, y = y1;
        xinc = dx/steps;
        yinc = dy/steps;
        for(int i=0;i<=steps;i++){
            printf("%f %f\n",x,y);
            int tempx = round(x), tempy = round(y);
            glVertex2i(tempx,tempy);
            x += xinc;
            y += yinc;
        }
    glEnd();
    glFlush();

}


int main(int argc, char *argv[]){
    printf("Enter the first points:");
    scanf("%f %f",&x1,&y1);
    printf("Enter the second points:");
    scanf("%f %f",&x2,&y2);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("A beautiful Day");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
