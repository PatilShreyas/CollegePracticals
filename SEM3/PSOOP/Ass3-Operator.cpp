/*Program for Operator Overloading*/

#include<iostream>
using namespace std;
	
class Complex
{
	public :
		int r,i;
		int div;
		
		Complex(){
			div = 0;
		}
		
		Complex(int x, int y)
		{
			r = x;
			i = y;
			div = 0;
		}
		
		void show()
		{
			char sign = '+';
			if(i < 0)
				sign = '\0';
			
			cout<<"\n("<<r<<sign<<i<<"i)";
			if(div){
				cout<<"/("<<div<<")";	
			}
		}
		
		Complex operator *(Complex t)
		{
			Complex tmp;
			tmp.r = (r*t.r) - (i*t.i);             
			tmp.i = (r*t.i) + (t.r*i);  
			return tmp;
		}
		
			Complex operator /(Complex t)
		{
			Complex tmp;
			tmp.r = (r*t.r) + (i*t.i);
			tmp.i = -(r*t.i) + (t.r*i);  
			tmp.div = (t.r*t.r) - (t.i*t.i);
			return tmp;
		}
		
		friend Complex operator +(Complex, Complex);
		friend Complex operator -(Complex, Complex);
};



int main()
{
	Complex c1(5,3), c2(2,6);
	Complex result;
	
	result = c1+c2;
	cout<<"\n\nAddition = ";
	result.show();
	
	result = c1-c2;
	cout<<"\n\nSubtraction =";
	result.show();
	
	result = c1*c2;
	cout<<"\n\nMultiplication =";
	result.show();
	
	result = c1/c2;
	cout<<"\n\nDivision =";
	result.show();
	
	cout<<"\n\n";
	
}

/*Operator + Oveloading for Addition */
Complex operator + (Complex c1, Complex c2)
{
	return Complex(c1.r+c2.r, c1.i+c2.i);
}

/*Operator - Oveloading for Subtraction */
Complex operator - (Complex c1, Complex c2)
{
	return Complex(c1.r - c2.r, c1.i - c2.i);
}

/*

Output:

Addition = 
(7+9i)

Subtraction =
(3-3i)

Multiplication =
(-8+36i)

Division =
(28-24i)/(-32)



*/
