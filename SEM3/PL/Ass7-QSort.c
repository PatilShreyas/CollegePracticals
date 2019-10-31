#include<stdio.h>

/* Function to input the numbers in array */
void accept(int a[], int size)
{	
	int i;
	printf("\nEnter The %d Numbers :", size);
	for(i=0; i<size; i++)
	{
		scanf("%d",&a[i]);
	}
}

/* Function to display the numbers in array */
void display(int a[], int size)
{	
	int i;
	for(i=0; i<size; i++)
	{
		printf("\n%d",a[i]);
	}
}

/* Swap function to swap numbers */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Function for applying quick sort logic on array */
void quick_sort(int a[], int low, int high)
{
	int pos;
	if(low<high)
	{
		pos = partition(a,low,high);
		quick_sort(a,low,pos-1);
		quick_sort(a,pos+1,high);
	}
}

/*Function for partition of array */
int partition(int a[], int low, int high)
{
	int pivot = a[low], temp, i, j;
	i = low+1;
	j = high;
	while(i<=j)
	{
		while(a[i] < pivot)
		{
			i++;
		}	
		while(a[j] > pivot)
		{
			j--;
		}
	
		if(i<j)
		{
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[low],&a[j]);
	

	return j;
}


/*Main Function*/
int main()
{
	int choice;
	int a[10], size;
	
	do
	{
		printf("\n==========================");
		printf("\nMENU");
		printf("\n1.Accept Array\n2.Display Array\n3.Quick Sort Array\n4.Exit");
		printf("\n\nEnter Choice :");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter Size of array : ");
				scanf("%d",&size);
				accept(a,size);
				break;
				
			case 2:
				printf("\n==========================");
				printf("\nArray :");
				display(a,size);
				break;
				
			case 3:
				printf("\n==========================");
				printf("\nQuick Sort :");
				quick_sort(a,0,(size-1));
				display(a,size);
				break;
				
			case 4: printf("\nExiting\n");break;
			default:printf("\nINVALID CHOICE !!!\n");
				
		}
	}while(choice != 4);
}

/*
	**OUTPUT**
	
student@student-OptiPlex-330:~/Desktop/Shreyas$ gcc Ass7-QSort.c
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out

==========================
MENU
1.Accept Array
2.Display Array
3.Quick Sort Array
4.Exit

Enter Choice :1

Enter Size of array : 7

Enter The 7 Numbers :6 2 9 0 1 3 10

==========================
MENU
1.Accept Array
2.Display Array
3.Quick Sort Array
4.Exit

Enter Choice :2

==========================
Array :
6
2
9
0
1
3
10
==========================
MENU
1.Accept Array
2.Display Array
3.Quick Sort Array
4.Exit

Enter Choice :3

==========================
Quick Sort :
0
1
2
3
6
9
10
==========================
MENU
1.Accept Array
2.Display Array
3.Quick Sort Array
4.Exit

Enter Choice :4

Exiting

*/
