#include<stdio.h>

void accept(int*, int, int);
void display(int*, int, int);
void addMatrices(int*, int*, int*, int, int, int, int);
void subMatrices(int*, int*, int*, int, int, int, int);
void multiplyMatrices(int*, int*, int*, int, int, int, int);
void saddlePoint(int*, int, int);
void transpose(int*, int*, int, int);

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
        printf("\n4.Subtract Matrices");
		printf("\n5.Multiply Matrices");
		printf("\n6.Saddle Point");
		printf("\n7.Transpose Matrix");
		printf("\n8.Exit");
		printf("\n\nEnter your choice :");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Row and Column Size :");
				scanf("%d%d",&r1,&c1);
				printf("\nEnter elements for %dX%d Matrix :",r1,c1);
				accept(&a[0][0],r1,c1);
				display(&a[0][0],r1,c1);
				break;

			case 2:
				printf("\nEnter Row and Column Size :");
				scanf("%d%d",&r2,&c2);
				printf("\nEnter elements for %dX%d Matrix :",r2,c2);
				accept(&b[0][0],r2,c2);
				display(&b[0][0],r2,c2);
				break;

			case 3:
				addMatrices(&a[0][0],&b[0][0],&c[0][0],r1,c1,r2,c2);
				printf("\nAddition of Matrices (A+B) =\n");
				display(&c[0][0],r1,c1);
				break;

            case 4:
				subMatrices(&a[0][0],&b[0][0],&c[0][0],r1,c1,r2,c2);
				printf("\nSubtraction of Matrices (A+B) =\n");
				display(&c[0][0],r1,c1);
				break;

			case 5:
				multiplyMatrices(a,b,c,r1,c1,r2,c2);
				printf("\nMultiplication of Matrices (AXB) =\n");
				display(c,r1,c1);
				break;

			case 6:
				printf("\nSaddle Point of Matrix A :");
				saddlePoint(a,r1,c1);

				printf("\n\nSaddle Point of Matrix B :");
				saddlePoint(b,r1,c1);
				break;

            case 7:
                transpose(&a[0][0],&c[0][0],r1,c1);
                printf("\nTranspose of Matrix (A) =\n");
				display(c,r1,c1);
				break;

			case 8: printf("\n\nThank You !\n\n");break;
			default: printf("\nInvalid Choice !");
		}
	}while(choice != 8);
	return 0;
}

/* Function to read elements of matrix*/
void accept(int *m, int rows, int cols)
{
	int i,j;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			scanf("%d",m+(i*10+j));
		}
	}
}

/* Function to display elements of matrix */
void display(int *m, int rows, int cols)
{
	int i,j;
	printf("\n\nMatrix :");
	for(i=0; i<rows; i++)
	{
		printf("\n");
		for(j=0; j<cols; j++)
		{
			printf("\t%d",*(m+(i*10+j)));
		}
	}
}

/*Addition of Matrices using pointer */
void addMatrices(int *a, int *b, int *c, int rows1, int cols1, int rows2, int cols2)
{
	int i,j;
	if(rows1==rows2 && cols1==cols2)
	{
        for(i=0;i<rows1;i++)
        {
            for(j=0;j<cols1;j++)
            {
                *(c+(i*10+j)) = *(a+(i*10+j)) + *(b+(i*10+j));
            }
        }
	}
}

/*Addition of Matrices using pointer */
void subMatrices(int *a, int *b, int *c, int rows1, int cols1, int rows2, int cols2)
{
	int i,j;
	if(rows1==rows2 && cols1==cols2)
	{
        for(i=0;i<rows1;i++)
        {
            for(j=0;j<cols1;j++)
            {
                *(c+(i*10+j)) = *(a+(i*10+j)) - *(b+(i*10+j));
            }
        }
	}
}

/*For Multiplication of matrices using pointer*/
void multiplyMatrices(int *a, int *b, int *c, int rows1, int cols1, int rows2, int cols2)
{
    int i,j,k;

    if(rows1==cols2 && rows2==cols1)
	{
        for (i = 0; i < rows1; i++)
        {
            for (j = 0; j < cols2; j++)
            {
                *(c+(i*10+j)) = 0;
                for (k = 0; i < cols1; i++)
                {
                    (*(c+(i*10+j))) += (*(a+(i*10+k))) * (*(b+(k*10+j)));
                }

            }
        }
	}
	else
        printf("\nCan't Perform Multiplication");
}


/*To find Saddle point of matrix using pointer*/
void saddlePoint(int *a, int r, int c)
{
    int i,j,k,pos,min,max,flag=0;

	for(i=0; i<r; i++)
	{
		min = *(a+(i*10+0));

		for(j=0; j<c; j++)
		{
			if(min > *(a+(i*10+j)))
			{
				min = *(a+(i*10+j));
				pos = j;
			}
		}

		max = *(a+(10+pos));
		for(k=0; k<r; k++)
		{
			if(max < *(a+(k*10+pos)))
			{
				max = *(a+(k*10+pos));
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

/* Transpose of Matrix */
void transpose(int *a, int *b, int r, int c)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            *(b+(j*10+i)) = *(a+(i*10+j));
        }
    }
}

/*
    **OUTPUT**

student@student-OptiPlex-330:~/Desktop/Shreyas$ gcc Ass2B-Matrix.c
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out

==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Subtract Matrices
5.Multiply Matrices
6.Saddle Point
7.Transpose Matrix
8.Exit

Enter your choice :1

Enter Row and Column Size :2 2

Enter elements for 2X2 Matrix :1 4 7 9


Matrix :
        1       4
        7       9
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Subtract Matrices
5.Multiply Matrices
6.Saddle Point
7.Transpose Matrix
8.Exit

Enter your choice :2

Enter Row and Column Size :2 2

Enter elements for 2X2 Matrix :1 2 3 4


Matrix :
        1       2
        3       4
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Subtract Matrices
5.Multiply Matrices
6.Saddle Point
7.Transpose Matrix
8.Exit

Enter your choice :3

Addition of Matrices (A+B) =


Matrix :
        2       6
        10      13
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Subtract Matrices
5.Multiply Matrices
6.Saddle Point
7.Transpose Matrix
8.Exit

Enter your choice :4

Subtraction of Matrices (A+B) =


Matrix :
        0       2
        4       5
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Subtract Matrices
5.Multiply Matrices
6.Saddle Point
7.Transpose Matrix
8.Exit

Enter your choice :5

Multiplication of Matrices (AXB) =


Matrix :
        1       2
        11      5
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Subtract Matrices
5.Multiply Matrices
6.Saddle Point
7.Transpose Matrix
8.Exit

Enter your choice :6

Saddle Point of Matrix A :
Saddle Point doesn't exists
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Subtract Matrices
5.Multiply Matrices
6.Saddle Point
7.Transpose Matrix
8.Exit

Enter your choice :7

Transpose of Matrix (A) =


Matrix :
        1       7
        4       9
==========================

MENU

1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Add Matrices
4.Subtract Matrices
5.Multiply Matrices
6.Saddle Point
7.Transpose Matrix
8.Exit

Enter your choice :8


Thank You !



*/
