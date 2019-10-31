//Assignment 2 - Draw Line using DDA Algorithm

#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>

using namespace std;

void initWindow(float,float,float,float);
void draw();
void drawDDA(int, int, int, int);

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutCreateWindow("WINDOW");
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
	
	drawDDA(-20,-20,50,50);
	
	glFlush();
}

//Function to draw a line using DDA Algorithm
void drawDDA(int x1, int y1, int x2, int y2)
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
	
	int x = x1 + 0.5*signbit(dx);
	int y = y1 + 0.5*signbit(dy);
	
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
