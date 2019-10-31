#include<stdio.h>
#include<string.h>

void accept(char[10][10], int);
void display(char[10][10], int);
void bubbleSort(char[10][10], int);
void selectionSort(char[10][10], int);
void insertionSort(char[10][10], int);
int binary_search(char[10][10], int, int, char[]);
int binary_search_recursion(char[10][10], int, int, char[]);

int main()
{
	int choice, size, result;
	char str[10][10], key[10];

	do
	{
		printf("\n===========================");
		printf("\nMenu");
		printf("\n1.Accept String Array");
		printf("\n2.Display");
		printf("\n3.Bubble Sort");
		printf("\n4.Selection Sort");
		printf("\n5.Insertion Sort");
		printf("\n6.Binary Search");
		printf("\n7.Binary Search (Recursion)");
		printf("\n8.Exit");

		printf("\n\nEnter Choice :");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\n===========================");
				printf("\nEnter the Size :");
				scanf("%d",&size);
				accept(str,size);
				break;

			case 2:
				printf("\n===========================");
				printf("\nString Array :::");
				display(str,size);
				break;

			case 3:
				printf("\n===========================");
				printf("\nBubble Sort :::");
				bubbleSort(str,size-1);
				display(str,size);
				break;

			case 4:
				printf("\n===========================");
				printf("\nSelection Sort :::");
				selectionSort(str,size-1);
				display(str,size);
				break;

            case 5:
				printf("\n===========================");
				printf("\nInsertion Sort :::");
				insertionSort(str,size-1);
				display(str,size);
				break;
			case 6:
				printf("\nEnter the string to search :");
				scanf("%s",key);
				result = binary_search(str,0,size,key);
				if(result == -1)
					printf("%s is not found in array !!!", key);
				else
					printf("%s is found at %d position.\n",key,result);

				break;
            case 7:
                    printf("\nEnter the string to search :");
                    scanf("%s",key);
                    result = binary_search_recursion(str,0,size,key);
                    if(result == -1)
                        printf("%s is not found in array !!!", key);
                    else
                        printf("%s is found at %d position.\n",key,result);

                    break;
		}
	}while(choice != 8);
}

/* To accept array of string as input */
void accept(char str[10][10], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("Enter String %d : ",(i+1));
		scanf("%s",&str[i]);
	}
}

/* To display array of strings */
void display(char str[10][10], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("\nString %d : %s",(i+1), str[i]);
	}
}

/* Bubble sort of array */
void bubbleSort(char str[10][10], int size)
{
	int i,j;
	char temp[10];

	for(i=0; i<size; i++)
	{
		for(j=1; j<size; j++)
		{
			if(strcmp(str[j],str[j+1]) > 0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j], str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	printf("\nPasses = %d", i*j);
}

/* Selection sort of array */
void selectionSort(char str[10][10], int size)
{
	int i,j,k=0;
	char temp[10];

	for(i=0; i<size; i++)
	{
		k=i;
		for(j=i+1; j<size; j++)
		{
			if(strcmp(str[k],str[j]) > 0)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			strcpy(temp,str[i]);
			strcpy(str[i], str[k]);
			strcpy(str[k],temp);
		}
	}
	printf("\nPasses = %d", i*j);
}

/* Insertion sort of array */
void insertionSort(char s[10][10], int size)
{
    int i,j;
    char temp[10];
    for(i=1; i<size; i++)
    {
        strcpy(temp,s[i]);
        for(j=i-1; j>=0 && (strcmp(s[j], temp)>0); j--)
        {
            strcpy(s[j+1],s[j]);
            strcpy(s[j],temp);
        }
    }
    printf("\nPasses = %d",(i*j));
}

/* Binary search in array of string */
int binary_search(char s[10][10], int low, int high, char key[])
{
	int mid = (high+low)/2;

	while(strcmp(s[mid],key) != 0 && low<=high)
	{
	    if (strcmp(s[mid],key) == 0)
            return mid;

		if(strcmp(s[mid],key)>0)
			low = mid+1;
		else
			high = mid-1;

		mid = (low+high)/2;
	}

	if(strcmp(s[mid],key) == 0)
		return mid;
    else
        return -1;
}

/* Binary search in array of string using recursion*/
int binary_search_recursion(char s[10][10], int low, int high, char key[])
{
    int mid,k;
    if(low<=high)
    {
        mid = (low+high)/2;
        if(strcmp(s[mid],key) == 0)
            return mid;
        if(strcmp(s[mid],key)<0)
            return binary_search_recursion(s,mid+1,high,key);
        if(strcmp(s[mid],key)>0)
            return binary_search_recursion(s,low,mid-1,key);
    }
    return -1;
}


/*
**OUTPUT**


===========================
Menu
1.Accept String Array
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search
7.Binary Search (Recursion)
8.Exit

Enter Choice :1

===========================
Enter the Size :4
Enter String 1 : Hello
Enter String 2 : World
Enter String 3 : Shreyas
Enter String 4 : Patil

===========================
Menu
1.Accept String Array
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search
7.Binary Search (Recursion)
8.Exit

Enter Choice :2

===========================
String Array :::
String 1 : Hello
String 2 : World
String 3 : Shreyas
String 4 : Patil
===========================
Menu
1.Accept String Array
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search
7.Binary Search (Recursion)
8.Exit

Enter Choice :3

===========================
Bubble Sort :::
Passes = 9
String 1 : Hello
String 2 : Patil
String 3 : Shreyas
String 4 : World
===========================
Menu
1.Accept String Array
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search
7.Binary Search (Recursion)
8.Exit

Enter Choice :4

===========================
Selection Sort :::
Passes = 9
String 1 : Hello
String 2 : Patil
String 3 : Shreyas
String 4 : World

===========================
Menu
1.Accept String Array
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search
7.Binary Search (Recursion)
8.Exit

Enter Choice :5

===========================
Insertion Sort :::
Passes = 3
String 1 : Hello
String 2 : Patil
String 3 : Shreyas
String 4 : World
===========================
Menu
1.Accept String Array
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search
7.Binary Search (Recursion)
8.Exit

Enter Choice :6

Enter the string to search :Shreyas
Shreyas is found at 2 position.

===========================
Menu
1.Accept String Array
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search
7.Binary Search (Recursion)
8.Exit

Enter Choice :7

Enter the string to search :Patil
Patil is found at 1 position.

===========================
Menu
1.Accept String Array
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search
7.Binary Search (Recursion)
8.Exit

Enter Choice :8
*/
