#include<stdio.h>

void accept(int[10][10], int, int);
void display(int[10][10], int, int);
void convert(int[10][10], int[10][3], int, int);
void displaySparse(int[10][3]);
void add(int[10][3], int[10][3], int[10][3]);
void simple_transpose(int [10][3], int[10][3]);
void fast_transpose(int[10][3], int[10][3]);

int main()
{
	int a[10][10], b[10][10];
	int s1[10][3], s2[10][3], s3[10][3];
	int row1, row2, col1, col2;
	int ch;
	int chm;

	do
	{
		printf("\n===============================");
		printf("\n\nMENU");
		printf("\n1.Accept & Display Matrix A\n2.Accept & Display Matrix B\n3.Convert Matrix A to Sparse Matrix & Display\n4.Convert Matrix B to Sparse Matrix & Display\n5.Addition\n6.Simple Transpose\n7.Fast Transpose\n8.Exit");

		printf("\n\nEnter your Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\nEnter Rows and Columns :");
				scanf("%d%d",&row1,&col1);
				printf("\nEnter the elements of %dX%d Matrix A:",row1,col1);
				accept(a,row1,col1);
				display(a,row1,col1);
				break;

			case 2:
				printf("\nEnter Rows and Columns :");
				scanf("%d%d",&row2,&col2);
				printf("\nEnter the elements of %dX%d Matrix B:",row2,col2);
				accept(b,row2,col2);
				display(b,row2,col2);
				break;


			case 3:
				convert(a,s1,row1,col1);
				printf("\nSparse Matrix from Matrix A :");
				displaySparse(s1);
				break;

			case 4:
				convert(b,s2,row2,col2);
				printf("\nSparse Matrix from Matrix B :");
				displaySparse(s2);
				break;

			case 5:
				printf("\nAddition of Sparse Matrices :");
				add(s1,s2,s3);
				displaySparse(s3);
				break;

			case 6:
				printf("\nWhich Matrix ? (A=1/B=2) :");
				scanf("%d",&chm);
				if(chm == 1)
					simple_transpose(s1,s3);
				else if(chm == 2)
					simple_transpose(s2,s3);
				else
					break;

				printf("\nSimple Transposition :");
				displaySparse(s3);
				break;

			case 7:
				printf("\nWhich Matrix ? (A=1/B=2) :");
				scanf("%d",&chm);
				if(chm == 1)
					fast_transpose(s1,s3);
				else if(chm == 2)
					fast_transpose(s2,s3);
				else
					break;

				printf("\nFast Transposition :");
				displaySparse(s3);
				break;


			case 8: printf("\n\nThank You !!\n\n"); break;
			default : printf("\nInvalid Choice !!\n");

		}
	}while(ch != 8);
	return 0;
}

/*Function to accept Simple Matrix */
void accept(int m[10][10], int r, int c)
{
	int i,j;
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
}

/*Function to Display Simple Matrix */
void display(int m[10][10], int r, int c)
{
	int i,j;
	for(i=0; i<r; i++)
	{
		printf("\n");
		for(j=0; j<c; j++)
		{
			printf("\t%d",m[i][j]);
		}
	}
}

/*Function to Convert Simple Matrix into Sparse Matrix*/
void convert(int m[10][10], int s[10][3], int r, int c)
{
	int i,j,k=1;

	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			if(m[i][j] != 0)
			{
				s[k][0] = i;
				s[k][1] = j;
				s[k][2] = m[i][j];
				k++;
			}
		}
	}

	s[0][0] = i;
	s[0][1] = j;
	s[0][2] = (k-1);
}

/*Function to display Sparse Matrix */
void displaySparse(int s[10][3])
{
	int i,j;
	int k = s[0][2]+1;
	for(i=0; i<k; i++)
	{
		printf("\n");
		printf("\t%d\t%d\t%d", s[i][0], s[i][1], s[i][2]);
	}
	printf("\n---------------------------------\n");
	printf("\n\n");
}

/*Function for addition of Sparse Matrices s1 and s2 and store it in s3*/
void add(int s1[10][3], int s2[10][3], int s3[10][3])
{
	int i=1, j=1, k=1;

	while(i<=s1[0][2] && j<=s2[0][2])
	{
		if(s1[i][0] < s2[j][0])
		{
			s3[k][0] = s1[i][0];
			s3[k][1] = s1[i][1];
			s3[k][2] = s1[i][2];
			i++;
			k++;
			goto last;
		}

		if(s1[i][0] > s2[j][0])
		{
			s3[k][0] = s2[j][0];
			s3[k][1] = s2[j][1];
			s3[k][2] = s2[j][2];
			j++;
			k++;
			goto last;
		}

		if(s1[i][1] < s2[j][1])
		{
			s3[k][0] = s1[i][0];
			s3[k][1] = s1[i][1];
			s3[k][2] = s1[i][2];
			i++;
			k++;
			goto last;
		}

		if(s1[i][1] > s2[j][1])
		{
			s3[k][0] = s2[j][0];
			s3[k][1] = s2[j][1];
			s3[k][2] = s2[j][2];
			j++;
			k++;
			goto last;
		}

		s3[k][0] = s1[i][0];
		s3[k][1] = s1[i][1];
		s3[k][2] = s1[i][2] + s2[j][2];

		i++;
		j++;
		k++;

		last:;
	}

	while(i <= s1[0][2])
	{
		s3[k][0] = s1[i][0];
		s3[k][1] = s1[i][1];
		s3[k][2] = s1[i][2];
		i++;
		k++;
	}

	while(j <= s2[0][2])
	{
		s3[k][0] = s2[j][0];
		s3[k][1] = s2[j][1];
		s3[k][2] = s2[j][2];
		j++;
		k++;
	}
	s3[0][0] = s1[0][0];
	s3[0][1] = s1[0][1];
	s3[0][2] = k-1;
}

