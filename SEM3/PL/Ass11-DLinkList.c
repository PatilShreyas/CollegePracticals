/* To implement doubly linked list and perform various operations */

#include<stdio.h>
#include<stdlib.h>

/*Declaring a structure Node*/
typedef struct node
{
	int roll;
	char name[30];
	float marks;
	struct node *prev;
	struct node *next;
}node;

/*Function Declarations for node operations*/
node* create(int);
void display_forward(node *);
void display_reverse(node*);
node* insert_beginning(node *);
void insert_end(node *);
void insert_inbetween(node *, int);
node* delete_beginning(node *);
void delete_end(node *);
void delete_inbetween(node *, int);
node* reverse(node*);
node* search(node*);
void modify(node*);
/*End Declaration*/


/* Function Main */
int main()
{
	node *head = NULL, *p=NULL;
	int choice, size, pos;
	do
	{
		printf("\n======================================================");
		printf("\nMENU");
		printf("\n1.Create Database\n2.Display Forward\n3.Display Reverse\n4.Insert Node\n5.Delete Node\n6.Search\n7.Modify\n8.Exit");
		printf("\n\nEnter Choice :");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the no of Records :");
				scanf("%d",&size);
				head = create(size);
				break;

			case 2:
				printf("\n======================================================");
				printf("\nROLLNO\tNAME\tMARKS");
				printf("\n======================================================");
				display_forward(head);
				printf("\n======================================================");
				break;

            case 3:
				printf("\n======================================================");
				printf("\nROLLNO\tNAME\tMARKS");
				printf("\n======================================================");
				display_reverse(head);
				printf("\n======================================================");
				break;


			case 4:
				printf("\nEnter the Position :");
				scanf("%d", &pos);

				if(pos == 1)
				{
					head = insert_beginning(head);
					size++;
				}
				else if(pos == size)
				{
					insert_end(head);
					size++;
				}
				else if(pos>1 && pos<size)
				{
					insert_inbetween(head, pos);
					size++;
				}

				else
					printf("\nWrong Position entered...");
				break;

			case 5:
				printf("\nEnter the Position :");
				scanf("%d", &pos);

				if(pos == 1)
				{
					head = delete_beginning(head);
					size--;
				}
				else if(pos == size)
				{
					delete_end(head);
					size--;
				}
				else if(pos>1 && pos<size)
				{
					delete_inbetween(head, pos);
					size--;
				}

				else
					printf("\nWrong Position entered...");
				break;

			case 6:
                p = search(head);
                if(p == NULL)
                    printf("\nRecord Not Found !");
                else
                {
                    printf("\n======================================================");
                    printf("\nROLLNO\tNAME\tMARKS");
                    printf("\n======================================================");
                    display_forward(p);
                    printf("\n======================================================");
                }
				break;

			case 7:
                p = search(head);
                if(p == NULL)
                    printf("\nRecord Not Found !");
                else
                {
                    modify(p);
                }
				break;

			case 8:
				printf("\nThank You !!!\n");
				break;

			default: printf("\nINVALID CHOICE !!!\n");
		}

	}while(choice != 8);
}

/* Creates a record of specified 'size' number of elements */
node* create(int size)
{
	int i;
	int data;
	node *head=NULL, *p, *last, *next;

	for(i=0; i<size; i++)
	{
		if(head == NULL)
		{
			head = (node *)malloc(sizeof(node));
			printf("\nEnter the Value %d(Roll No, Name, Marks) :",(i+1));
			scanf("%d%s%f",&head->roll, &head->name, &head->marks);
			head->next = NULL;
			head->prev = NULL;
			last = head;
		}
		else
		{
			p = (node *)malloc(sizeof(node));
			printf("\nEnter the Value %d(Roll No, Name, Marks) :",(i+1));
			scanf("%d%s%f",&p->roll, &p->name, &p->marks);
			p->next = NULL;
			last->next = p;
			p->prev = last;
			last = last->next;
		}
	}
	return head;
}

/* Displays records in forward order */
void display_forward(node *head)
{
	node *p;
	for(p=head; p!=NULL; p=p->next)
	{
		printf("\n%d\t%s\t%0.2f%",p->roll, p->name, p->marks);
	}
}

/*Display record in reverse order*/
void display_reverse(node *head)
{
    node *p;
    for(p=head; p->next!=NULL; p=p->next)
	{
	}

	for(;p!=NULL; p=p->prev)
    {
        printf("\n%d\t%s\t%0.2f%",p->roll, p->name, p->marks);
    }
}


