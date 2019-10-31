#include<stdio.h>

struct Employee
{
	int emp_id;
	char fName[20];
	char lName[20];
	char designation[20];
	float salary;
	
};

/* Creates and Initiates Database*/
void createDB(struct Employee e[], int size)
{
	int i=0;
	
	for(i=0; i<size; i++)
	{
		printf("\n------------------------------");
		printf("\nEnter The Record of Employee %d",(i+1));
		e[i].emp_id = i+1; 
		printf("\nEnter First name & Last Name :");
		scanf("%s%s",e[i].fName,e[i].lName);
		printf("\nEnter Designation :");
		scanf("%s",e[i].designation);
		printf("\nEnter Salary : Rs. ");
		scanf("%f",&e[i].salary);
		printf("\n------------------------------");
	}
}

/* Displays record of a Employee */
void display(struct Employee e)
{
	printf("\n%d\t%s\t\t%s\t\t%s\t\tRs.%0.2f/-",e.emp_id,e.fName,e.lName,e.designation,e.salary);
}

/* Searches for a record with key */
int search(struct Employee e[], int size, int key)
{
	int pos = -1, i;
	for(i=0; i<size; i++)
	{
		if(e[i].emp_id == key)
		{
			pos = i;
			break;
		}
	}
	return pos;
	
}

/* Sorts all record according to 'emp_id' in ascending order*/
void sort(struct Employee e[], int size)
{
	struct Employee tmp;
	int i,j;
		
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			if(e[i].emp_id < e[j].emp_id)
			{
				tmp = e[i];
				e[i] = e[j];
				e[j] = tmp;
			}
		}
	}
}

/* Inserts record into database */
void add(struct Employee e[], int size, int id)
{
	int i = size-1;
	e[i].emp_id = id;
	printf("\nEnter First name & Last Name :");
	scanf("%s%s",e[i].fName,e[i].lName);
	printf("\nEnter Designation :");
	scanf("%s",e[i].designation);
	printf("\nEnter Salary : Rs. ");
	scanf("%f",&e[i].salary);
	
	sort(e,size);
}

/* Updates the value of record */
void modify(struct Employee e[], int size, int key)
{
	printf("\nEnter First name & Last Name :");
	scanf("%s%s",e[key].fName,e[key].lName);
	printf("\nEnter Designation :");
	scanf("%s",e[key].designation);
	printf("\nEnter Salary : Rs. ");
	scanf("%f",&e[key].salary);
	
	sort(e,size);
	
	printf("\nRecord Modified Successfully !!!");
}

/* Removes record from database */
void delete(struct Employee e[], int size, int key)
{
	int i,j;
	
	for(i=key; i<size; i++)
	{
		e[i] = e[i+1];
	}
	printf("\nRecord Deleted Successfully !!\n");
}

/* Execution starts from here */
int main()
{
	struct Employee e[20];
	int size, choice, i, key, res, id;
	
	do
	{
		printf("\n===============================================");
		printf("\nMENU");
		printf("\n1.Create Database\n2.Display\n3.Add\n4.Delete\n5.Search\n6.Modify\n7.Exit");
		printf("\n\nEnter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\n\nEnter the size of data :");
				scanf("%d", &size);
				
				createDB(e,size);
				printf("\n======================================================================");
				break;
			
			case 2:
				printf("\n======================================================================");
				printf("\nID\tFIRST NAME\tLAST NAME\tDESIGNATION\tSALARY");
				printf("\n======================================================================");
				for(i=0; i<size; i++)
				{
					display(e[i]);
					printf("\n----------------------------------------------------------------------");
				}
				printf("\n======================================================================");
				break;
				
			case 3:
				printf("\nEnter EMP ID :");
				scanf("%d", &id);
	
				if(search(e, size, id) != -1)
				{
					printf("\nAlready Present !!! ENTER ANOTHER ID");
				}
				else
				{
					size++;
					add(e,size,id);
				}
				printf("\n======================================================================");
				break;
				
			case 4:
				printf("\nEnter EMP ID to delete :");
				scanf("%d", &key);
				res = search(e,size,key);
				if(res != -1)
				{
					delete(e,size,res);
					size--;
				}
				else
				{
					printf("\n\nNO RECORD FOUND !!!");
				}
				printf("\n======================================================================");
				break;
				
			case 5:
				printf("\nEnter EMP ID to search :");
				scanf("%d", &key);
				res = search(e,size,key);
				if(res != -1)
				{
					printf("\n======================================================================");
					printf("\nID\tFIRST NAME\tLAST NAME\tDESIGNATION\tSALARY");
					printf("\n======================================================================");
					display(e[res]);
					printf("\n======================================================================");
				}
				else
				{
					printf("\n\nNO RECORD FOUND !!!");
				}
				printf("\n======================================================================");
				break;
				
			case 6:
				printf("\n\nEnter EMP ID to Modify :");
				scanf("%d", &key);
				res = search(e,size,key);
				if(res != -1)
				{
					modify(e,size,res);
				}
				else
				{
					printf("\n\nNO RECORD FOUND !!!");
				}
				printf("\n======================================================================");
				break;
				
			case 7:
				printf("\nThank You !!!\n\n");
				printf("\n======================================================================\n");
				break;
				
			default : printf("\nInvalid Choice !\n");
		}
	}while(choice != 7);
}

