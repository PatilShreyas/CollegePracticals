#include<iostream>
using namespace std;

//Structure for Tree Node
typedef struct TreeNode
{
	char data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;
//End TreeNode

//Structure for Node
typedef struct Node
{
	struct TreeNode *add;
	struct Node *next;
}Node;
//End Node

//Class Stack for Tree Structure
class Stack
{
	Node *top;
public:
	Stack()
	{
		top = NULL;
	}
	
	int isEmpty()
	{
		return ((top==NULL)?1:0);
	}
	
	void push(TreeNode *treeNode)
	{
		Node *p = new Node();
		p->add = treeNode;
		p->next = top;
		top = p;
	}
	
	TreeNode *pop()
	{
		Node *p;
		TreeNode *treeNode;
		p = top;
		treeNode = p->add;
		top = top->next;
		delete(p);
		return treeNode;
	}
};
//End Stack

//Class Tree for implementing Tree data structure
class Tree
{
	Stack stack;
	
public:

	//Function to create a new Tree Node
	TreeNode* create()
	{
		TreeNode *treeNode = new TreeNode();;
		char ch;
		cout<<"\nEnter the Data : ";
		cin>>ch;

		if(ch=='0')
			return NULL;

		treeNode->data = ch;

		cout<<"\n\tEnter the Left Node of "<<ch<<" : ";
		treeNode->left = create();

		cout<<"\tEnter the Right Node of "<<ch<<" : ";
		treeNode->right = create();

		return treeNode;
	}
	
	//Function to create a tree using Postfix expression and return
	TreeNode* createByPostfix(char postfix[])
	{
		TreeNode *p;
		Stack s;
		for(int i=0;postfix[i]!='\0';i++)
		{
			char token = postfix[i];
			if(isalnum(token))
			{
				p = new TreeNode();
				p->data = token;
				p->left = NULL;
				p->right = NULL;
				s.push(p);		
			}	
			else
			{
				p=new TreeNode();
				p->data = token;
				p->right = s.pop();
				p->left = s.pop();
				s.push(p);		
			}
		}
		return s.pop();
	}
	
	
	//Function to create a tree using Prefix expression and return
	TreeNode* createByPrefix(char prefix[])
	{
		TreeNode *p;
		Stack s;

		int i;
		for(i=0;prefix[i]!='\0';i++){}
		
		i=i-1;
		for(;i>=0;i--)
		{
			char token=prefix[i];
			if(isalnum(token))
			{
				p = new TreeNode();
				p->data = token;
				p->left = NULL;
				p->right = NULL;
				s.push(p);		
			}	
			else
			{
				p = new TreeNode();
				p->data = token;
				p->left = s.pop();
				p->right = s.pop();
				s.push(p);		
			}
		}
		return s.pop();
	}
	
	//Recursive Function for inorder travering of tree
	void inorder(TreeNode* treeNode)
	{
		if(treeNode!=NULL)
		{
			inorder(treeNode->left);
			cout<<treeNode->data;
			inorder(treeNode->right);
		}
	}
	
	//Recursive Function for preorder travering of tree
	void preorder(TreeNode* treeNode)
	{
		if(treeNode!=NULL)
		{
			cout<<treeNode->data;
			preorder(treeNode->left);
			preorder(treeNode->right);
		}
	}
	
	//Recursive Function for postorder travering of tree
	void postorder(TreeNode* treeNode)
	{
		if(treeNode!=NULL)
		{
			postorder(treeNode->left);
			postorder(treeNode->right);
			cout<<treeNode->data;
		}
	}
	
	//Function for Inorder Tree Traversing WITHOUT RECURSION
	void inorder_norecursion(TreeNode* treeNode)
	{
		Stack s;
		while(treeNode != NULL)
		{
			s.push(treeNode);
			treeNode = treeNode->left;
		}

		while(!s.isEmpty())
		{
			treeNode = s.pop();
			cout<<treeNode->data;
			treeNode = treeNode->right;
			while(treeNode != NULL)
			{
				s.push(treeNode);
				treeNode = treeNode->left;
			}
		}
	}
	
	//Function for Preorder Tree Traversing WITHOUT RECURSION
	void preorder_norecursion(TreeNode* treeNode)
	{
		Stack s;
		while(treeNode != NULL)
		{
			cout<<treeNode->data;
			s.push(treeNode);
			treeNode = treeNode->left;
		}

		while(!s.isEmpty())
		{
			treeNode = s.pop();
			treeNode = treeNode->right;
			
			while(treeNode != NULL)
			{
				cout<<treeNode->data;
				s.push(treeNode);
				treeNode = treeNode->left;
			}
		}
	}
	
	//Function for Postorder Tree Traversing WITHOUT RECURSION
	void postorder_norecursion(TreeNode* treeNode)
	{
		Stack s1,s2;
		TreeNode *t;
		while(treeNode!=NULL)
		{
			s1.push(treeNode);
			s2.push(NULL);
			treeNode=treeNode->left;			
		}
		while(!s1.isEmpty())
		{
			treeNode = s1.pop();
			t = s2.pop();
			if(t == NULL)
			{
				s1.push(treeNode);
				s2.push((TreeNode *)1);
				treeNode=treeNode->right;		
				while(treeNode!=NULL)
				{
					s1.push(treeNode);
					s2.push(NULL);
					treeNode=treeNode->left;			
				}	
			
			}
			else
			{
				cout<<treeNode->data;
			}	
		}	
	}
};


//Function main
int main()
{
	Tree tree;
	int choice,count;
	TreeNode *root=NULL,*rt;
	do
	{
		cout<<"\n===========================================================";
		cout<<"\n\n**Menu** \n\n1.Construct Tree\n2.Inorder Traversal Tree\n3.Preorder Traversal Tree\n4.Postorder Traversal Tree\n5.Exit";
		cout<<"\n\nEnter Your Choice : ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				int ch;
				char expression[20];
				cout<<"\n------------------------";
				cout<<"\nCHOOSE ::";
				cout<<"\n1. Postfix Expression";
				cout<<"\n2. Prefix Expression";
				cout<<"\n------------------------";
				cout<<"\nEnter Choice :";
				cin>>ch;
				if(ch == 1)
				{
					cout<<"\nEnter Postfix Expression :";
					cin>>expression;
					root = tree.createByPostfix(expression);
				}
				else if(ch == 2)
				{
					cout<<"\nEnter Prefix Expression :";
					cin>>expression;
					root = tree.createByPrefix(expression);
				}
				else
				{
					cout<<"\nINVALID CHOICE !!\n";
				}
				cout<<"\nTREE CONSTRUCTED SUCCESSFULLY !!!\n";
				break;
				
			case 2:
				cout<<"\n-------------------------------------------------------";
				cout<<"\nINORDER (RECURSIVE) : \t\t";
				tree.inorder(root);
				cout<<"\n-------------------------------------------------------";
				cout<<"\nINORDER (NON RECURSIVE) : \t";
				tree.inorder_norecursion(root);
				cout<<"\n-------------------------------------------------------";
				break;
				
			case 3:
				cout<<"\n-------------------------------------------------------";
				cout<<"\nPREORDER (RECURSIVE) : \t\t";
				tree.preorder(root);
				cout<<"\n-------------------------------------------------------";
				cout<<"\nINORDER (NON RECURSIVE) : \t";
				tree.preorder_norecursion(root);
				cout<<"\n-------------------------------------------------------";
				break;
			
			case 4:	
				cout<<"\n-------------------------------------------------------";
				cout<<"\nPOSTORDER (RECURSIVE) : \t";
				tree.postorder(root);
				cout<<"\n-------------------------------------------------------";
				cout<<"\nPOSTORDER (NON RECURSIVE) : \t";
				tree.postorder_norecursion(root);
				cout<<"\n-------------------------------------------------------";
				break;
						
			case 5:cout<<"\n\nThank You !!\n";break;
			default:cout<<"\nInvalid choice!!\n\n";      
		}     
	}while(choice != 5);
}

