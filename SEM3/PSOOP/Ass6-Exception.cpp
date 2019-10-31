#include<iostream>
using namespace std;

class Math
{
	double n1,n2;
	
	public:
	Math(double a, double b)
	{
		n1 = a;
		n2 = b;
	}
	
	void divide()
	{
		double div;
		try
		{
			if(n2 == 0)
			{
				throw 0;
			}
			div = n1/n2;
			cout<<"\nDivision ="<<div<<"\n\n";
		}
		catch(int e)
		{
			cout<<"\nArithmeticExcepion Occured ! Divide by Zero !\n\n";
		}
	}
};

int main()
{
	double n1,n2;
	cout<<"\nEnter 2 Numbers :";
	cin>>n1>>n2;
	
	Math math(n1,n2);
	
	math.divide();
	return 0;
}

/*

**OUTPUT :**

student@student-OptiPlex-330:~/Desktop/Shreyas/Shreyas_CPP$ g++ Exception.cpp
student@student-OptiPlex-330:~/Desktop/Shreyas/Shreyas_CPP$ ./a.out

Enter 2 Numbers :10 0

ArithmeticExcepion Occured ! Divide by Zero !


*/
