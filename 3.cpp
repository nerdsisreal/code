#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>

#define round(x) x+0.5;

float x1,y1,x2,y2,pk,m,dx,dy,x,y,xinc,yinc;
int tempx,tempy;

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(4);
    glBegin(GL_POINTS);


    dx = x2-x1,dy= y2-y1;
    m = abs(dy)/abs(dx);
    bool flag = false;
    if(m<1)
    {
        flag = true;
        pk = 2*abs(dy) - abs(dx);
        if(dx>0 && dy>0)
        {
            xinc = 1,yinc = 1;
        }
        else if(dx <= 0 && dy <= 0)
        {
            xinc = -1, yinc = -1;
        }
        else if(dx > 0 && dy <= 0)
        {
            xinc = 1, yinc = -1;
        }
        else if(dx <= 0 && dy > 0)
        {
            xinc = -1, yinc = 1;
        }
    }
    else
    {
        pk = 2*abs(dx) - abs(dy);
        if(dx>0 && dy>0)
        {
            xinc = 1,yinc = 1;
        }
        else if(dx <= 0 && dy <= 0)
        {
            xinc = -1, yinc = -1;
        }
        else if(dx > 0 && dy <= 0)
        {
            xinc = 1, yinc = -1;
        }
        else if(dx <= 0 && dy > 0)
        {
            xinc = -1, yinc = 1;
        }
    }

    if(flag)
    {
        x = x1,y = y1;
        printf("%f %f\n",x,y);
        tempx = round(x);
        tempy = round(y);
        glVertex2i(tempx,tempy);
        while(x != x2 && y != y2)
        {


            if(pk<0)
            {
                x += xinc;
                pk += 2*abs(dy);
            }
            else
            {
                x += xinc;
                y += yinc;
                pk += 2*abs(dy) - 2*abs(dx);
            }
            printf("%f %f\n",x,y);
            tempx = round(x);
             tempy = round(y);
            glVertex2i(tempx,tempy);
        }
    }
    else
    {
        x = x1,y = y1;
        printf("%f %f\n",x,y);
        tempx = round(x);
        tempy = round(y);
        glVertex2i(x,y);
        while(x != x2 && y != y2)
        {

            if(pk<0)
            {
                y += yinc;
                pk += 2*abs(dx);
            }
            else
            {
                x += xinc;
                y += yinc;
                pk += 2*abs(dx) - 2*abs(dy);
            }
            printf("%f %f\n",x,y);
            tempx = round(x);
            tempy = round(y);
            glVertex2i(tempx,tempy);
        }

    }










    glEnd();
    glFlush();

}

int main(int argc,char *argv[])
{
    printf("Enter the first points:");
    scanf("%f %f",&x1,&y1);
    printf("Enter the second points:");
    scanf("%f %f",&x2,&y2);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("The good boys");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
