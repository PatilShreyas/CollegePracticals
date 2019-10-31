/* To implement singly linked list and perform various operations */

#include<stdio.h>
#include<stdlib.h>

/*Declaring a structure Node*/
typedef struct node
{
	int data;
	struct node *next;
}node;

/*Function Declarations for node operations*/
node* create(int);
void display(node *);
node* insert_beginning(node *);
void insert_end(node *);
void insert_inbetween(node *, int);
node* delete_beginning(node *);
void delete_end(node *);
void delete_inbetween(node *, int);
node* reverse(node*);
void display_reverse(node*);
/*End Declaration*/


/* Function Main */
int main()
{
	node *head = NULL;
	int choice, size, pos;
	do
	{
		printf("\n======================================================");
		printf("\nLinked List :\n");
		display(head);
		printf("\n======================================================");
		printf("\nMENU");
		printf("\n1.Create Linklist\n2.Display Linklist\n3.Insert Node\n4.Delete Node\n5.Display Reverse\n6.Reverse Node\n7.Exit");
		printf("\n\nEnter Choice :");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the size of Linklist :");
				scanf("%d",&size);
				head = create(size);
				break;

			case 2:
				printf("\n======================================================");
				printf("\nLinked List :\n");
				display(head);
				printf("\n======================================================");
				break;

			case 3:
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

			case 4:
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

			case 5:
			    printf("\nLinkList In Reverse :");
                display_reverse(head);
				break;

			case 6:
			    printf("\nReversed LinkList :");
                head = reverse(head);
                display(head);
				break;

			case 7:
				printf("\nThank You !!!\n");
				break;

			default: printf("\nINVALID CHOICE !!!\n");
		}

	}while(choice != 7);
}
/*Initializes a node*/
void init_node(node *n, int data, node *next)
{
	n->data = data;
	n->next = next;
}


/* Creates a linklist of specified 'size' number of elements */
node* create(int size)
{
	int i;
	int data;
	node *head=NULL, *p, *q, *next;

	for(i=0; i<size; i++)
	{
		if(head == NULL)
		{
			head = (node *)malloc(sizeof(node));
			printf("\nEnter the Value (%d) :",(i+1));
			scanf("%d",&head->data);
			head->next = NULL;
			q = head;
		}
		else
		{
			p = (node *)malloc(sizeof(node));
			printf("Enter the Value (%d) :",(i+1));
			scanf("%d",&p->data);
			p->next = NULL;
			q->next = p;
			q = q->next;
		}
	}
	printf("\nHEAD VAL = %d",head->data);
	return head;
}

/* Displays a Linklist */
void display(node *head)
{
	if(head == NULL)
	{
		printf(":: EMPTY ::");
		return;
	}
	node *p;
	for(p=head; p!=NULL; p=p->next)
	{
		printf("\t%d",p->data);
	}
}

/* To Insert node at the beginning of Linklist */
node* insert_beginning(node *head)
{
	node *p;
	p = (node *)malloc(sizeof(node));
	printf("\nEnter the Value :");
	scanf("%d",&p->data);
	p->next = head;
	head = p;
	return head;
}

/* To Insert node at the end of Linklist */
void insert_end(node *head)
{
	node *p, *q;
	p = (node *)malloc(sizeof(node));
	printf("\nEnter the Value :");
	scanf("%d",&p->data);
		p->next = NULL;
	for(q=head; q->next!=NULL; q=q->next)
	{
	}
	q->next = p;
}

/* To Insert node in between of Linklist */
void insert_inbetween(node *head, int pos)
{
	node *p, *q;
	int i;
	p = (node *)malloc(sizeof(node));
	printf("\nEnter the Value :");
	scanf("%d",&p->data);
	q = head;
	for(i=0; i<pos-1; i++)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
}

/* To delete node from the beginning of Linklist */
node* delete_beginning(node *head)
{
	node *p;
	p = head;
	head = head->next;
	free(p);
	return head;
}

