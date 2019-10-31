#include<iostream>
using namespace std;

/* Function to read elements of matrix*/
template <class M>
void accept(M m[5][5], int rows, int cols)
{
	int i,j;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			cin>>m[i][j];
		}
	}
}

/* Function to display elements of matrix */
template <class M>
void display(M m[5][5], int rows, int cols)
{
	int i,j;
	cout<<"\n\nMatrix :";
	for(i=0; i<rows; i++)
	{
		cout<<"\n";
		for(j=0; j<cols; j++)
		{
			cout<<"\t"<<m[i][j];
		}
	}
}

/* Function for addition of two matrices */
template <class M, class N, class S>
void addMatrices(M a[5][5], N b[5][5], S c[5][5], int r1, int c1, int r2, int c2)
{
	int i,j;
	
	if(r1==r2 && c1==c2)
	{
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
			{
				c[i][j] = a[i][j] + b[i][j];
			}
		}
	}
	else
	{
		cout<<"\nCan't Perform Addition";
	}

}

/* Function for multiplication of two matrices */
template <class M, class N, class S>
void multiplyMatrices(M a[5][5], N b[5][5], S c[5][5], int r1, int c1, int r2, int c2)
{
	int i,j,k;
	if(r1==c2 && r2==c1)
	{
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c2; j++)
			{
				c[i][j] = 0;
				for(k=0; k<c1; k++)
				{
					c[i][j] = c[i][j] + a[i][k] * b[k][j];
				}
			}
		}
	}
	else
	{
		cout<<"\nCan't Perform Multiplication";
	}
}

int main()
{
	int a[5][5];
	float b[5][5];
	double c[5][5];
	int r1,r2,r3,c1,c2,c3;
	int choice;
	int ch;
	
	do
	{
		cout<<"\n==========================";
		cout<<"\n\nMENU";
		cout<<"\n\n1.Accept & Display Matrix A";
		cout<<"\n2.Accept & Display Matrix B";
		cout<<"\n3.Add Matrices";
		cout<<"\n4.Multiply Matrices";
		cout<<"\n5.Exit";
		cout<<"\n\nEnter your choice :";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter Row and Column Size :";
				cin>>r1>>c1;
				cout<<"\nEnter elements for Matrix :";
				accept(a,r1,c1);
				display(a,r1,c1);
				break;
				
			case 2:
				cout<<"\nEnter Row and Column Size :";
				cin>>r2>>c2;
				cout<<"\nEnter elements for Matrix :";
				accept(b,r2,c2);
				display(b,r2,c2);
				break;
				
			case 3:
				addMatrices(a,b,c,r1,c1,r2,c2);
				cout<<"\nAddition of Matrices (A+B) =\n";
				display(c,r1,c1);
				break;
				
			case 4:
				multiplyMatrices(a,b,c,r1,c1,r2,c2);
				cout<<"\nMultiplication of Matrices (AXB) =\n";
				display(c,r1,c1);
				break;
				
			case 5: cout<<"\n\nThank You !\n\n";break;
			default: cout<<"\nInvalid Choice !";
		}
	}while(choice != 5);
	return 0;
}

/*
	** OUTPUT**
	
student@student-OptiPlex-330:~/Programs$ g++ Ass7-Template.cpp
student@student-OptiPlex-330:~/Programs$ ./a.out

==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Exit

Enter your choice :1

Enter Row and Column Size :2
2

Enter elements for Matrix :1 2 3 4


Matrix :
	1	2
	3	4
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Exit

Enter your choice :2

Enter Row and Column Size :2 2

Enter elements for Matrix :1.1 2.2 3.3 4.4


Matrix :
	1.1	2.2
	3.3	4.4
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Exit

Enter your choice :3

Addition of Matrices (A+B) =


Matrix :
	2.1	4.2
	6.3	8.4
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Exit

Enter your choice :4

Multiplication of Matrices (AXB) =


Matrix :
	7.7	11
	16.5	24.2
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Exit

Enter your choice :5


Thank You !



*/
