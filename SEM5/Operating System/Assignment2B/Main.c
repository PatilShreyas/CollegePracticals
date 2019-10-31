#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>

// Functions Declarations
int read_array(int[]);
void show_array(int[], int);
void quick_sort(int[], int, int);
int partition(int[], int, int);
void swap(int*, int*);

// End Declarations

int main(int argc, char *argv[])
{
	pid_t pid;
	int array[20], size, pos, i;
	char *m[30] = {NULL}, *b[30];
	
	// Read array and show.
	size = read_array(array);
	show_array(array, size);

	// Begin Process
	quick_sort(array, 0, size-1);
	printf("\nElements After Quick Sorting:");
	show_array(array, size);
                 
	printf("\nEnter the element to search: ");
	scanf("%d", &array[size]);

	// 
	for (i = 0; i < size + 1; i++)
	{
		char arr[sizeof(int)];
		snprintf(arr, sizeof(int), "%d", array[i]);
		b[i] = malloc(sizeof(arr));
		strcpy(b[i], arr);
	}
	b[i] = NULL;
		
	// Fork Process
	pid = fork();

	if (pid < 0) 
	{
		// Error Occurred.
		printf("\nError occurred while creating a process!");
	}
	else if (pid == 0)
	{
		// Child Process is created.
		execve(argv[1], b, m);
		perror("Error in execve() call");
		
	}
	return 0;
}

// Function to read elements in array.
int read_array(int array[])
{
	int i, size;
	printf("\nEnter the size of array: ");
	scanf("%d", &size);

	printf("\nEnter the Elements of Array: \n");
	for (i = 0; i < size; i++)
	{
		scanf("%d", &array[i]);
	}
	
	return size;
}

// Function to display array.
void show_array(int array[], int size)
{
	int i;
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("\t%d", array[i]);
	}
	printf("\n");
}

// Function to sort elements using Quick Sort
void quick_sort(int array[], int low, int high)
{
	int pivot;
	if (low < high) 
	{ 
		pivot = partition(array, low, high); 

		quick_sort(array, low, pivot - 1); 
		quick_sort(array, pivot + 1, high); 
	}
}

// Function to partition array
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high];
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] <= pivot) 
		{ 
			i++;   
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

// Function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* OUTPUT:
student@student-OptiPlex-3060:~/Desktop/Shreyas/Assignment2$ gcc Assignment-2B.c -o b1
student@student-OptiPlex-3060:~/Desktop/Shreyas/Assignment2$ gcc BinarySearch.c -o b2
student@student-OptiPlex-3060:~/Desktop/Shreyas/Assignment2$ ./b1 ./b2

Enter the size of array: 5

Enter the Elements of Array: 
10 5 11 90 55

	10	5	11	90	55

Elements After Quick Sorting:
	5	10	11	55	90

Enter the element to search: 11

Element Found at position 2

*/
