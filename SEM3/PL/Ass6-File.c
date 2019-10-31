#include<stdio.h>
#include<stdlib.h>
char FILENAME[] = "Student.dat";
typedef struct student
{
	int roll_no;
	char name[30];
	float marks;
}student;

void create(int);
void display(int);
void insert();
int search(int);
void modify(int);
void delete(int);

FILE *fp = NULL;

int main()
{
	int ch;
	int size;
	int key;
	int r;
	do
	{
		printf("\n=============================");
		printf("\nMENU");
		printf("\n1.Create Database\n2.Display\n3.Insert\n4.Modify\n5.Delete\n6.Search\n7.Exit");
		printf("\n\nEnter Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\nEnter the Number of Records :");
				scanf("%d",&size);
				create(size);
				break;

			case 2:
				printf("\n==========================================");
				printf("\nROLL_NO\t\tNAME\t\tMARKS");
				printf("\n==========================================");
				display(size);
				printf("\n==========================================");
				break;

			case 3:
				insert();
				break;

			case 4:
				printf("\nEnter Roll No to Modify :");
				scanf("%d",&key);
				r = search(key);
				if(r == 1)
					modify(key);
				break;

			case 5:
				printf("\nEnter Roll No to Delete :");
				scanf("%d",&key);
				r = search(key);
				if(r == 1)
					delete(key);
				break;

			case 6:
				printf("\nEnter Roll No to Search :");
				scanf("%d",&key);
				search(key);
				break;



			case 7: printf("\nThank You !!\n"); break;
		}
	}while(ch!=7);
}

/*Function to create data file initially */
void create(int size)
{
	int i;
	student s;

	fp = fopen(FILENAME, "w");
	for(i=0; i<size; i++)
	{
		printf("\nEnter Details For Student %d :",(i+1));
		printf("\nRoll No :");
		scanf("%d",&s.roll_no);
		printf("Name :");
		scanf("%s",s.name);
		printf("Marks :");
		scanf("%f", &s.marks);

		fwrite((char *)&s,sizeof(student),1,fp);
	}
	fclose(fp);
}

/*Function to display all data from file*/
void display(int size)
{
	student s;
	fp = fopen(FILENAME,"r");

	while(fread((char *)&s,sizeof(student),1,fp))
	{
		printf("\n%d\t\t%s\t\t%0.2f%%",s.roll_no,s.name,s.marks);
	}
	fclose(fp);
}

/*Function to insert data and end of file*/
void insert()
{
	student s;

	fp = fopen(FILENAME, "a");

	printf("\nEnter Details of Student");
	printf("\nRoll No :");
	scanf("%d",&s.roll_no);
	printf("Name :");
	scanf("%s",s.name);
	printf("Marks :");
	scanf("%f", &s.marks);

	fwrite((char *)&s,sizeof(student),1,fp);

	fclose(fp);
}

/*To search record using roll_no*/
int search(int key)
{
	student s;
	int r=-1;
	fp = fopen(FILENAME,"r");
	printf("\n==========================================");
	printf("\nROLL_NO\t\tNAME\t\tMARKS");
	printf("\n==========================================");
	while(fread((char *)&s,sizeof(student),1,fp))
	{
        if(s.roll_no == key)
        {
            printf("\n%d\t\t%s\t\t%0.2f%%",s.roll_no,s.name,s.marks);
            r=1;
        }
	}
	if(r==-1)
	{
		printf("\nNO RECORD FOUND");
	}
	printf("\n==========================================");
	fclose(fp);
	return r;
}

/*To modify record in file using roll_no*/
void modify(int key)
{
    student s;
    FILE *newFile = fopen("tmp.tmp","w");
    fp = fopen(FILENAME, "r");
    while(fread((char *)&s,sizeof(student),1,fp))
    {
        if(s.roll_no == key)
        {
            printf("\nEnter Details of Student");
            printf("\nRoll No :");
            scanf("%d",&s.roll_no);
            printf("Name :");
            scanf("%s",s.name);
            printf("Marks :");
            scanf("%f", &s.marks);

            fwrite((char *)&s,sizeof(student),1,newFile);
        }
        else
        {
            fwrite((char *)&s,sizeof(student),1,newFile);
        }
    }
    fclose(newFile);
    fclose(fp);
    remove(FILENAME);
    rename("tmp.tmp",FILENAME);
    remove("tmp.tmp");
}

