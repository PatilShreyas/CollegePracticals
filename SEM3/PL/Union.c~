/* Program for SET Operations */

#include<stdio.h>

void accept(int[], int);
void display(int[], int);
int intersection(int[], int, int[], int, int[], int);
int unionset(int[], int, int[], int, int[], int);
int difference(int[], int, int[], int, int[], int);
int symdifference(int[], int, int[], int, int[], int);

int main()
{
	int choice,sizeA,sizeB,sizeC=0;
	int a[20], b[20], c[20];
	
	do{
		printf("\n===============================================\n");
		printf("\nMENU");
		printf("\n1.Accept & Display Set 1\n2.Accept & Display Set 2");
		printf("\n\n :OPERATIONS:\n3.Intersection\n4.Union\n5.Difference\n6.Symmetric Difference");
		printf("\n\n7.Exit");
	
		printf("\n\nEnter Choice :");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: 
					printf("\nEnter the Total No of Elements of Set A:");
					scanf("%d",&sizeA);
					printf("\nEnter the elements of SET A :");
					accept(a,sizeA);
					printf("----------------------------------------");
					printf("\n\nElements of SET A :");
					display(a,sizeA);
					printf("----------------------------------------");
					break;
			case 2: 
					printf("\nEnter the Total No of Elements of Set B:");
					scanf("%d",&sizeB);
					printf("\nEnter the elements of SET B :");
					accept(b,sizeB);
					printf("----------------------------------------");
					printf("\n\nElements of SET B :");
					display(b,sizeB);
					printf("----------------------------------------");
					break;
					
			case 3:	sizeC = 0;
					sizeC = intersection(a,sizeA,b,sizeB,c, sizeC);
					printf("----------------------------------------");
					printf("\n\nIntersection of SET A&B :");
					display(c,sizeC);
					printf("----------------------------------------");
					break;
					
			case 4:	sizeC = 0;
					sizeC = unionset(a,sizeA,b,sizeB,c, sizeC);
					printf("----------------------------------------");
					printf("\n\nUnion of SET A&B :");
					display(c,sizeC);
					printf("----------------------------------------");
					break;
					
			case 5: sizeC = 0;
					sizeC = difference(a,sizeA,b,sizeB,c, sizeC);
					printf("----------------------------------------");
					printf("\n\nDifference of SET A&B :");
					display(c,sizeC);
					printf("----------------------------------------");
					break;
					
			case 6: sizeC = 0;
					sizeC = symdifference(a,sizeA,b,sizeB,c, sizeC);
					printf("----------------------------------------");
					printf("\n\nSymmetric Difference of SET A&B :");
					display(c,sizeC);
					printf("----------------------------------------");
					break;
			
		    default : printf("\n\nPlease Enter Correct Option !");
		}
	}while(choice != 7);
	return 0;
}

/* To accept set data */
void accept(int array[20], int n)
{
	int i,j;
	for(i=0; i<n; i++)
	{
		printf("\nEnter Number %d : ",(i+1));
		scanf("%d", &array[i]);
		
		for(j=0; j<i; j++)
		{
			if(array[i]==array[j])
			{
				printf("\nREPEATATION OCCURED ! Enter another number...\n");
				i--;
			}
		}
	}
}

/* To display Sets */
void display(int array[20], int n)
{
	int i;
	printf("\n{");
	for(i=0; i<n; i++)
	{
		printf("%d",array[i]);
		if(i!=(n-1))
		{
			printf(",");
		}
	}
	printf("}\n");
	printf("\n===============================================\n");
}

/* To find intersection of Sets */
int intersection(int a[20], int aSize, int b[20], int bSize, int c[], int cSize)
{
	int i,j;
	for(i=0;i<aSize; i++)
	{
		for(j=0; j<bSize; j++){
			if(a[i] == b[j])
			{
				c[cSize] = a[i];
				cSize++;
			}
		}
	}	
	return cSize;
}

/* To find difference of Sets */
int difference(int a[20], int aSize, int b[20], int bSize, int c[20], int cSize)
{
	int flag;
	int i,j;
	
	for(i=0; i<aSize; i++)
	{
		flag = 0;
		for(j=0; j<bSize; j++)
		{
			if(a[i] == b[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag != 1)
		{
			c[cSize] = a[i];
			cSize++;
		}
	}
	return cSize;
}

/* To find Union of Sets */
int unionset(int a[], int aSize, int b[], int bSize, int c[], int cSize)
{
	cSize = difference(a,aSize,b,bSize,c,cSize);
	cSize = intersection(a,aSize,b,bSize,c,cSize);
	cSize = difference(b,bSize,a,aSize,c,cSize);
	
	return cSize;
}

/* To find symmetric difference of Sets */
int symdifference(int a[], int aSize, int b[], int bSize, int c[], int cSize)
{
	cSize = difference(a,aSize,b,bSize,c,cSize);
	cSize = difference(b,bSize,a,aSize,c,cSize);

	return cSize;
}


/*
	**OUTPUT**
	
student@student-OptiPlex-330:~/Desktop/Shreyas$ gcc Union.c
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out

===============================================

MENU
1.Accept & Display Set 1
2.Accept & Display Set 2

 :OPERATIONS:
3.Intersection
4.Union
5.Difference
6.Symmetric Difference

7.Exit

Enter Choice :1

Enter the Total No of Elements of Set A:3

Enter the elements of SET A :
Enter Number 1 : 1

Enter Number 2 : 2

Enter Number 3 : 3
----------------------------------------

Elements of SET A :
{1,2,3}

===============================================
----------------------------------------
===============================================

MENU
1.Accept & Display Set 1
2.Accept & Display Set 2

 :OPERATIONS:
3.Intersection
4.Union
5.Difference
6.Symmetric Difference

7.Exit

Enter Choice :2

Enter the Total No of Elements of Set B:3

Enter the elements of SET B :
Enter Number 1 : 3 

Enter Number 2 : 4

Enter Number 3 : 5
----------------------------------------

Elements of SET B :
{3,4,5}

===============================================
----------------------------------------
===============================================

MENU
1.Accept & Display Set 1
2.Accept & Display Set 2

 :OPERATIONS:
3.Intersection
4.Union
5.Difference
6.Symmetric Difference

7.Exit

Enter Choice :3
----------------------------------------

Intersection of SET A&B :
{3}

===============================================
----------------------------------------
===============================================

MENU
1.Accept & Display Set 1
2.Accept & Display Set 2

 :OPERATIONS:
3.Intersection
4.Union
5.Difference
6.Symmetric Difference

7.Exit

Enter Choice :4
----------------------------------------

Union of SET A&B :
{1,2,3,4,5}

===============================================
----------------------------------------
===============================================

MENU
1.Accept & Display Set 1
2.Accept & Display Set 2

 :OPERATIONS:
3.Intersection
4.Union
5.Difference
6.Symmetric Difference

7.Exit

Enter Choice :5
----------------------------------------

Difference of SET A&B :
{1,2}

===============================================
----------------------------------------
===============================================

MENU
1.Accept & Display Set 1
2.Accept & Display Set 2

 :OPERATIONS:
3.Intersection
4.Union
5.Difference
6.Symmetric Difference

7.Exit

Enter Choice :6
----------------------------------------

Symmetric Difference of SET A&B :
{1,2,4,5}

===============================================
----------------------------------------
===============================================

MENU
1.Accept & Display Set 1
2.Accept & Display Set 2

 :OPERATIONS:
3.Intersection
4.Union
5.Difference
6.Symmetric Difference

7.Exit

Enter Choice :7

*/
