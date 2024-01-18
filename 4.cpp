#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>

int xc,yc,r,x,y,pk;

void init(){
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(4);
    glBegin(GL_POINTS);

        x = 0,y = r;
        pk = 1-r;
        while(x<y){
            if(pk<0){
                x++;
                pk = pk+ (2*x) + 1;
            }
            else{
                x++;
                y--;
                pk = pk + (2*x) + 1 - (2*y);
            }

            glVertex2i(xc+x,yc+y);
            glVertex2i(xc+x,yc-y);
            glVertex2i(xc-x,yc+y);
            glVertex2i(xc-x,yc-y);

            glVertex2i(xc+y,yc+x);
            glVertex2i(xc+y,yc-x);
            glVertex2i(xc-y,yc+x);
            glVertex2i(xc-y,yc-x);

        }
    glEnd();
    glFlush();

}

int main(int argc, char *argv[]){
    printf("Enter the center of the circle:");
    scanf("%d %d",&xc,&yc);
    printf("Enter the radius of the circle:");
    scanf("%d",&r);




    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("A good title");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