/* To Insert node at the beginning of record */
node* insert_beginning(node *head)
{
	node *p;
	p = (node *)malloc(sizeof(node));
	printf("\nEnter the Value (Roll No, Name, Marks) :");
    scanf("%d%s%f",&p->roll, &p->name, &p->marks);
	p->next = head;
	p->prev = NULL;
	head->prev = p;
	head = p;
	return head;
}

/* To Insert node at the end of record */
void insert_end(node *head)
{
	node *p, *q;
	p = (node *)malloc(sizeof(node));
	printf("\nEnter the Value (Roll No, Name, Marks) :");
    scanf("%d%s%f",&p->roll, &p->name, &p->marks);
    p->next = NULL;
    p->prev = NULL;
	for(q=head; q->next!=NULL; q=q->next)
	{
	}

	q->next = p;
	p->prev = q;
}

/* To Insert node in between of record */
void insert_inbetween(node *head, int pos)
{
	node *p, *q;
	int i;
	p = (node *)malloc(sizeof(node));
	printf("\nEnter the Value (Roll No, Name, Marks) :");
    scanf("%d%s%f",&p->roll, &p->name, &p->marks);

	p->next = NULL;
	p->prev = NULL;

    q = head;
    for(i=0; i<pos-2; i++)
    {
        q = q->next;
    }
    p->next = q->next;
    q->next->prev = p;
    q->next = p;
    p->prev = q;
}

/* To delete node from the beginning of record */
node* delete_beginning(node *head)
{
	node *p;
	p = head;
	head = head->next;
	head->prev = NULL;
	free(p);
	return head;
}

/* To Delete node from the end of record */
void delete_end(node *head)
{
	node *p, *q;
	for(q=head; q->next!=NULL; q=q->next)
	{
	}
	p = q->prev;
	p->next = NULL;

	free(q);
}

/* To delete node from given position in Linklist */
void delete_inbetween(node *head, int pos)
{
	node *p, *q;
	int i;

	p = head;
	for(i=0; i<pos-2; i++)
	{
		p = p->next;
	}
	q = p->next;
	p->next = q->next;
	q->next->prev = p;
	free(q);
}

/* To search record */
node* search(node *head)
{
    node *q, *p=NULL;
    int key;
    printf("\nEnter Roll No. :");
    scanf("%d",&key);
    for(q=head; q!=NULL; q=q->next)
    {
        if(q->roll == key)
        {
            p=q;
            break;
        }
    }
    return p;
}

/* Modify specific record */
void modify(node *p)
{
    printf("\nEnter the Value (Roll No, Name, Marks) :");
    scanf("%d%s%f",&p->roll, &p->name, &p->marks);
}

/*

**OUTPUT**
student@student-OptiPlex-330:~/Desktop/Shreyas$ gcc Ass11-DLinkList.c
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out



======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :1

Enter the no of Records :2

Enter the Value 1(Roll No, Name, Marks) :1
Shreyas
99

Enter the Value 2(Roll No, Name, Marks) :2
Patil
80

======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :2

======================================================
ROLLNO  NAME    MARKS
======================================================
1       Shreyas 99.00
2       Patil   80.00
======================================================
======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :3

======================================================
ROLLNO  NAME    MARKS
======================================================
2       Patil   80.00
1       Shreyas 99.00
======================================================
======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :4

Enter the Position :1

Enter the Value (Roll No, Name, Marks) :3
Hello
70

======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :2

======================================================
ROLLNO  NAME    MARKS
======================================================
3       Hello   70.00
1       Shreyas 99.00
2       Patil   80.00
======================================================
======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :4

Enter the Position :4

Wrong Position entered...
======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :4

Enter the Position :3

Enter the Value (Roll No, Name, Marks) :6
World
80

======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :2

======================================================
ROLLNO  NAME    MARKS
======================================================
3       Hello   70.00
1       Shreyas 99.00
2       Patil   80.00
6       World   80.00
======================================================
======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :5

Enter the Position :4

======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :2

======================================================
ROLLNO  NAME    MARKS
======================================================
3       Hello   70.00
1       Shreyas 99.00
2       Patil   80.00
======================================================
======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :6

Enter Roll No. :2

======================================================
ROLLNO  NAME    MARKS
======================================================
2       Patil   80.00
======================================================
======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :7

Enter Roll No. :2

Enter the Value (Roll No, Name, Marks) :8
SSPatil
99

======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :2

======================================================
ROLLNO  NAME    MARKS
======================================================
3       Hello   70.00
1       Shreyas 99.00
8       SSPatil 99.00
======================================================
======================================================
MENU
1.Create Database
2.Display Forward
3.Display Reverse
4.Insert Node
5.Delete Node
6.Search
7.Modify
8.Exit

Enter Choice :8

Thank You !!!



*/
