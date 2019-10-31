#include<iostream>
#include<GL/glut.h>
using namespace std;
int x1=0 ,Y1=0,x2=0,y2=-2;
float theta=60*(22/7)*180;
void pendulum();
void init()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-5,5,-5,5);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
	glutWireSphere(0.5, 20,40);
	glRotatef(theta,1,0,0);
	glRotatef(0,0,1,0);
	glRotatef(theta,0,0,1);
	pendulum();
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(600,600);
	glutCreateWindow("Shreyas");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}
void pendulum()
{
	glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2d(x1,Y1);
    glVertex2d(x2,y2);
    glEnd();
    glColor3f(0.0,1.0,1.0);
    glTranslatef(0.0,-2.0,0.0);
    glutSolidSphere(0.5, 20,40);
    if(theta>60)
        theta-=0.10;
    glFlush();
}