/* Function for Simple Transposition Sparse Matrix */
void simple_transpose(int b1[10][3], int b2[10][3])
{
	int i,j,k,n;
    b2[0][0]=b1[0][1];
    b2[0][1]=b1[0][0];
    b2[0][2]=b1[0][2];

    k=1;
    n=b1[0][2];

    for(i=0;i<b1[0][1];i++)
        for(j=1;j<=n;j++)
            if(i==b1[j][1])
            {
                b2[k][0]=i;
                b2[k][1]=b1[j][0];
                b2[k][2]=b1[j][2];
                k++;
            }

}

/* Function for Fast Transposition Sparse Matrix */
void fast_transpose(int s[10][3], int t[10][3])
{
	int total[10]={0}, index[10], i, j, col=0, loc=0;
	for(i=1; i<s[0][2]; i++)
	{
		col = s[i][1];
		total[col]++;
	}
	index[0] = 1;
	for(i=1; i<s[0][2]; i++)
	{
		index[i] = index[i-1] + total[i-1];

	}

	for(i=1; i<=s[0][2]; i++)
	{
		col = s[i][1];
		loc = index[col];
		index[col]++;
		t[loc][0] = s[i][1];
		t[loc][1] = s[i][0];
		t[loc][2] = s[i][2];
		loc++;
	}
	t[0][0] = s[0][1];
	t[0][1] = s[0][1];
	t[0][2] = loc-1;
}
/*

**OUTPUT**

student@student-OptiPlex-330:~/Desktop/Shreyas/tmp$ gcc Ass8-Sparse.c
student@student-OptiPlex-330:~/Desktop/Shreyas/tmp$ ./a.out



===============================

MENU
1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Convert Matrix A to Sparse Matrix & Display
4.Convert Matrix B to Sparse Matrix & Display
5.Addition
6.Simple Transpose
7.Fast Transpose
8.Exit

Enter your Choice : 1

Enter Rows and Columns :3 3

Enter the elements of 3X3 Matrix A:1 0 6 7 0 8 0 0 9

        1       0       6
        7       0       8
        0       0       9
===============================

MENU
1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Convert Matrix A to Sparse Matrix & Display
4.Convert Matrix B to Sparse Matrix & Display
5.Addition
6.Simple Transpose
7.Fast Transpose
8.Exit

Enter your Choice : 2

Enter Rows and Columns :3 3

Enter the elements of 3X3 Matrix B:3 0 8 5 6 7 0 0 6

        3       0       8
        5       6       7
        0       0       6
===============================

MENU
1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Convert Matrix A to Sparse Matrix & Display
4.Convert Matrix B to Sparse Matrix & Display
5.Addition
6.Simple Transpose
7.Fast Transpose
8.Exit

Enter your Choice : 3

Sparse Matrix from Matrix A :
        3       3       5
        0       0       1
        0       2       6
        1       0       7
        1       2       8
        2       2       9
---------------------------------



===============================

MENU
1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Convert Matrix A to Sparse Matrix & Display
4.Convert Matrix B to Sparse Matrix & Display
5.Addition
6.Simple Transpose
7.Fast Transpose
8.Exit

Enter your Choice : 4

Sparse Matrix from Matrix B :
        3       3       6
        0       0       3
        0       2       8
        1       0       5
        1       1       6
        1       2       7
        2       2       6
---------------------------------



===============================

MENU
1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Convert Matrix A to Sparse Matrix & Display
4.Convert Matrix B to Sparse Matrix & Display
5.Addition
6.Simple Transpose
7.Fast Transpose
8.Exit

Enter your Choice : 5

Addition of Sparse Matrices :
        3       3       6
        0       0       4
        0       2       14
        1       0       12
        1       1       6
        1       2       15
        2       2       15
---------------------------------



===============================

MENU
1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Convert Matrix A to Sparse Matrix & Display
4.Convert Matrix B to Sparse Matrix & Display
5.Addition
6.Simple Transpose
7.Fast Transpose
8.Exit

Enter your Choice : 6

Which Matrix ? (A=1/B=2) :1

Simple Transposition :
        3       3       5
        0       0       1
        0       1       7
        2       0       6
        2       1       8
        2       2       9
---------------------------------



===============================

MENU
1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Convert Matrix A to Sparse Matrix & Display
4.Convert Matrix B to Sparse Matrix & Display
5.Addition
6.Simple Transpose
7.Fast Transpose
8.Exit

Enter your Choice : 7

Which Matrix ? (A=1/B=2) :2

Fast Transposition :
        3       3       6
        0       0       3
        0       1       5
        1       1       6
        2       0       8
        2       1       7
        2       2       6
---------------------------------



===============================

MENU
1.Accept & Display Matrix A
2.Accept & Display Matrix B
3.Convert Matrix A to Sparse Matrix & Display
4.Convert Matrix B to Sparse Matrix & Display
5.Addition
6.Simple Transpose
7.Fast Transpose
8.Exit

Enter your Choice : 8


Thank You !!


*/
