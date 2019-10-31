/*
Consider a friends’ network on facebook social web site. Model it as a graph to represent each
node as a user and a link to represent the fried relationship between them. Store data such as
date of birth, number of comments for each user.
1. Find who is having maximum friends
2. Find who has post maximum and minimum comments
3. Find users having birthday in this month.
Hint: (Use adjacency list representation and perform DFS and BFS traversals)
*/

#include<iostream>
using namespace std;
struct Date
{
	int date;
	int month;
	int year;
};

typedef struct Vertex
{
	int data;
	int cost;
	int comm;
	struct Date dob;
	struct Vertex *next;
}Vertex;

class Facebook
{
	int v,e,ch,s,visit[10],i,mon;
	Vertex *graph[10];
public:

	void addUsers()
	{
		cout<<"\n--------------------";
		cout<<"\nEnter the Number of Users : ";
		cin>>v;
		cout<<"\nEnter the Number of Edges : ";
		cin>>e;
		cout<<"\n--------------------";



		int i,j,src,des;

		Vertex *start;
		int re;
		for(i=0;i<v;i++)
		{
			start=new Vertex;
			cout<<"\nEnter id=";
			cin>>start->data;
			cout<<"No.of comments for user"<<start->data<<"=";
			cin>>start->comm;
			cout<<"Enter date/month/year =";
			cin>>start->dob.date>>start->dob.month>>start->dob.year;
			graph[i]=start;
			graph[i]->next=NULL;
		}
		for(i=0;i<e;i++)
		{
			cout<<"Enter friends:\nFriend1 id:=";
			cin>>src;
			cout<<"friend2 id:=";
			cin>>des;

			re=insert(graph,src,des);
			re=insert(graph,des,src);
			if(re==1)
			{
				cout<<"\nEnter appropriate user id\n";
				i--;
			}
		}
	}
	void display()
{Vertex *p;
	int i,j,flag;
	cout<<"USERS   \t   comments\t   friends \t Date of birth";
		for(i=0;i<v;i++)
	{        // cout<<"date:="<<graph[i]->dob.date<<"/"<<graph[i]->dob.month<<"/"<<graph[i]->dob.year;
		p=graph[i]->next;
		cout<<"\n"<<graph[i]->data;
		flag=0;
		for(;p!=NULL;p=p->next)
		{
			flag++;
		}
		cout<<"\t\t"<<graph[i]->comm<<"\t\t"<<flag<<"\t\t"<<graph[i]->dob.date<<"/"<<graph[i]->dob.month<<"/"<<graph[i]->dob.year;
	}


}

int insert(Vertex *graph[],int src,int des)
{
	Vertex *start,*p;
	int i,flag=0;
	start=new Vertex;




	start->data=graph[des]->data;
	start->dob=graph[des]->dob;
	start->comm=graph[des]->comm;
	       //	start->cost=cost;
		start->next=NULL;
				if(graph[src]->next==NULL)
			    {
			    	graph[src]->next=start;
				}
			else
			{	p=graph[src]->next;
				while(p->next!=NULL)
				{              // cout<<"\n="<<p->data;
						p=p->next;
				}
				p->next=start;
			}
			return 0;
}

void maxfriends()
{int max=-1,flag,i,k;
Vertex *p;
     for(i=0;i<v;i++)
     {p=graph[i]->next;
		flag=0;
		for(;p!=NULL;p=p->next)
			flag=flag+1;

		if(max<flag)
		{	max=flag;
			k=graph[i]->data;
		}
     }

	cout<<"User "<<k<<" has maximum friends="<<max;
}


void maxmincomm()
{int m,n,i,max,min;
	max=graph[0]->comm;
	m=graph[0]->data;
	min=graph[0]->comm;
	n=graph[0]->data;
	for(i=0;i<v;i++)
	{
		if(max<graph[i]->comm)
		{	max=graph[i]->comm;
			m=graph[i]->data;
		}

		if(min>graph[i]->comm)
		{min=graph[i]->comm;
			n=graph[i]->data;
		}
	}

	cout<<"\nUser "<<m<<" has maximum comments="<<max;
	cout<<"\nUser "<<n<<" has minimum comments="<<min;
}

void birth(int mon)
{
	int i,flag=0;

	for(i=0;i<v;i++)
	{
		if(mon==graph[i]->dob.month)
		{	cout<<"User "<<graph[i]->data<<" having birthday on date:"<<graph[i]->dob.date;
			flag=1;
		}
	}
	if(flag==0)
		cout<<"\nNone of friends having birthday on "<<mon<<" month";
}
};
void birth(Vertex *graph,int v,int mon);
void maxmincomm(Vertex *graph,int v);
void maxfriends(Vertex *graph,int v);
void accept(Vertex *graph,int v,int e);
void display(Vertex *graph,int v);
int insert(Vertex *graph,int src,int des);


