#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>

using namespace std;

float x1,y1,x2,y2;
int r;

//Functions Declaration
void init();
void display();
int sign(int a);
void bres(int r);
//End Declaration

int main(int argc,char **argv)
{
     cout<<"Enter Radius of Circle :";
     cin>>r;
     glutInit(&argc,argv);
     glutCreateWindow("Assignment 2");
     init();
     glutDisplayFunc(display);

     glutMainLoop();
}

void init()
{
     glClearColor(0,0,0,0);
     glClear(GL_COLOR_BUFFER_BIT);
     gluOrtho2D(-100,100,-100,100);
}

//To draw a line
void dda(float x1,float y1,float x2,float y2)
{
     int len,i=1;
     float dx=0,dy=0,x=0,y=0;

     dx = abs(x2-x1);
     dy = abs(y2-y1);

     if(dx>dy)
     {
        len = dx;
     }
     else
     {
        len = dy;
     }
     dx = (x2-x1)/len;
     dy = (y2-y1)/len;

     x = x1+0.5*(sign(dx));
     y = y1+0.5*(sign(dy));

     while(i<=len)
     {
          glBegin(GL_POINTS);
          glVertex2i(x,y);
          glEnd();
          x=x+dx;
          y=y+dy;
          i++;
     }
}

//To Check Sign of int
int sign(int a)
{
    if(a<0)
        return -1;
    else if(a>0)
        return 1;
    else
        return 0;
}



void display()
{
    bres(r);
    bres(2*r);

    dda(-1.73*r,-r,1.73*r,-r);
    dda(-1.73*r,-r,0,2*r);
    dda(1.73*r,-r,0,2*r);

    glFlush();
}

//For Circle
void bres(int r)
{
     int d,x=0,y;
     d=3-2*r;
     y=r;
     do
     {
          glBegin(GL_POINTS);
          glVertex2i(x,y);
          glVertex2i(y,x);
          glVertex2i(x,-y);
          glVertex2i(-x,y);
          glVertex2i(y,-x);
          glVertex2i(-y,x);
          glVertex2i(-x,-y);
          glVertex2i(-y,-x);
          glEnd();
          if(d<0)
          {
            d=d+4*x+6;
          }
          else
          {
            d=d+4*(x-y)+10;
            y=y-1;
          }
          x=x+1;
     }
     while(x<y);
}







