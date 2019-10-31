#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

// Functions Declarations
int read_array(int[]);
void show_array(int[], int);

void quick_sort(int[], int, int);
int partition(int[], int, int);
void swap(int*, int*);

void merge_sort(int[], int, int);
void merge(int[], int, int, int);

// End Declarations

int main()
{
    pid_t pid;
    int array[20], size;
    
    // Read array and show.
    size = read_array(array);
    show_array(array, size);
    
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
   	 printf("\n==============================");
   	 printf("\nCHILD PROCESS");
   	 printf("\n\n==============================");
   	 printf("\nProcess ID = %d", getpid());
   	 printf("\nParent Process ID = %d", getppid());
   	 printf("\n==============================");
   	 printf("\n");
   	 
   	 // Begin Process Task
   	 merge_sort(array, 0, size-1);    
   	 printf("\nElements After Merge Sorting:");
   	 show_array(array, size);
   	 
   	 printf("\nPausing Program for 3 Seconds...");
    }
    else
    {
   	 wait();    // Comment it to get defunct output.
   	 sleep(3);
   	 // Parent Process is created.
   	 printf("\n==============================");
   	 printf("\nPARENT PROCESS");
   	 printf("\n\n==============================");
   	 printf("\nProcess ID = %d", getpid());
   	 printf("\nParent Process ID = %d", getppid());
   	 printf("\n==============================");
   	 printf("\n");
   	 
   	 // Begin Process Task
   	 quick_sort(array, 0, size-1);
   	 printf("\nElements After Quick Sorting:");
   	 show_array(array, size);
    }
    printf("\n==============================");
    execl("/bin/ps","ps", NULL);
    
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

// Function to merge into arrays
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
   	 L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
   	 R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
   	 if (L[i] <= R[j])
   	 {
   		 arr[k] = L[i];
   		 i++;
   	 }
   	 else
   	 {
   		 arr[k] = R[j];
   		 j++;
   	 }
   	 k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
   	 arr[k] = L[i];
   	 i++;
   	 k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
   	 arr[k] = R[j];
   	 j++;
   	 k++;
    }
}
 
// Function to sort array using Merge Sort
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
   	 int m = l+(r-l)/2;

   	 // Sort first and second halves
   	 merge_sort(arr, l, m);
   	 merge_sort(arr, m+1, r);

   	 merge(arr, l, m, r);
    }
}

/* Output:

Output 1 (Without wait()) Zombie:
student@student-OptiPlex-3060:~/Desktop/Shreyas/Assignment2$ ./a.out

Enter the size of array: 4

Enter the Elements of Array:
1 2 3 4

    1    2    3    4

==============================
CHILD PROCESS

==============================
Process ID = 3057
Parent Process ID = 3056
==============================

Elements After Merge Sorting:
    1    2    3    4

Pausing Program for 3 Seconds...
  PID TTY      	TIME CMD
 2581 pts/18   00:00:00 bash
 3056 pts/18   00:00:00 a.out
 3057 pts/18   00:00:00 ps

==============================
PARENT PROCESS

==============================
Process ID = 3056
Parent Process ID = 2581
==============================

Elements After Quick Sorting:
    1    2    3    4

  PID TTY      	TIME CMD
 2581 pts/18   00:00:00 bash
 3056 pts/18   00:00:00 ps
 3057 pts/18   00:00:00 ps <defunct>


Output 2 (With wait()) Orphan:
student@student-OptiPlex-3060:~/Desktop/Shreyas/Assignment2$ ./a.out
Enter the size of array: 4

Enter the Elements of Array:
5 3 1 8

    5    3    1    8

==============================
CHILD PROCESS

==============================
Process ID = 3126
Parent Process ID = 3125
==============================

Elements After Merge Sorting:
    1    3    5    8

Pausing Program for 3 Seconds...
  PID TTY      	TIME CMD
 2581 pts/18   00:00:00 bash
 3125 pts/18   00:00:00 a.out
 3126 pts/18   00:00:00 ps

==============================
PARENT PROCESS

==============================
Process ID = 3125
Parent Process ID = 2581
==============================

Elements After Quick Sorting:
    1    3    5    8

  PID TTY      	TIME CMD
 2581 pts/18   00:00:00 bash
 3125 pts/18   00:00:00 ps

*/