/* To Delete node from the end of Linklist */
void delete_end(node *head)
{
	node *p, *q;
	for(q=head; q->next->next!=NULL; q=q->next)
	{
	}
	p = q->next;

	free(p);
	q->next = NULL;
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
	free(q);
}

/*To reverse contents of Linkedlist */
node* reverse(node *head)
{
    node *p,*q,*r;
    p = NULL;
    q = head;
    r = q->next;

    while(q!=NULL)
    {
        q->next = p;
        p=q;
        q=r;

        if(q!=NULL)
        {
            r = r->next;
        }
    }
    return p;
}

/*Display Linkedlist in reverse order*/
void display_reverse(node *head)
{
    if(head !=NULL)
    {
        display_reverse(head->next);
        printf("\t%d",head->data);
    }
}

/*

**OUTPUT**
student@student-OptiPlex-330:~/Desktop/Shreyas$ gcc Ass9-SLinkList.c
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out

======================================================
Linked List :
:: EMPTY ::
======================================================
MENU
1.Create Linklist
2.Display Linklist
3.Insert Node
4.Delete Node
5.Display Reverse
6.Reverse Node
7.Exit

Enter Choice :1

Enter the size of Linklist :5

Enter the Value (1) :1
Enter the Value (2) :2
Enter the Value (3) :3
Enter the Value (4) :4
Enter the Value (5) :5

HEAD VAL = 1
======================================================
Linked List :
        1       2       3       4       5
======================================================
MENU
1.Create Linklist
2.Display Linklist
3.Insert Node
4.Delete Node
5.Display Reverse
6.Reverse Node
7.Exit

Enter Choice :3

Enter the Position :1

Enter the Value :10

======================================================
Linked List :
        10      1       2       3       4       5
======================================================
MENU
1.Create Linklist
2.Display Linklist
3.Insert Node
4.Delete Node
5.Display Reverse
6.Reverse Node
7.Exit

Enter Choice :3

Enter the Position :5

Enter the Value :66

======================================================
Linked List :
        10      1       2       3       4       66      5
======================================================
MENU
1.Create Linklist
2.Display Linklist
3.Insert Node
4.Delete Node
5.Display Reverse
6.Reverse Node
7.Exit

Enter Choice :3

Enter the Position :7

Enter the Value :90

======================================================
Linked List :
        10      1       2       3       4       66      5       90
======================================================
MENU
1.Create Linklist
2.Display Linklist
3.Insert Node
4.Delete Node
5.Display Reverse
6.Reverse Node
7.Exit

Enter Choice :4

Enter the Position :1

======================================================
Linked List :
        1       2       3       4       66      5       90
======================================================
MENU
1.Create Linklist
2.Display Linklist
3.Insert Node
4.Delete Node
5.Display Reverse
6.Reverse Node
7.Exit

Enter Choice :4

Enter the Position :5

======================================================
Linked List :
        1       2       3       4       5       90
======================================================
MENU
1.Create Linklist
2.Display Linklist
3.Insert Node
4.Delete Node
5.Display Reverse
6.Reverse Node
7.Exit

Enter Choice :4

Enter the Position :6

======================================================
Linked List :
        1       2       3       4       5
======================================================
MENU
1.Create Linklist
2.Display Linklist
3.Insert Node
4.Delete Node
5.Display Reverse
6.Reverse Node
7.Exit

Enter Choice :5

LinkList In Reverse :   5       4       3       2       1
======================================================
Linked List :
        1       2       3       4       5
======================================================
MENU
1.Create Linklist
2.Display Linklist
3.Insert Node
4.Delete Node
5.Display Reverse
6.Reverse Node
7.Exit

Enter Choice :6

Reversed LinkList :     5       4       3       2       1
======================================================
Linked List :
        5       4       3       2       1
======================================================
MENU
1.Create Linklist
2.Display Linklist
3.Insert Node
4.Delete Node
5.Display Reverse
6.Reverse Node
7.Exit

Enter Choice :7

Thank You !!!



*/
