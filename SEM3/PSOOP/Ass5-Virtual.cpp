#include<iostream>
using namespace std;

class Shape
{
	public:
		double dim1, dim2;
		
		public:
		void setDimensions(double d1, double d2)
		{
			dim1 = d1;
			dim2 = d2;
		}
		
	 	virtual void area() = 0;
};

class Rectangle : public Shape
{
	public:
		void area()
		{
			cout<<"\nArea of Rectangle :"<<(dim1*dim2)<<"sq.m.\n";
		}
};

class Triangle : public Shape
{
	public:
		void area()
		{
			cout<<"\nArea of Triangle :"<<((dim1*dim2)/2)<<"sq.m.\n";
		}
};


int main()
{
	int dim1,dim2;
	Shape *shape;
	
	//For RECTANGLE
     shape = new Rectangle();
	cout<<"\nEnter Width & Height of Rectangle :";
	cin>>dim1>>dim2;
	shape->setDimensions(dim1, dim2);
	shape->area();
	
	//For TRIANGLE
	shape = new Triangle();
	cout<<"\nEnter Base & Height of Triangle :";
	cin>>dim1>>dim2;
	shape->setDimensions(dim1, dim2);
	shape->area();
	
	return 0;
}
/*
	**OUTPUT**
	
student@student-OptiPlex-330:~/Programs$ g++ Ass5-Virtual.cpp
student@student-OptiPlex-330:~/Programs$ ./a.out

Enter Width & Height of Rectangle :10 20
Area of Rectangle :200sq.m.

Enter Base & Height of Triangle :30 40
Area of Triangle :600sq.m.
*/
