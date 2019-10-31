#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
using namespace std;
struct Type_rgb
	{
		float r;
		float g;
		float b;
	};

struct Type_rgb pixels[421*720], pattern[499];

void mandelbrotset()
{
    float x0,y0,x,y,xtemp;
    int iteration,max_iteration, loc=0;

    for(y0=-1;y0<1.1;y0=y0+0.005)
        for(x0=-2.5;x0<1.1;x0=x0+0.005)
        {
            x=0;
            y=0;
            iteration=0;
            max_iteration=500;
            while(((x*x)+(y*y) <(2*2)) && iteration < max_iteration)
            {
                xtemp=(x*x) -(y*y) +x0;
                y=(2*x*y)+y0;
                x=xtemp;
                iteration=iteration + 1;
            }
            if(iteration>=499)
            {
                pixels[loc].r=0;
                pixels[loc].g=0;
                pixels[loc].b=0;
            }
            else
            {
                pixels[loc].r=pattern[iteration].r;
                pixels[loc].g=pattern[iteration].g;
                pixels[loc].b=pattern[iteration].b;
            }
            loc=loc+1;
        }
}


void Init()
{
		glViewport(0,0,720,421);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0,720,0,421);

		int i;
		float r,g,b;


		for(i=0;i<720*421;i++)
        {
            pixels[i].r=1;
            pixels[i].g=1;
            pixels[i].b=1;
        }

		i=0;
		for(i=0.1;r<=0.8;r=r+0.1)
			for(i=0.1;g<=0.8;g=g+0.1)
				for(i=0.1;b<=0.8;b=b+0.1)
                {
                    pattern[i].r=b;
                    pattern[i].g=r;
                    pattern[i].b=g;
                    i++;
					}
		for(;i<=499;i++)
        {
            pattern[i].r=1;
            pattern[i].g=1;
            pattern[i].b=1;
        }
		mandelbrotset();
}

void onDisplay()
{
        glClearColor(1,1,1,0);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawPixels(720,421, GL_RGB, GL_FLOAT,pixels);
        glutSwapBuffers();
}


int main(int argc,char**argv)
{
        glutInit(&argc,argv);
        glutInitWindowSize(720,421);
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE |GLUT_DEPTH);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Mandelbrotset - Jagruti");
        Init();
        glutDisplayFunc(onDisplay);
        glutMainLoop();
        return 0;
}