/*To delete record in file using roll_no*/
void delete(int key)
{
    student s;
    FILE *newFile = fopen("tmp.tmp","w");
    fp = fopen(FILENAME, "r");

    while(fread((char *)&s,sizeof(student),1,fp))
    {
        if(s.roll_no != key)
        {
            fwrite((char *)&s,sizeof(student),1,newFile);
        }
    }
    fclose(newFile);
    fclose(fp);
    remove(FILENAME);
    rename("tmp.tmp",FILENAME);
    remove("tmp.tmp");
}

/*
    **OUTPUT**

student@student-OptiPlex-330:~/Desktop/Shreyas/tmp$ gcc Ass6-File.c
student@student-OptiPlex-330:~/Desktop/Shreyas/tmp$ ./a.out

=============================
MENU
1.Create Database
2.Display
3.Insert
4.Modify
5.Delete
6.Search
7.Exit

Enter Choice :1

Enter the Number of Records :2

Enter Details For Student 1 :
Roll No :1
Name :Shreyas
Marks :90

Enter Details For Student 2 :
Roll No :2
Name :Patil
Marks :80

=============================
MENU
1.Create Database
2.Display
3.Insert
4.Modify
5.Delete
6.Search
7.Exit

Enter Choice :2

==========================================
ROLL_NO         NAME            MARKS
==========================================
1               Shreyas         90.00%
2               Patil           80.00%
==========================================
=============================
MENU
1.Create Database
2.Display
3.Insert
4.Modify
5.Delete
6.Search
7.Exit

Enter Choice :3

Enter Details of Student
Roll No :3
Name :Ankit
Marks :85

=============================
MENU
1.Create Database
2.Display
3.Insert
4.Modify
5.Delete
6.Search
7.Exit

Enter Choice :2

==========================================
ROLL_NO         NAME            MARKS
==========================================
1               Shreyas         90.00%
2               Patil           80.00%
3               Ankit           85.00%
==========================================
=============================
MENU
1.Create Database
2.Display
3.Insert
4.Modify
5.Delete
6.Search
7.Exit

Enter Choice :4

Enter Roll No to Modify :1

==========================================
ROLL_NO         NAME            MARKS
==========================================
1               Shreyas         90.00%
==========================================
Enter Details of Student
Roll No :1
Name :Shreyas
Marks :100

=============================
MENU
1.Create Database
2.Display
3.Insert
4.Modify
5.Delete
6.Search
7.Exit

Enter Choice :2

==========================================
ROLL_NO         NAME            MARKS
==========================================
1               Shreyas         100.00%
2               Patil           80.00%
3               Ankit           85.00%
==========================================
=============================
MENU
1.Create Database
2.Display
3.Insert
4.Modify
5.Delete
6.Search
7.Exit

Enter Choice :5

Enter Roll No to Delete :3

==========================================
ROLL_NO         NAME            MARKS
==========================================
3               Ankit           85.00%
==========================================
=============================
MENU
1.Create Database
2.Display
3.Insert
4.Modify
5.Delete
6.Search
7.Exit

Enter Choice :2

==========================================
ROLL_NO         NAME            MARKS
==========================================
1               Shreyas         100.00%
2               Patil           80.00%
==========================================
=============================
MENU
1.Create Database
2.Display
3.Insert
4.Modify
5.Delete
6.Search
7.Exit

Enter Choice :5

Enter Roll No to Delete :2

==========================================
ROLL_NO         NAME            MARKS
==========================================
2               Patil           80.00%
==========================================
=============================
MENU
1.Create Database
2.Display
3.Insert
4.Modify
5.Delete
6.Search
7.Exit

Enter Choice :7

Thank You !!
*/
