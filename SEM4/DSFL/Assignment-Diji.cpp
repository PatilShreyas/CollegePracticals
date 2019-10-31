#include<iostream>
using namespace std;
#include<stdlib.h>
#define INFINITY 10000

void accept(int *a,int n)
{
    int i,j,temp;
    for(i=0 ; i<n ; i++)
    {
        for(j=i ; j<n ; j++)
        {
            if(i==j)
            	*(a+i*n+j)=0;
            else
            {
                cout<<"\n\tWeight of edge ["<<i<<"]["<<j<<"]>>";
                cin>>temp;
                *(a+i*n+j)=*(a+j*n+i)=temp;
        	}
        }
    }
}
void display(int *a,int n)
{
    int i,j;
    for(i=0 ; i<n ; i++)
    {
        cout<<"\n\t"<<i<<"]";
        for(j=0 ; j<n ; j++)
            cout<<"\t"<<*(a+i*n+j);
    }
}

void dijkstra(int *a,int n)
{
	int visit[n],dist[n],prev[n],cost[n][n],d[n];
	int i,j,k,count,mindist,nxtnode,startvertex;

	cout<<"\n\tEnter the STARTING VERTEX of Graph : ";
	cin>>startvertex;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(a+i*n+j)==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=*(a+i*n+j);
		}
	}

	for(i=0;i<n;i++)
	{
		dist[i]=cost[startvertex][i];
		prev[i]=startvertex;
		visit[i]=0;
	}

	dist[startvertex]=0;
	visit[startvertex]=1;
	count=1;

	while(count<n-1)
	{
		mindist=INFINITY;
		for(i=0;i<n;i++)
		{
			if(dist[i]<mindist && !visit[i])
			{
				mindist=dist[i];
				nxtnode=i;
			}
		}

		visit[nxtnode]=1;

		for(i=0;i<n;i++)
		{
			if(!visit[i])
			{
				if(mindist+cost[nxtnode][i] < dist[i])
				{
					dist[i]=mindist+cost[nxtnode][i];
					prev[i]=nxtnode;
				}
			}
		}
		count++;
	}

	for(i=0;i<n;i++)
	{
		if(i!=startvertex)
		{
			cout<<"\n\n\tDistance of node "<<i<<" from node "<<startvertex<<" is : "<<dist[i];
			cout<<"\n\tIts path is : "<<i;
			j=i;
			do
			{
				j=prev[j];
				cout<<"<-"<<j;
			}while(j!=startvertex);
		}
	}
}

int main()
{
    int *a,n,flag,choice;

    cout<<"\n\t\t**Shortest path using Dijkstra's alorithm**\n";
    cout<<"\n\tEnter the No.of Vertices : ";
    cin>>n;
    a=new int[n*n];
    accept(a,n);

    do
    {
		cout<<"\n--------------------MENU--------------------";
		cout<<"\n\t1:Display Adjacency matrix\n\t2:Display Shortest paths\n\t0:Exit : ";
		cin>>choice;

		switch(choice)
		{
		    case 1:
		        display(a,n);
		        break;
		    case 2:
		    dijkstra(a,n);
		        break;
		}
    }while(choice!=0);

    cout<<"\n";
    return 0;
}
