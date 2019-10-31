/*ASSIGNMENT 12- hashing (without replacement) with file handeling*/
#include<iostream>
using namespace std;
typedef struct student
{
	int pno;
	char name[20];
}student;


int size;
void insert(student data[30],int chain[30],int flag[30],int size,student x);
void displayH(student data[30],int chain[30],int flag[30]);
//int search(int data[30],int chain[30],int flag[30],int size,int key);

int main()
{
	int i,ch,key;

	int chain[30],flag[30];
	student data[30],x;
	cout<<"\nEnter size of hash table: ";
	cin>>size;
	for(i=0;i<size;i++)
			{
				flag[i]=0;
				chain[i]=-1;
			}
	do
	{
		cout<<"\n1. insert\t2. display\t3. search\t4. exit\n\nEnter your choice...:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\nEnter phone num and name of to insert:";
			cin>>x.pno>>x.name;

			insert(data,chain,flag,size,x);
		break;

		case 2:
			displayH(data,chain,flag);
		break;

		case 3:
			int k;
			cout<<"\nEnter element to search...";
			cin>>key;
		// k=search(data,chain,flag,size,key);
			if(k==-1)
			{
				cout<<"\nELement not found...";
			}
			else
			cout<<"\nfound at "<<k<<"th position......";
		break;
		}
			}while(ch!=4);

return 0;
}
void insert(student data[30],int chain[30],int flag[30],int size,student x)
{
	int start=x.pno%size;
	if(flag[start]==0)
	{
		data[start]=x;
		flag[start]=1;
		return ;
	}
	else if(data[start].pno%size==x.pno%size)
	{
		while(chain[start]!=-1)
		{
			start=chain[start];
		}
		int cnt=0;
		int j=start;
		while(flag[j]!=0 && cnt<size)
		{
			j=(j+1)%size;
			cnt++;
		}
		if(cnt==size )
		{
			cout<<"\nTable is full.....";
		}
		else
		{
			data[j]=x;
			chain[start]=j;
			flag[j]=1;
		}
	}
	else
	{
		int cnt=0;
		int i=data[start].pno%size;
		while(chain[i]!=start)
			i=chain[i];

		int j=start;
		while(flag[j]==1 && cnt<size)
		{
			j=(j+1)%size;
			cnt++;
		}
		if(cnt==size)
		cout<<"\nTable is full....";

		data[j]=data[start];
		chain[i]=j;
		chain[j]=chain[start];
		flag[j]=1;
		data[start]=x;
		chain[start]=-1;
	}
}
void displayH(student data[30],int chain[30],int flag[30])
{
	for(int i=0;i<size;i++)
	{
		if(flag[i]==1)
		{
			cout<<"\n"<<i<<"\t"<<data[i].pno<<"\t"<<data[i].name<<"\t"<<chain[i];
		}
		else
		{
			cout<<"\n"<<i<<"\t"<<"____"<<"\t "<<"................."<<"\t"<<chain[i];
		}
	}
}

/*

Enter size of hash table: 4

1. insert       2. display      3. search       4. exit

Enter your choice...:1

Enter phone num and name of to insert:111
Shreyas

1. insert       2. display      3. search       4. exit

Enter your choice...:1

Enter phone num and name of to insert:222
Patil

1. insert       2. display      3. search       4. exit

Enter your choice...:1

Enter phone num and name of to insert:422
Piyush

1. insert       2. display      3. search       4. exit

Enter your choice...:1

Enter phone num and name of to insert:511
Aditya

1. insert       2. display      3. search       4. exit

Enter your choice...:2

0       422     Piyush  -1
1       511     Aditya  -1
2       222     Patil   0
3       111     Shreyas 1
1. insert       2. display      3. search       4. exit

Enter your choice...:3

Enter element to search...222

found at 3 position......
1. insert       2. display      3. search       4. exit

Enter your choice...:4

*/
