#include<iostream>
using namespace std;

//Node for dynamic stack
typedef struct Node
{
	char data;
	struct Node *next;
}Node;

//Implementation of stack for expressions
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
		return ((top == NULL)? 1 : 0);
	}
	
	void push(char c)
	{
		Node *p;
		p = new Node();
		p->data = c;
		p->next = top;
		top=p;
	}
	
	char pop()
	{
		char c;
		if(isEmpty() == 0)
		{
			Node *p = top;

		
			c = p->data;
			top = top->next;
		
			delete p;
		}
		return c;
		
	}
	
	char getTop()
	{
		return top->data;
	}
	
	void display()
	{
		Node *p = top;
		
		while(p != NULL)
		{
			cout<<"\n"<<(p->data);
			p = p->next;
		}
	}
};
//End Stack

//Function Declarations
void toPostfix(char[], char[]);
void toPrefix(char[], char[]);
void reverse(char[], char[]);
void evaluatePostfix(char[]);
void evaluatePrefix(char[]);
int evaluate(int, int, char);
int precedence(char);
//End Function Declarations

int main()
{
	int choice;
	int result;
	char infix[20];
	char postfix[20];
	char prefix[20];
	char token;


	do
	{
		cout<<"\n=======================================================";
		cout<<"\nMENU\n";
		cout<<"\n1. Set Infix Expression";
		cout<<"\n2. Infix to Postfix Conversion";
		cout<<"\n3. Infix to Prefix Conversion";
		cout<<"\n4. Evaluate Postfix Expression";
		cout<<"\n5. Evaluate Prefix Expression";
		cout<<"\n6. Exit";
		cout<<"\n\nEnter Your Choice :";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter The Infix Expression :";
				cin>>infix;
				break;
				
			case 2: 
				toPostfix(infix,postfix);
				cout<<"\n-----------------------------------";
				cout<<"\nPostfix : "<<postfix;
				cout<<"\n-----------------------------------";
				break;
				
			case 3:
				toPrefix(infix,prefix);
				cout<<"\n-----------------------------------";
				cout<<"\nPrefix : "<<prefix;
				cout<<"\n-----------------------------------";
				break;
				
			case 4:
				evaluatePostfix(postfix);
				break;
				
			case 5:
				evaluatePrefix(prefix);
				break;
				
			case 6: cout<<"\nThank You !!!\n\n";break;
		}
		
		cout<<"\n=======================================================\n\n";
	}while(choice != 6);
}

//Function to Convert Infix Expression to Postfix Expression
void toPostfix(char infix[20], char postfix[20])
{
	Stack stack;
	char token, c;
	int i,j=0;
	
	for(i=0; infix[i] != '\0'; i++)
	{
		token = infix[i];
		if(isalnum(token))
		{
			postfix[j] = token;
			j++;
		}
		else
		{
			if(token == '(')
			{
				stack.push(token);
			}
			else if(token == ')')
			{
				while((c = stack.pop()) != '(')
				{
					postfix[j] = c;
					j++;				
				}
			}
			else
			{
				while(stack.isEmpty() != 1 && (precedence(token) <= precedence(stack.getTop())))
				{
					postfix[j] = stack.pop();
					j++;
				}
				stack.push(token);
			}
		}
	}

	while(stack.isEmpty() != 1)
	{
		postfix[j] = stack.pop();
		j++;
	}
	postfix[j] = '\0';
}

//Function for reversing the contents of Expression
void reverse(char src[20], char dest[20])
{
	int i,j=0;
	
	for(i=0; src[i] != '\0'; i++){}
	
	i--;
	
	for(j=0; i>=0; j++,i--)
	{
		if(src[i] == '(')
		{
			dest[j] = ')';
		}
		else if(src[i] == ')')
		{
			dest[j] = '(';
		}
		else
			dest[j] = src[i];
	}
	dest[j] = '\0';
}

// Function to convert Infix Expression to Prefix Expression
void toPrefix(char infix[20], char prefix[20])
{
	char tmpInfix[20], tmpPrefix[20];
	
	reverse(infix, tmpInfix);
	toPostfix(tmpInfix, tmpPrefix);
	reverse(tmpPrefix, prefix);
}

