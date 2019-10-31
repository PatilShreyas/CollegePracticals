#include<iostream>
#include<GL/glut.h>
#include<stdio.h>
//#include<math.h>
using namespace std;
float n;
float x1=100,y1=100,x2=400,y2=100;
void getdata()
{

    cout<<"enter nos interation";
    cin>>n;
}

void koch(float x1,float y1,float x2,float y2,float n)
{
	//float ang=60;ang=ang*3.14/180;
	float x3=(2*x1+x2)/3;
	float y3=(2*y1+y2)/3;
	float x4=(x1+2*x2)/3;
	float y4=(y1+2*y2)/3;
	float x=x3+(x4-x3)*0.5+(y4-y3)*0.8660;
	float y=y3-(x4-x3)*0.8660+(y4-y3)*0.5;
	if(n>0)
	{
		koch(x1,y1,x3,y3,n-1);
		koch(x3,y3,x,y,n-1);
		koch(x,y,x4,y4,n-1);
		koch(x4,y4,x2,y2,n-1);
	}
	else
	{
		glBegin(GL_LINE_STRIP);
		glClearColor(1.0,1.0,1.0,0.0);
		glColor3f(0.0,1.0,1.0);
		glVertex2f(x1,y1);
		glColor3f(0.0,1.0,1.0);
		glVertex2f(x3,y3);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(x,y);
		glColor3f(1.0,0.0,1.0);
		glVertex2f(x4,y4);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(x2,y2);
		glEnd();

	}
}
void Init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0.0,640.0,480.0,0.0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	koch(x1,y1,x2,y2,n);
	glFlush();
}
int main(int argv,char **argc)
{

	getdata();

	glutInit(&argv,argc);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Shreyas");
	Init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