/*
**OUTPUT**
student@student-OptiPlex-330:~/Desktop/Shreyas$ g++ Assignment4-BT.cpp
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out

===========================================================

**Menu** 

1.Construct Tree
2.Inorder Traversal Tree
3.Preorder Traversal Tree
4.Postorder Traversal Tree
5.Exit

Enter Your Choice : 1

------------------------
CHOOSE ::
1. Postfix Expression
2. Prefix Expression
------------------------
Enter Choice :1

Enter Postfix Expression :ABC*+

TREE CONSTRUCTED SUCCESSFULLY !!!

===========================================================

**Menu** 

1.Construct Tree
2.Inorder Traversal Tree
3.Preorder Traversal Tree
4.Postorder Traversal Tree
5.Exit

Enter Your Choice : 4

-------------------------------------------------------
POSTORDER (RECURSIVE) : 	ABC*+
-------------------------------------------------------
POSTORDER (NON RECURSIVE) : 	ABC*+
-------------------------------------------------------
===========================================================

**Menu** 

1.Construct Tree
2.Inorder Traversal Tree
3.Preorder Traversal Tree
4.Postorder Traversal Tree
5.Exit

Enter Your Choice : 3

-------------------------------------------------------
PREORDER (RECURSIVE) : 		+A*BC
-------------------------------------------------------
INORDER (NON RECURSIVE) : 	+A*BC
-------------------------------------------------------
===========================================================

**Menu** 

1.Construct Tree
2.Inorder Traversal Tree
3.Preorder Traversal Tree
4.Postorder Traversal Tree
5.Exit

Enter Your Choice : 2

-------------------------------------------------------
INORDER (RECURSIVE) : 		A+B*C
-------------------------------------------------------
INORDER (NON RECURSIVE) : 	A+B*C
-------------------------------------------------------
===========================================================

**Menu** 

1.Construct Tree
2.Inorder Traversal Tree
3.Preorder Traversal Tree
4.Postorder Traversal Tree
5.Exit

Enter Your Choice : 1

------------------------
CHOOSE ::
1. Postfix Expression
2. Prefix Expression
------------------------
Enter Choice :2

Enter Prefix Expression :+*ABC

TREE CONSTRUCTED SUCCESSFULLY !!!

===========================================================

**Menu** 

1.Construct Tree
2.Inorder Traversal Tree
3.Preorder Traversal Tree
4.Postorder Traversal Tree
5.Exit

Enter Your Choice : 2

-------------------------------------------------------
INORDER (RECURSIVE) : 		A*B+C
-------------------------------------------------------
INORDER (NON RECURSIVE) : 	A*B+C
-------------------------------------------------------
===========================================================

**Menu** 

1.Construct Tree
2.Inorder Traversal Tree
3.Preorder Traversal Tree
4.Postorder Traversal Tree
5.Exit

Enter Your Choice : 3

-------------------------------------------------------
PREORDER (RECURSIVE) : 		+*ABC
-------------------------------------------------------
INORDER (NON RECURSIVE) : 	+*ABC
-------------------------------------------------------
===========================================================

**Menu** 

1.Construct Tree
2.Inorder Traversal Tree
3.Preorder Traversal Tree
4.Postorder Traversal Tree
5.Exit

Enter Your Choice : 4

-------------------------------------------------------
POSTORDER (RECURSIVE) : 	AB*C+
-------------------------------------------------------
POSTORDER (NON RECURSIVE) : AB*C+
-------------------------------------------------------
===========================================================

**Menu** 

1.Construct Tree
2.Inorder Traversal Tree
3.Preorder Traversal Tree
4.Postorder Traversal Tree
5.Exit

Enter Your Choice : 5


Thank You !!

*/