int main()
{
	int v,e,ch,s,visit[10],i,mon;
	Vertex *graph;

	Facebook fb;
	//clrscr();
do{
	cout<<"\nMain Menu\n1.Add Users\n2.Display\n3.Find maximum no. of friends\n4.Find max and min no. of comments\n5.Friends having birthday in given month\n8.Exit\nEnter your choice=";
	cin>>ch;
	switch(ch)
	{
		case 1:	cout<<"Enter graph details\n";
			fb.addUsers();
			cout<<"\nGraph created successfully\n";
			break;

		case 2:fb.display();
			break;

		case 3:fb.maxfriends();
			break;

		case 4:fb.maxmincomm();
					break;
		case 5:cout<<"Enter month=";
				cin>>mon;
				fb.birth(mon);
			break;

	}
}while(ch!=8);
	return 0;
}

/*
**OUTPUT**
student@student-OptiPlex-330:~/Desktop/Shreyas$ graph++ Assignment5.cpp
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out

Main Menu
1.Accept
2.Display
3.Find maximum no. of friends
4.Find max and min no. of comments
5.Friends having birthday in given month
8.Exit
Enter your choice=1
Enter graph details
No of users=4

No. of edges2

Enter id=1
No.of comments for user1=2
Enter date/month/year =1
1
1

Enter id=2
No.of comments for user2=3
Enter date/month/year =2
3
4

Enter id=3
No.of comments for user3=4
Enter date/month/year =3
4
55

Enter id=4
No.of comments for user4=4
Enter date/month/year =4
5
66
Enter friends:
Friend1 id:=2
friend2 id:=1
Enter friends:
Friend1 id:=3
friend2 id:=3

Graph created successfully

Main Menu
1.Accept
2.Display
3.Find maximum no. of friends
4.Find max and min no. of comments
5.Friends having birthday in given month
8.Exit
Enter your choice=2
USERS   	   comments	   friends 	 Date of birth
1		2		0		1/1/1
2		3		1		2/3/4
3		4		1		3/4/55
4		4		2		4/5/66
Main Menu
1.Accept
2.Display
3.Find maximum no. of friends
4.Find max and min no. of comments
5.Friends having birthday in given month
8.Exit
Enter your choice=3
User 4 has maximum friends=2
Main Menu
1.Accept
2.Display
3.Find maximum no. of friends
4.Find max and min no. of comments
5.Friends having birthday in given month
8.Exit
Enter your choice=4

User 3 has maximum comments=4
User 1 has minimum comments=2
Main Menu
1.Accept
2.Display
3.Find maximum no. of friends
4.Find max and min no. of comments
5.Friends having birthday in given month
8.Exit
Enter your choice=5
Enter month=1
User 1 having birthday on date:1
Main Menu
1.Accept
2.Display
3.Find maximum no. of friends
4.Find max and min no. of comments
5.Friends having birthday in given month
8.Exit
Enter your choice=5
Enter month=6

None of friends having birthday on 6 month
Main Menu
1.Accept
2.Display
3.Find maximum no. of friends
4.Find max and min no. of comments
5.Friends having birthday in given month
8.Exit
Enter your choice=5
Enter month=5
User 4 having birthday on date:4
Main Menu
1.Accept
2.Display
3.Find maximum no. of friends
4.Find max and min no. of comments
5.Friends having birthday in given month
8.Exit
Enter your choice=8


*/

