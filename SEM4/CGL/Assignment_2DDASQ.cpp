//Assignment 2 - Draw Line using DDA Algorithm

#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>

float X1,Y1,X2,Y2;
using namespace std;

void initWindow(float,float,float,float);
void draw();
void drawDDA(float,float,float,float);

int main(int argc, char **argv)
{
    cout<<"\nEnter Point 1 (x1,y1) :";
    cin>>X1>>Y1;
    cout<<"\nEnter Point 2 (x2,y2) :";
    cin>>X2>>Y2;
    glutInit(&argc,argv);
    glutCreateWindow("DDA ALGORITHM (Shreyas Patil)");
    initWindow(0,0,0,0);
    glutDisplayFunc(draw);
    glutMainLoop();
}

//Function to initialize window
void initWindow(float r, float g, float b, float o)
{
    glClearColor(r,g,b,o);
    gluOrtho2D(-100,100,-100,100);
}

//Function to draw on Window
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Outer Square Start
    drawDDA(X1,Y1,X1,Y2);
    drawDDA(X1,Y2,X2,Y2);
    drawDDA(X2,Y1,X2,Y2);
    drawDDA(X1,Y1,X2,Y1);
    //Outer Square End

    //Middle Square Start
    int p = (X1+X2)/2;
    int q = (Y1+Y2)/2;

    drawDDA(X1,q,p,Y2);
    drawDDA(p,Y2,X2,q);
    drawDDA(X2,q,p,Y1);
    drawDDA(p,Y1,X1,q);
    //Middle Square End

    //Inner Square Start
    drawDDA((p+X1)/2,(Y2+q)/2,(X2+p)/2,(Y2+q)/2);
    drawDDA((p+X2)/2,(Y2+q)/2,(X2+p)/2,(Y1+q)/2);
    drawDDA((p+X2)/2,(Y1+q)/2,(X1+p)/2,(Y1+q)/2);
    drawDDA((p+X1)/2,(Y1+q)/2,(X1+p)/2,(Y2+q)/2);
    //Inner Square End

    glFlush();
}

//Function to draw a line using DDA Algorithm
void drawDDA(float x1, float y1, float x2, float y2)
{
    int length;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if(dx >= dy)
        length = dx;
    else
        length = dy;

    dx = (x2 - x1)/length;
    dy = (y2 - y1)/length;

    float x = x1 + 0.5 * signbit(dx);
    float y = y1 + 0.5 * signbit(dy);

    int i=1;
    while(i<=length)
    {
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();

        x = x+dx;
        y = y+dy;

        i++;
    }
}
