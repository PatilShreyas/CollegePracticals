//Assignment 2 - Draw Line using DDA Algorithm

#include<GL/gl.h>
#include<GL/glut.h>

void initWindow(float,float,float,float);
void draw();

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
	
	dda()
	
	glFlush();
}

void dda(int x1, int y1, int x2, int y2)
{
	int dx = Abs(x2 - x1);
}
