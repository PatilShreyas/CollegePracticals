#include <GL/glut.h>
#include<math.h>
#define sign(x) (x>0)?1:((x<0)?-1:0)
#define WIDTH 600
#define HEIGHT 500

float fillColor[3] = {0.0,0.0,0.0};
float initColor[3] = {1.0,1.0,1.0};

void setPixel(float x,float y, float color[3])
{
    glBegin(GL_POINTS);
    glColor3fv(color);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void getPixel(int x, int y, float pixels[3])
{
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);
}

void bres(float x1, float Y1, float x2, float y2)
{
	 float dx, dy, x, y, d, s1, s2, swap=0, temp;
	 float c,d1;
	 dx = abs(x2 - x1);
	 dy = abs(y2 - Y1);
	 s1 = sign(x2-x1);
	 s2 = sign(y2-Y1);

	 if(dy > dx)
	   {
	    	temp = dx;
	    	dx = dy;
	     	dy = temp;
	     	swap = 1;
    	}

  	d = 2 * dy - dx;
  	x = x1;
  	y = Y1;

  	for(int i=1; i<=dx; i++)
    {
        glBegin(GL_POINTS);

        c = x*cos(45*(3.14/180)) + y*sin(45*(3.14/180));
        d1 = -x*sin(45*(3.14/180)) + y*cos(45*(3.14/180));

        glVertex2f(c,d1);
        while(d >= 0)
        {
            if(swap) x = x + s1;
            else
            {
                y = y+s2;
                d = d-2*dx;
            }
        }

        if(swap)
            y = y + s2;
        else
            x = x + s1;

        d = d+2*dy;
    }
	glEnd();
  	glFlush();
}

void display()
{
    glColor3f(0.0, 0.0,0.0);

    //Outer Lines for Chess
            bres(50,350,250,350);
			bres(250,350,250,550);
			bres(250,550,50,550);
			bres(50,550,50,350);


			bres(50,400,250,400);
			bres(50,450,250,450);
			bres(50,500,250,500);

			bres(100,350,100,550);
			bres(150,350,150,550);
			bres(200,350,200,550);

    glFlush();

}

void flood_fill(int x,int y,float oldColor[3],float newColor[3])
{
    float color[3];
    getPixel(x,y,color);
    if(color[0]==oldColor[0] && (color[1])==oldColor[1] && (color[2])==oldColor[2])
    {
        setPixel(x,y,newColor);
        flood_fill(x+1,y,oldColor,newColor);
        flood_fill(x-1,y,oldColor,newColor);
        flood_fill(x,y+1,oldColor,newColor);
        flood_fill(x,y-1,oldColor,newColor);
    }
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        int xi = x;
        int yi = (500-y);

        flood_fill(xi,yi,initColor,fillColor);
     }
}

void init()
{
    glClearColor(1.0, 1.0,1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0.0,600,0.0,500);

}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Shreyas Patil (SEITB18272)");
    glutDisplayFunc(display);
    init();
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
