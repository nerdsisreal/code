#include<iostream>
#include<math.h>
#include<vector>
#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>

using namespace std;

vector<int> ptX,ptY;
int choice,edges;


// translation
int tx,ty;

// scaling
double sx,sy,xf,yf;

double round(double d){
    return floor(d+0.5);
}

// rotation angle
double angle,xp,yp;

void degToRad(){
    angle = ((3.1416)/180)*angle;
}

// Reflection
char reflectionAxis;


// shearing axis;
char shearingAxis;
double shx,shy;

void drawPolygon()
{
    glBegin(GL_POLYGON);
    for(int i=0; i<edges; i++)
    {
        glVertex2i(ptX[i],ptY[i]);
    }
    glEnd();
}
void drawPolygonTranslation(){
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<edges;i++){
        glVertex2i(ptX[i]+tx,ptY[i]+ty);
    }
    glEnd();
}

void drawPolygonScaling(){
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<edges;i++){
        double x = xf + ((ptX[i]-xf)*sx);
        double y = yf + ((ptY[i]-yf)*sy);
        glVertex2i(round(x),round(y));
    }
    glEnd();
}

void drawPolygonRotation(){
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<edges;i++){
        double x = xp + ((ptX[i]-xp)*cos(angle)) - ((ptY[i]-yp)*sin(angle));
        double y = yp + ((ptX[i]-xp)*sin(angle)) + ((ptY[i]-yp)*cos(angle));
        glVertex2i(round(x),round(y));
    }
    glEnd();

}

void drawPolygonReflection(){
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
        if(reflectionAxis == 'a'){
            for(int i=0;i<edges;i++){
                double x = ptX[i];
                double y = -ptY[i];
                glVertex2i(round(x),round(y));
            }
        }
        else if(reflectionAxis == 'b'){
            for(int i=0;i<edges;i++){
                double x = -ptX[i];
                double y = ptY[i];
                glVertex2i(round(x),round(y));
            }
        }
        else if(reflectionAxis == 'c'){
            for(int i=0;i<edges;i++){
                double x = ptY[i];
                double y = ptX[i];
                glVertex2i(round(x),round(y));
            }
        }
        else if(reflectionAxis == 'd'){
            for(int i=0;i<edges;i++){
                double x = -ptX[i];
                double y = -ptY[i];
                glVertex2i(round(x),round(y));
            }
        }
    glEnd();
}
void drawPolygonShearing(){
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
   // cout<<shx<<" "<<shy<<endl;
    //cout<<shearingAxis<<endl;
    for(int i=0;i<edges;i++){
        if(shearingAxis == 'X' || shearingAxis == 'x'){


            double x = ptX[i] + (shx*ptY[i]);
            double y = ptY[i];

            glVertex2i(round(x),round(y));
        }
        else{
            cout<<shy<<endl;
            double x = ptX[i];
            double y = ptY[i] + (shy*ptX[i]);

            glVertex2i(round(x),round(y));
        }
    }
    glEnd();
}
void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(4);
    drawPolygon();
    if(choice == 1){
        drawPolygonTranslation();
    }
    else if(choice == 2){
        drawPolygonScaling();
    }
    else if(choice == 3){
        drawPolygonRotation();
    }
    else if(choice == 4){
        drawPolygonReflection();
    }
    else if(choice == 5){
        drawPolygonShearing();
    }
    glFlush();
}

int main(int argc,char *argv[])
{
    cout<<"2D geometric transformation"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"1. Translation"<<endl;
    cout<<"2. Scaling(Fixed Point)"<<endl;
    cout<<"3. Rotation(Pivot point)"<<endl;
    cout<<"4. Reflection"<<endl;
    cout<<"5. Shearing"<<endl;
    cout<<"6. Exit"<<endl<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    cout<<"Enter the number of edges:";
    cin>>edges;
    for(int i=0; i<edges; i++)
    {
        cout<<"Enter the "<<i<<"th points:";
        int temp1,temp2;
        cin>>temp1>>temp2;
        ptX.push_back(temp1);
        ptY.push_back(temp2);
    }
    if(choice == 1)
    {
        cout<<"Enter translation factor tx:";
        cin>>tx;
        cout<<"Enter the translation factor ty:";
        cin>>ty;

    }
    else if(choice == 2)
    {
        cout<<"Enter the scaling factor X and Y:";
        cin>>sx>>sy;
        cout<<"Enter the fixed point for scaling:";
        cin>>xf>>yf;
    }
    else if(choice == 3)
    {
        cout<<"Enter the rotation angle:";
        cin>>angle;
        degToRad();
        cout<<"Enter the pivot point for rotation:";
        cin>>xp>>yp;
    }
    else if(choice == 4)
    {
        cout<<"Choose Reflection Axis:";
        cout<<"a. X axis"<<endl;
        cout<<"b. Y axis"<<endl;
        cout<<"c. X=Y axis"<<endl;
        cout<<"d. Origin"<<endl;
        cout<<"Enter reflection axis:";
        cin>>reflectionAxis;
    }
    else if(choice == 5)
    {

        cout<<"Enter the shearing axis(x,y):";
        cin>>shearingAxis;

        if(shearingAxis == 'x' || shearingAxis == 'X'){
            cout<<"Enter the shearing factor for X:";
            cin>>shx;


        }
        else{
            cout<<"Enter the shearing factor for Y:";
            cin>>shy;

        }
    }
    else
    {
        cout<<"Exiting program"<<endl;
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("2D translation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0;
}
