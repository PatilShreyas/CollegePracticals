#include<iostream>
#include<GL/glut.h>
using namespace std;

int frame1=0;

void Init()
{
	glClearColor(0.6,0.9,1,0);
	gluOrtho2D(0,640,0,480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
}

void car()
{
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2d(20,160);
	glVertex2d(20,200);
	glVertex2d(100,200);
	glVertex2d(120,180);
	glVertex2d(120,160);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(80,200);
	glVertex2d(80,180);
	glVertex2d(120,180);
	glVertex2d(100,200);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2d(20,160);
	glVertex2d(20,200);
	glVertex2d(100,200);
	glVertex2d(120,180);
	glVertex2d(120,160);
	glEnd();

	glColor3f(0,0,0);		//wheels
	glPushMatrix();
	glTranslated(30,160,0);
	glutWireSphere(5,110,110);
	glPopMatrix();
	glPushMatrix();
	glTranslated(110,160,0);
	glutWireSphere(5,110,110);
	glPopMatrix();

	glFlush();
}

void doframe(int v)
{
	frame1++;
	glutPostRedisplay();
	glutTimerFunc(20,doframe,0);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0,0.75,0);
	glBegin(GL_TRIANGLES);	//mountains
	glVertex2d(0,300);
	glVertex2d(75,350);
	glVertex2d(150,300);

	glVertex2d(140,300);
	glVertex2d(230,350);
	glVertex2d(300,300);

	glVertex2d(340,300);
	glVertex2d(415,350);
	glVertex2d(490,300);

	glVertex2d(480,300);
	glVertex2d(570,350);
	glVertex2d(640,300);
	glEnd();

	glColor3f(0.5,1,0.5);	//surface
	glBegin(GL_POLYGON);
	glVertex2d(0,0);
	glVertex2d(0,300);
	glVertex2d(640,300);
	glVertex2d(640,0);
	glEnd();

	glColor3f(0,1,1);		//river
	glBegin(GL_POLYGON);
	glVertex2d(220,0);
	glVertex2d(300,300);
	glVertex2d(340,300);
	glVertex2d(400,0);
	glEnd();

	glColor3f(0.5,0.5,0.5);	//road
	glBegin(GL_POLYGON);
	glVertex2d(0,120);
	glVertex2d(0,160);
	glVertex2d(640,160);
	glVertex2d(640,120);
	glEnd();

	glColor3f(1,0,0.5);		//Building
	glBegin(GL_POLYGON);
	glVertex2d(10,160);
	glVertex2d(10,260);
	glVertex2d(45,300);
	glVertex2d(80,260);
	glVertex2d(80,160);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2d(45,220);
	glVertex2d(45,240);
	glEnd();

	glPushMatrix();    //Move car from left to right
	glTranslated((frame1 % 640),0,0);
	car();
	glPopMatrix();
	glFlush();

}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);

	glutCreateWindow("VEHICLE ANIMATION - Shreyas Patil");
	Init();
	glutDisplayFunc(Display);
	glutTimerFunc(100,doframe,0);
	glutMainLoop();
}
