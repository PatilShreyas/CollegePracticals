/*
Create Binary tree and perform following operations:
a. Insert
b. Display
c. Depth of a tree
d. Display leaf-nodes
e. Create a copy of a tree
*/

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
		TreeNode *treeNode = new TreeNode();
		char ch;
		cout<<"\nEnter the Data : ";
		cin>>ch;

		if(ch=='0')
			return NULL;

		treeNode->data = ch;

		cout<<"\nEnter the Left Node of "<<ch<<" : ";
		treeNode->left = create();

		cout<<"\nEnter the Right Node of "<<ch<<" : ";
		treeNode->right = create();

		return treeNode;
	}

	//Recursive Function for inorder travering of tree
	void inorder(TreeNode* treeNode)
	{
		if(treeNode!=NULL)
		{
			inorder(treeNode->left);
			cout<<"\t"<<treeNode->data;
			inorder(treeNode->right);
		}
	}

	//Function to count the leaf nodes and return
	int getLeafCount(TreeNode *treeNode)
	{
		int count = 0;
		if(treeNode==NULL)
			return 0;

		if(treeNode->left==NULL && treeNode->right==NULL)
		{       cout<<"\t"<<treeNode->data;
				return 1;
		}
		count = getLeafCount(treeNode->left) + getLeafCount(treeNode->right);
		return count;
	}

	//Function to calculate height of tree
	int getHeight(TreeNode *treeNode)
	{
		int hLeft, hRight;
		if(treeNode==NULL)
			return 0;

		if(treeNode->left==NULL && treeNode->right==NULL)
			return 0;

		hLeft = getHeight(treeNode->left);
		hRight = getHeight(treeNode->right);

		if(hLeft>hRight)
			return 1+hLeft;
		else
			return 1+hRight;
	}

	//Function to Copy tree nodes and return
	TreeNode* copy(TreeNode *treeNode)
	{
		TreeNode *p;
		p=NULL;
		if(treeNode!=NULL)
		{
			p = new TreeNode();
			p->data = treeNode->data;
			p->left = copy(treeNode->left);
			p->right = copy(treeNode->right);
		}
		return p;
	}
};

//Function main
int main()
{
	Tree tree;
	int choice,count;
	TreeNode *root,*rt;
	do
	{
		cout<<"\n===========================================================";
		cout<<"\n\nMain Menu \n\n1.Create Tree\n2.Display Tree\n3.Leaf Node Count\n4.Height Of Tree\n5.Copy\n6.Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>choice;

		switch(choice)
		{
			case 1:root = tree.create();break;

			case 2:tree.inorder(root);break;

			case 3:
				count = tree.getLeafCount(root);
				cout<<"\n----------------------------------------";
				cout<<"\n\nNumber of Leaf Nodes :"<<count;
				cout<<"\n----------------------------------------";
				break;

			case 4:
				count = tree.getHeight(root);
				cout<<"\n----------------------------------------";
				cout<<"\n\nHeight of tree :"<<count;
				cout<<"\n----------------------------------------";
				break;

			case 5:
				cout<<"\n----------------------------------------";
				cout<<"\n Copied tree : ";
				rt = tree.copy(root);
				cout<<"\n----------------------------------------";
				tree.inorder(rt);
				break;

			case 6:cout<<"\n\nThank You !!\n";break;
			default:cout<<"\n Invalid choice!! Please enter your choice again."<<endl;
		}
	}while(choice != 6);
}
