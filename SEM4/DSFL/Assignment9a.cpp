#include<iostream>
using namespace std;


typedef struct student
{
	int phno;
	char name[20];
}student;

int insert(int flag[10], student data[10], int chain[10],student X , int size);
int search(student data[10], int chain[10], int flag[10], int size, int x);
void display(int flag[10], student data[10], int chain[10], int size);



int main()
{
int ch,size,i,chain[10],flag[10],result,x;
student data[10],X;
cout<<"\nenter size: ";
cin>>size;


	for(i=0;i<size;i++)
	{
	flag[i]=0;
	chain[i]=-1;
	}
do
{
cout<<"\n1.insert\n2.display\n3.search\n4.exit\n enter your choice: ";
cin>>ch;
	switch(ch)
{
			case 1:
			cout<<"\n Enter the Phone No. and Name of Student to be Inserted: ";
			cin>>X.phno>>X.name;
			insert(flag,data,chain,X,size);
			break;

			case 2:
					display(flag,data,chain,size);
					break;


			case 3:
					 cout<<"\nenter phone no. to be searched: ";
					cin>>x;
			result=search(data,chain,flag,size,x);
			if(result==-1)
			{
			cout<<"\nelement not found";
			}
			else
			{
			cout<<"\nelement found\n"<<x;


			}

			break;
			}
	}while(ch!=4);
}






int insert(int flag[10], student data[10], int chain[10],student X , int size)
{


	int j,start,count=0,i;
	start=X.phno%size;
	if(flag[start]==0)
		{
			data[start]=X;
			flag[start]=1;

		}
		else if (data[start].phno%size==X.phno%size)
		{
			while(chain[start]!=-1)
			{
			start=chain[start];

			}
			j=start;
			count=0;
			while(flag[j]==1&&count<size)
			{
			j=(j+1)%size;
			count++;
			}
			if(count==size)
			{
			cout<<"\n hash table is full";
			return 0;
			}
			data[j]=X;
			flag[j]=1;
			chain[start]=j;

		}


		else
		{
			count=0;
			j=start;
			while(flag[j]==1 &&count<size)
			{
				j=(j+1)%size;
				count++;
			}
			if(count==size)
			cout<<"\nFull";
			else
			{
				i=data[start].phno%size;
				while(chain[i]!=start)
				{
					i=chain[i];
				}
			chain[i]=j;
			data[j]=data[start];
			chain[j]=chain[start];
			flag[j]=1;
			data[start]=X;
			chain[start]=-1;
			}

			}
}




void display(int flag[10], student data[10], int chain[10], int size)
	{

		int i;
		for(i=0;i<size;i++)
		{

		if(flag[i]==1)
		{
		cout<<"\n"<<i<<"\t"<<data[i].phno <<"\t "<< data[i].name<<"\t"<<chain[i]<<"\t"<<flag[i];
		}
		else
		{
		cout<<"\n"<<i<<"\t"<<"---"<<"\t ------------" <<"\t"<<"-1"<<"\t"<<"0";
		}

		}

}



int search(student data[10], int chain[10], int flag[10], int size, int x)

  {

		int start;
		start=x%size;
		if(flag[start]==1 && data[start].phno==x)
		{
		return start;
		}
		else if(flag[start]==1 && data[start].phno==x%size)
		{
		while(chain[start]!=-1)
		{
		if(data[start].phno==x)
		return start;
		start=chain[start];

		}
		}
		if(data[start].phno==x)
		return start;
		else
		return -1;

}
/*

enter size: 10

1.insert
2.display
3.search
4.exit
 enter your choice: 1

 Enter the Phone No. and Name of Student to be Inserted: 111
Shreyas

1.insert
2.display
3.search
4.exit
 enter your choice: 1

 Enter the Phone No. and Name of Student to be Inserted: 222
Piyush

1.insert
2.display
3.search
4.exit
 enter your choice: 1

 Enter the Phone No. and Name of Student to be Inserted: 3
Aditya

1.insert
2.display
3.search
4.exit
 enter your choice: 2

0       ---      ------------   -1      0
1       111      Shreyas        -1      1
2       222      Piyush -1      1
3       3        Aditya -1      1
4       ---      ------------   -1      0
5       ---      ------------   -1      0
6       ---      ------------   -1      0
7       ---      ------------   -1      0
8       ---      ------------   -1      0
9       ---      ------------   -1      0
1.insert
2.display
3.search
4.exit
 enter your choice: 3

enter phone no. to be searched: 111

element found
111
1.insert
2.display
3.search
4.exit
 enter your choice: 4
*/













