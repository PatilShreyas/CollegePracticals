#include<stdio.h>

void accept(int[5][5], int, int);
void display(int[5][5], int, int);
void addMatrices(int[5][5], int[5][5], int[5][5], int, int, int, int);
void multiplyMatrices(int[5][5], int[5][5], int[5][5], int, int, int, int);
void saddlePoint(int[5][5], int, int);
void transpose(int[5][5], int[5][5], int, int);


int main()
{
	int a[5][5], b[5][5], c[5][5];
	int r1,r2,r3,c1,c2,c3;
	int choice;
	int ch;

	do
	{
		printf("\n==========================");
		printf("\n\nMENU");
		printf("\n\n1.Accept & Display Matrix A");
		printf("\n2.Accept & Display Matrix B");
		printf("\n3.Add Matrices");
		printf("\n4.Multiply Matrices");
		printf("\n5.Saddle Point");
		printf("\n6.Transpose");
		printf("\n7.Exit");
		printf("\n\nEnter your choice :");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Row and Column Size :");
				scanf("%d%d",&r1,&c1);
				printf("\nEnter elements for %dX%d Matrix :",r1,c1);
				accept(a,r1,c1);
				display(a,r1,c1);
				break;

			case 2:
				printf("\nEnter Row and Column Size :");
				scanf("%d%d",&r2,&c2);
				printf("\nEnter elements for %dX%d Matrix :",r2,c2);
				accept(b,r2,c2);
				display(b,r2,c2);
				break;

			case 3:
				addMatrices(a,b,c,r1,c1,r2,c2);
				printf("\nAddition of Matrices (A+B) =\n");
				display(c,r1,c1);
				break;

			case 4:
				multiplyMatrices(a,b,c,r1,c1,r2,c2);
				printf("\nMultiplication of Matrices (AXB) =\n");
				display(c,r1,c1);
				break;

			case 5:
				printf("\nSaddle Point of Matrix A :");
				saddlePoint(a,r1,c1);

				printf("\n\nSaddle Point of Matrix B :");
				saddlePoint(b,r1,c1);
				break;

            case 6:
                printf("\nTranspose of Matrix A :");
                transpose(a,c,r1,c1);
                display(c,r1,c1);

                printf("\nTranspose of Matrix B :");
                transpose(b,c,r2,c2);
                display(c,r2,c2);
                break;

			case 7: printf("\n\nThank You !\n\n");break;
			default: printf("\nInvalid Choice !");
		}
	}while(choice != 7);
	return 0;
}

/* Function to read elements of matrix*/
void accept(int m[5][5], int rows, int cols)
{
	int i,j;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
}

/* Function to display elements of matrix */
void display(int m[5][5], int rows, int cols)
{
	int i,j;
	printf("\n\nMatrix :");
	for(i=0; i<rows; i++)
	{
		printf("\n");
		for(j=0; j<cols; j++)
		{
			printf("\t%d",m[i][j]);
		}
	}
}

/* Function for addition of two matrices */
void addMatrices(int a[5][5], int b[5][5], int c[5][5], int r1, int c1, int r2, int c2)
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
		printf("\nCan't Perform Addition");
	}

}

/* Function for multiplication of two matrices */
void multiplyMatrices(int a[5][5], int b[5][5], int c[5][5], int r1, int c1, int r2, int c2)
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
		printf("\nCan't Perform Multiplication");
	}
}

/* Function to check if saddle point exists or not in matrix */
void saddlePoint(int a[5][5], int rows, int cols)
{
	int i,j,k,pos1,pos2,min,max,flag=0;

	for(i=0; i<rows; i++)
	{
		min = a[i][0];

		for(j=1; j<cols; j++)
		{
			if(min > a[i][j])
			{
				min = a[i][j];
				pos1 = j;
			}
		}

		max = a[0][pos1];
		for(k=1; k<rows; k++)
		{
			if(max < a[k][pos1])
			{
				max = a[k][pos1];
				pos2 = k;
			}
		}

		if(min == max)
		{
			flag = 1;
			printf("\nSaddle Point Exists\n");
		}
	}
	if(flag == 0)
	{
		printf("\nSaddle Point doesn't exists");
	}
}

/* To Make transpose of matrix */
void transpose(int m[5][5], int t[5][5], int r, int c)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            t[j][i] = m[i][j];
        }
    }
}

/*

**OUTPUT**

student@student-OptiPlex-330:~/Desktop/Shreyas$ gcc Ass2A-Matrix.c
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out

==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Saddle Point
6.Transpose
7.Exit

Enter your choice :1

Enter Row and Column Size :3 3

Enter elements for 3X3 Matrix :3 4 1 5 6 7 3 8 4


Matrix :
	3	4	1
	5	6	7
	3	8	4
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Saddle Point
6.Transpose
7.Exit

Enter your choice :2

Enter Row and Column Size :3 3

Enter elements for 3X3 Matrix :6 4 2 1 5 7 2 4 5


Matrix :
	6	4	2
	1	5	7
	2	4	5
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Saddle Point
6.Transpose
7.Exit

Enter your choice :3

Addition of Matrices (A+B) =


Matrix :
	9	8	3
	6	11	14
	5	12	9
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Saddle Point
6.Transpose
7.Exit

Enter your choice :4

Multiplication of Matrices (AXB) =


Matrix :
	24	36	39
	50	78	87
	34	68	82
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Saddle Point
6.Transpose
7.Exit

Enter your choice :5

Saddle Point doesn't exists
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Saddle Point
6.Transpose
7.Exit

Enter your choice :8

Saddle Point of Matrix A :
Saddle Point doesn't exists

Saddle Point of Matrix B :
Saddle Point doesn't exists
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Saddle Point
6.Transpose
7.Exit

Enter your choice :6

Transpose of Matrix A :

Matrix :
        3       5       3
        4       6       8
        1       7       4
Transpose of Matrix B :

Matrix :
        6       1       2
        4       5       4
        2       7       5
MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Multiply Matrices
5.Saddle Point
6.Exit

Enter your choice :9


Thank You !


*/
