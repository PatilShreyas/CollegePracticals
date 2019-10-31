#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;

struct Color
{
    float r,g,b;
};

Color color;

//Functions Declaration
void init();
void display();
void dda(int x1,int y1,int x2,int y2);
void bres_circle(int r);
void mouse1(int button,int state,int x,int y);
void key1(unsigned char key,int x,int y);
void flood_fill(int x,int y,Color old_Color,Color new_Color);
void putPixel(int x,int y,Color new_Color);
Color getPixelColor(int x,int y);
//Declaration End

int x1,x2,y1,y2,r;
int pt=0;

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(700,700);
    glutCreateWindow("Shreyas Patil (SEITB18272)");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse1);
    glutKeyboardFunc(key1);
    glutMainLoop();
}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,700,0,700);
}

void display()
{
    glColor3f(1,0,0);
    glRecti(10,30,60,90);
    glColor3f(0,1,0);
    glRecti(70,30,120,90);
    glColor3f(0,0,1);
    glRecti(130,30,180,90);

    glFlush();
}

Color getPixelColor(int x,int y)
{
    Color color;
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,&color);
    return color;
}

void flood_fill(int x, int y, Color old_color, Color new_color)
{
    Color color;
    color=getPixelColor(x,y);
    if((color.r == old_color.r) && (color.g == old_color.g) && (color.b == old_color.b))
    {
        putPixel(x,y,new_color);
        flood_fill(x+1,y,old_color,new_color);
        flood_fill(x,y+1,old_color,new_color);
        flood_fill(x-1,y,old_color,new_color);
        flood_fill(x,y-1,old_color,new_color);
    }
}

void putPixel(int x,int y,Color new_color)
{
    glColor3f(new_color.r,new_color.g,new_color.b);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();

    glFlush();
}



void dda(int x1,int y1,int x2,int y2)
{
    glColor3f(1,1,1);
    float dx,dy,dx1,dy1,len,x,y;
    int i=1;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(dx>=dy)
    {
        len=dx;
    }
    else
    {
        len=dy;
    }

    dx1=(x2-x1)/len;
    dy1=(y2-y1)/len;

    x=x1;
    y=y1;

    while(i<=len)
    {
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        x=x+dx1;
        y=y+dy1;
        i++;
    }
}

void key1(unsigned char key,int x,int y)
{
    dda(x1,y1,x2,y2);
    pt=2;
    glFlush();
}

void mouse1(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(pt == 0)
        {
            x1 = x;
            y1 = 700-y;
            x2 = x;
            y2 = 700-y;
            pt++;
        }
        else if(pt == 1)
        {
            dda(x1,y1,x,700-y);
            x1=x;
            y1=700-y;
        }
        else if(pt == 2)
        {
            color=getPixelColor(x,700-y);
            pt = 3;
        }

        else if(pt == 3)
        {
            pt = 2;
            Color old_Color={0.0,0.0,0.0};
            Color new_Color={color.r,color.g,color.b};
            flood_fill(x,700-y,old_Color,new_Color);
        }
    }
    glFlush();
}