/*

**OUTPUT**

student@student-OptiPlex-330:~$ cd Desktop/Shreyas
student@student-OptiPlex-330:~/Desktop/Shreyas$ gcc Ass4-Employee.c
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out

===============================================
MENU
1.Create Database
2.Display
3.Add
4.Delete
5.Search
6.Modify
7.Exit

Enter your choice : 1


Enter the size of data :2

------------------------------
Enter The Record of Employee 1
Enter First name & Last Name :Shreyas Patil

Enter Designation :CEO

Enter Salary : Rs. 98768.44          

------------------------------
------------------------------
Enter The Record of Employee 2
Enter First name & Last Name :Piyush Rajput

Enter Designation :Manager

Enter Salary : Rs. 34756.76

------------------------------
======================================================================
===============================================
MENU
1.Create Database
2.Display
3.Add
4.Delete
5.Search
6.Modify
7.Exit

Enter your choice : 2

======================================================================
ID	FIRST NAME	LAST NAME	DESIGNATION	SALARY
======================================================================
1	Shreyas		Patil		CEO			Rs.98768.44/-
---------------------------------------------------------------------
2	Piyush		Rajput		Manager		Rs.34756.76/-
---------------------------------------------------------------------
======================================================================
===============================================
MENU
1.Create Database
2.Display
3.Add
4.Delete
5.Search
6.Modify
7.Exit

Enter your choice : 3

Enter EMP ID :4

Enter First name & Last Name :Ankit Patil

Enter Designation :Manager

Enter Salary : Rs. 45765.56

======================================================================
===============================================
MENU
1.Create Database
2.Display
3.Add
4.Delete
5.Search
6.Modify
7.Exit

Enter your choice : 2

======================================================================
ID	FIRST NAME	LAST NAME	DESIGNATION	SALARY
======================================================================
1	Shreyas		Patil		CEO			Rs.98768.44/-
---------------------------------------------------------------------
2	Piyush		Rajput		Manager		Rs.34756.76/-
---------------------------------------------------------------------
4	Ankit		Patil		Manager		Rs.45765.56/-
---------------------------------------------------------------------
======================================================================
===============================================
MENU
1.Create Database
2.Display
3.Add
4.Delete
5.Search
6.Modify
7.Exit

Enter your choice : 5

Enter EMP ID to search :2

======================================================================
ID	FIRST NAME	LAST NAME	DESIGNATION	SALARY
======================================================================
2	Piyush		Rajput		Manager		Rs.34756.76/-
======================================================================
======================================================================
===============================================
MENU
1.Create Database
2.Display
3.Add
4.Delete
5.Search
6.Modify
7.Exit

Enter your choice : 6


Enter EMP ID to Modify :4

Enter First name & Last Name :Ankit Patil

Enter Designation :CEO

Enter Salary : Rs. 87867.56

Record Modified Successfully !!!
======================================================================
===============================================
MENU
1.Create Database
2.Display
3.Add
4.Delete
5.Search
6.Modify
7.Exit

Enter your choice : 2

======================================================================
ID	FIRST NAME	LAST NAME	DESIGNATION	SALARY
======================================================================
1	Shreyas		Patil		CEO			Rs.98768.44/-
---------------------------------------------------------------------
2	Piyush		Rajput		Manager		Rs.34756.76/-
---------------------------------------------------------------------
4	Ankit		Patil		CEO			Rs.87867.56/-
---------------------------------------------------------------------
======================================================================
===============================================
MENU
1.Create Database
2.Display
3.Add
4.Delete
5.Search
6.Modify
7.Exit

Enter your choice : 4

Enter EMP ID to delete :2

Record Deleted Successfully !!

======================================================================
===============================================
MENU
1.Create Database
2.Display
3.Add
4.Delete
5.Search
6.Modify
7.Exit

Enter your choice : 2

======================================================================
ID	FIRST NAME	LAST NAME	DESIGNATION	SALARY
======================================================================
1	Shreyas		Patil		CEO			Rs.98768.44/-
---------------------------------------------------------------------
4	Ankit		Patil		CEO			Rs.87867.56/-
---------------------------------------------------------------------
======================================================================
===============================================
MENU
1.Create Database
2.Display
3.Add
4.Delete
5.Search
6.Modify
7.Exit

Enter your choice : 7

Thank You !!!


======================================================================

*/
