#include<stdio.h>
#include<stdlib.h>

int binary_search(int[], int, int, int);

int main(int argc, char *argv[], char *envp[])
{
	int i, key, pos;
	int array[argc];
	
	if (argc == 0)
	{
		printf("\nArray is empty!");
		return 0;
	}
	
	for (i = 0; i < argc-1; i++)
	{
		array[i] = atoi(argv[i]);
	}
	
	key = atoi(argv[i]);
	pos = binary_search(array, key, 0, argc-1);
	
	if (pos == -1)
	{
		printf("\nElement Not Found!\n");
	}
	else 
	{
		printf("\nElement Found at position %d\n",pos);
	}
	return 0;
}


// Function for binary search
int binary_search(int array[], int key, int low, int high)
{
	int mid = (low + high) / 2;
	if (array[mid] == key)
	{
		return mid;
	}
	else if (key < array[mid])
	{
		return binary_search(array, key, low, mid-1);
	} 
	else if (key > array[mid])
	{
		return binary_search(array, key, mid+1, high);
	}
	else 
	{
		return -1;
	}
}