//Function to Check Precedence of Operators
int precedence(char c)
{
	if(c == '(')
		return 0;
	if(c == '+' || c == '-')
		return 1;
	if(c == '*' || c == '/')
		return 2;
	return 3;
}

//Function for Evaluation of Operands with Operand
int evaluate(int operand1, int operand2, char op)
{
	if(op == '+')
		return (operand1 + operand2);
		
	if(op == '-')
		return (operand1 - operand2);
		
	if(op == '*')
		return (operand1 * operand2);
		
	if(op == '/')
		return (operand1 / operand2);
		
	if(op == '%')
		return (operand1 % operand2);		
}

//Function for evaluatioon of Postfix expressions
void evaluatePostfix(char postfix[20])
{
	Stack stack;
	int op1, op2, result;
	char token;
	int x;
	
	for(int i=0; postfix[i] != '\0'; i++)
	{
		token = postfix[i];
	
		if(isalnum(token))
		{
			cout<<"\nEnter the Value of "<<token<<" :";
			cin>>x;		
			stack.push(char(x));
		}
		else
		{
			op2 = stack.pop();
			op1 = stack.pop();
			result = evaluate(op1, op2, token);
			stack.push(char(result));
		}
	}
	result = stack.pop();
	cout<<"\n-----------------------------------";
	cout<<"\nResult = "<<result;
	cout<<"\n-----------------------------------";
}

//Function for evaluatioon of Prefix expressions
void evaluatePrefix(char prefix[20])
{
	Stack stack;
	int op1, op2, result;
	char token;
	int x, i;
	
	for(i=0; prefix[i] != '\0'; i++) {}
	
	i--;
	
	for(;i>=0; i--)
	{
		token = prefix[i];
		
		if(isalnum(token))
		{
			cout<<"\nEnter the Value of "<<token<<" :";
			cin>>x;	
			stack.push(char(x));
		}
		else
		{
			op1 = stack.pop();
			op2 = stack.pop();
			
			result = evaluate(op1, op2, token);
			stack.push(char(result));
		}
	}
	result = stack.pop();
	cout<<"\n-----------------------------------";
	cout<<"\nResult = "<<result;
	cout<<"\n-----------------------------------";
}

/*

	**OUTPUT**
	
student@student-OptiPlex-330:~/Desktop/Shreyas$ g++ Assignment1-Exp.cpp
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out

=======================================================
MENU

1. Set Infix Expression
2. Infix to Postfix Conversion
3. Infix to Prefix Conversion
4. Evaluate Postfix Expression
5. Evaluate Prefix Expression
6. Exit

Enter Your Choice :1

Enter The Infix Expression :a+b*c

=======================================================


=======================================================
MENU

1. Set Infix Expression
2. Infix to Postfix Conversion
3. Infix to Prefix Conversion
4. Evaluate Postfix Expression
5. Evaluate Prefix Expression
6. Exit

Enter Your Choice :2

-----------------------------------
Postfix : abc*+
-----------------------------------
=======================================================


=======================================================
MENU

1. Set Infix Expression
2. Infix to Postfix Conversion
3. Infix to Prefix Conversion
4. Evaluate Postfix Expression
5. Evaluate Prefix Expression
6. Exit

Enter Your Choice :3

-----------------------------------
Prefix : +a*bc
-----------------------------------
=======================================================


=======================================================
MENU

1. Set Infix Expression
2. Infix to Postfix Conversion
3. Infix to Prefix Conversion
4. Evaluate Postfix Expression
5. Evaluate Prefix Expression
6. Exit

Enter Your Choice :4

Enter the Value of a :1

Enter the Value of b :2

Enter the Value of c :3

-----------------------------------
Result = 7
-----------------------------------
=======================================================


=======================================================
MENU

1. Set Infix Expression
2. Infix to Postfix Conversion
3. Infix to Prefix Conversion
4. Evaluate Postfix Expression
5. Evaluate Prefix Expression
6. Exit

Enter Your Choice :5

Enter the Value of c :3

Enter the Value of b :2

Enter the Value of a :1

-----------------------------------
Result = 7
-----------------------------------
=======================================================


=======================================================
MENU

1. Set Infix Expression
2. Infix to Postfix Conversion
3. Infix to Prefix Conversion
4. Evaluate Postfix Expression
5. Evaluate Prefix Expression
6. Exit

Enter Your Choice :6

Thank You !!!


=======================================================

*/
