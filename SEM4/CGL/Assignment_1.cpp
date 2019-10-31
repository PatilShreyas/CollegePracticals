//Assignment 1 - Draw Square on Window

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
	
	glBegin(GL_LINES);

	glVertex2i(-50,-50);
	glVertex2i(-50,50);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2i(-50,50);
	glVertex2i(50,50);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2i(50,50);
	glVertex2i(50,-50);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2i(50,-50);
	glVertex2i(-50,-50);
	glEnd();
	
	glFlush();
}
