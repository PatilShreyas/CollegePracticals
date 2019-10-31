#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<iostream>

using namespace std;

//Functions Declaration
void init();
void displayTriangle();
void displayRhombus();
void DDAT(float x1,float y1,float x2,float y2);
void DDAS(float x1,float y3,float x2,float y2);
void DDAR(float x1,float y3,float x2,float y2);
void DDASH(float x1,float y1,float x2,float y2);
//End

int main(int argc,char **argv)
{
    int choice;
    cout<<"\n1. Triangle ";
    cout<<"\n2. Rhombus";
    cout<<"\nEnter Your Choice :";

    cin>>choice;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Transformation - SEITB18272");
    init();
	if(choice == 1)
    {
        glutDisplayFunc(displayTriangle);
	}
	else
    {
        glutDisplayFunc(displayRhombus);
    }

	glutMainLoop();
}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-500,500,-500,500);
}

void displayRhombus()
{
    int ch;
    do
    {
        cout<<"\n=================================";
        cout<<"\n## Menu ##\n\n1.Scaling \n2.Rotation\n3.Shearing\n4.Translation\n\nEnter the Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                glClearColor(0.0,0.0,0.0,0.0);
                glClear(GL_COLOR_BUFFER_BIT);
                DDAS(-100,0,0,100);
                DDAS(0,100,200,100);
                DDAS(200,100,100,0);
                DDAS(100,0,-100,0);
                break;

            case 2:
                glClearColor(0.0,0.0,0.0,0.0);
                glClear(GL_COLOR_BUFFER_BIT);
                DDAR(-100,0,0,100);
                DDAR(0,100,200,100);
                DDAR(200,100,100,0);
                DDAR(100,0,-100,0);
                break;

            case 3:
                glClearColor(0.0,0.0,0.0,0.0);
                glClear(GL_COLOR_BUFFER_BIT);
                DDASH(-100,0,0,100);
                DDASH(0,100,200,100);
                DDASH(200,100,100,0);
                DDASH(100,0,-100,0);
                break;

            case 4:
                glClearColor(0.0,0.0,0.0,0.0);
                glClear(GL_COLOR_BUFFER_BIT);
                DDAT(-100,0,0,100);
                DDAT(0,100,200,100);
                DDAT(200,100,100,0);
                DDAT(100,0,-100,0);
                break;
       }
    }while(ch!=5);
    glFlush();
}

void displayTriangle()
{
    int ch;
    do
    {
        cout<<"\n=================================";
        cout<<"\n## Menu ##\n\n1.Scaling \n2.Rotation\n3.Shearing\n4.Translation\n\nEnter the Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                glClearColor(0.0,0.0,0.0,0.0);
                glClear(GL_COLOR_BUFFER_BIT);
                DDAS(0,60,-(sqrt(3)*60)/2,-60/2);
                DDAS(-(sqrt(3)*60)/2,-60/2,(sqrt(3)*60)/2,-60/2);
                DDAS((sqrt(3)*60)/2,-60/2,0,60);
                break;

            case 2:
                glClearColor(0.0,0.0,0.0,0.0);
                glClear(GL_COLOR_BUFFER_BIT);
                DDAR(0,60,-(sqrt(3)*60)/2,-60/2);
                DDAR(-(sqrt(3)*60)/2,-60/2,(sqrt(3)*60)/2,-60/2);
                DDAR((sqrt(3)*60)/2,-60/2,0,60);
                break;

            case 3:
                glClearColor(0.0,0.0,0.0,0.0);
                glClear(GL_COLOR_BUFFER_BIT);
                DDASH(0,60,-(sqrt(3)*60)/2,-60/2);
                DDASH(-(sqrt(3)*60)/2,-60/2,(sqrt(3)*60)/2,-60/2);
                DDASH((sqrt(3)*60)/2,-60/2,0,60);
                break;

            case 4:
                glClearColor(0.0,0.0,0.0,0.0);
                glClear(GL_COLOR_BUFFER_BIT);
                DDAT(0,60,-(sqrt(3)*60)/2,-60/2);
                DDAT(-(sqrt(3)*60)/2,-60/2,(sqrt(3)*60)/2,-60/2);
                DDAT((sqrt(3)*60)/2,-60/2,0,60);
                break;
        }
    }while(ch!=5);
    glFlush();
}

//Scaling
void DDAS(float x1,float y3,float x2,float y2)
{
	float deltaX;
	float deltaY;
	float length;
	float Xincr,Yincr;
	float x,y;

	deltaX=abs(x2-x1);
	deltaY=abs(y2-y3);

	if(deltaX>=deltaY)
	{
		length=deltaX;
	}
	else
	{
		length=deltaY;
	}

	Xincr=(x2-x1)/length;
	Yincr=(y2-y3)/length;

	x=x1;
	y=y3;

	int i=1;
	while(i<=length)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glVertex2i(x*3,y*2);
		x=x+Xincr;
		y=y+Yincr;
		i++;
	}
	glEnd();
	glFlush();
}

//Translation
void DDAT(float x1,float y3,float x2,float y2)
{
	float deltaX;
	float deltaY;
	float length;
	float Xincr,Yincr;
	float x,y;

	deltaX=abs(x2-x1);
	deltaY=abs(y2-y3);

	if(deltaX>=deltaY)
	{
		length=deltaX;
	}
	else
	{
		length=deltaY;
	}

	Xincr=(x2-x1)/length;
	Yincr=(y2-y3)/length;

	x=x1;
	y=y3;

	int i=1;
	while(i<=length)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glVertex2i(x+10,y+10);
		x=x+Xincr;
		y=y+Yincr;
		i++;
	}
	glEnd();
	glFlush();
}

//Rotation
void DDAR(float x1,float y3,float x2,float y2)
{
	float deltaX;
	float deltaY,c,d;
	float length;
	float Xincr,Yincr;
	float x,y;
	deltaX=abs(x2-x1);
	deltaY=abs(y2-y3);

	if(deltaX>=deltaY)
	{
		length=deltaX;
	}
	else
	{
		length=deltaY;
	}
	Xincr=(x2-x1)/length;
	Yincr=(y2-y3)/length;

	x=x1;
	y=y3;

	int i=1;
	while(i<=length)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		c=x*cos(45)+y*sin(45);
		d=-x*sin(45)+y*cos(45);
		glVertex2i(c,d);
		x=x+Xincr;
		y=y+Yincr;
		i++;
	}
	glEnd();
	glFlush();
}

//Shearing
void DDASH(float x1,float y3,float x2,float y2)
{
	float deltaX,a;
	float deltaY,c,d;
	float length;
	float Xincr,Yincr;
	float x,y;

	deltaX=abs(x2-x1);
	deltaY=abs(y2-y3);
	a=2;

	if(deltaX>=deltaY)
	{
		length=deltaX;
	}
	else
	{
		length=deltaY;
	}

	Xincr=(x2-x1)/length;
	Yincr=(y2-y3)/length;

	x=x1;
	y=y3;

	int i=1;
	while(i<=length)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glVertex2i(x+a*y,y);
		glVertex2i(x,x*a+y);
		x=x+Xincr;
		y=y+Yincr;
		i++;
	}
	glEnd();
	glFlush();
}
