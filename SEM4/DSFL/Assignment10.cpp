/*primes*/
#include<iostream>
using namespace std;

class graph
{
 int G[20][20],n;

 public:

 void accept()
 {
  	int i,j,e;
  	int src,dest,cost;
	  cout<<"\nEnter the no. of vertices: ";
	  cin>>n;

	  for(i=0;i<n;i++)
	  {
	  for(j=0;j<n;j++)
	  {
	  G[i][j]=0;
	  }
	  }

	  cout<<"\nEnter the no. of  Edges: ";
	  cin>>e;



	  for(i=0;i<e;i++)
	  {
	  cout<<"\nEnter Source: ";
	   cin>>src;
	  cout<<"\nDestination: ";
	   cin>>dest;
	  cout<<"\nCost: ";
	  cin>>cost;

	  G[src][dest]=cost;
	  G[dest][src]=cost;
 	 }


  }





  void display()
  {
  	int i,j;
   for(i=0;i<n;i++)
   {
   	cout<<"\n";
   	for(j=0;j<n;j++)
   	{
   		cout<<"\t"<<G[i][j];
   	}
   }
  }



  void prims()
  {
  	int i,j,R[20][20];
  	int src,dest,cost,count,min;
  	int total=0;
  	int visited[20];

  	for(i=0;i<n;i++)
  	{
  		for(j=0;j<n;j++)
  		{
  			if(G[i][j]==0)
  			{
  				R[i][j]=999;
  			}
  		else
  		R[i][j]=G[i][j];
  		}
  	}



  	for(i=0;i<n;i++)
  	{
  		visited[i]=0;
  	}

  	cout<<"\nEnter start vertex: ";
  	cin>>src;
  	visited[src]=1;

  	count=0;
  	while(count<n-1)
  	{
  	min=999;

  	for(i=0;i<n;i++)
  	{

  	if(visited[i]==1)
  	for(j=0;j<n;j++)
  	{
  	if(visited[j]!=1)
  	{
  	if(min>R[i][j])
  	{
  		min=R[i][j];
  		src=i;
  		dest=j;
  	}
  	}
  	}
  	}


  	cout<<"\nEdge from "<<src<<" to "<<dest<<" \twith cost:  "<<min;
  	total=total+min;
  	visited[dest]=1;
  	count++;
  	}

  		cout<<"\nTotal Cost: "<<total<<"\n";
  	}

};


int main()
{
    graph g;
    g.accept();
    g.display();
    g.prims();
}

/*

Enter the no. of vertices: 3

Enter the no. of  Edges: 3

Enter Source: 0

Destination: 1

Cost: 10

Enter Source: 1

Destination: 2

Cost: 2

Enter Source: 2

Destination: 3

Cost: 8

        0       10      0
        10      0       2
        0       2       0
Enter start vertex: 0

Edge from 0 to 1        with cost:  10
Edge from 1 to 2        with cost:  2
Total Cost: 12

*/
