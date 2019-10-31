#include<iostream>
using namespace std;
#include<stdlib.h>

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

void spantree(int *a,int n)
{
    int i,j,flag[3]={0,0,0},totaledge=n*(n-1)/2,sflag,temp,total;
    int *s,edge=0,check1,check2;

    s=new int[totaledge*3];
    while(edge < totaledge)
    {
      	flag[2]=36000;
   	  	for(i=0 ; i<n ; i++)
      	{
    		for(j=i+1 ; j<n ; j++)
    		{
    			temp=0; sflag=0;
    			if(*(a+i*n+j) < flag[2] && *(a+i*n+j)!=0)
    			{
    				while(temp!=edge)
    				{
    					if(*(s+temp*3+0)==i && *(s+temp*3+1)==j && *(s+temp*3+2)==*(a+i*n+j))
                            sflag=1;
    					temp++;
    				}
    				if(sflag!=1)
    				{
    				    flag[0]=i;
    				    flag[1]=j;
    				    flag[2]=*(a+i*n+j);
    			    }
     		    }
     		}

      	}
		*(s+edge*3+0)=flag[0];
	 	*(s+edge*3+1)=flag[1];
	   	*(s+edge*3+2)=flag[2];
    	edge++;
	}

	cout<<"\n\tStart pt.   End pt.   Weight";
	total=0;
	for(i=0 ; i<totaledge ; i++)
	{
    	check1=0; check2=0;
	    for(j=0 ; j<i ; j++)
	    {
	        if(*(s+i*3+0)==*(s+j*3+0) || *(s+i*3+0)==*(s+j*3+1))
	            check1++;

	        if(*(s+i*3+1)==*(s+j*3+0) || *(s+i*3+1)==*(s+j*3+1))
	            check2++;
	    }

	    if(check1<2 && check2<2 || check1==0 || check2==0)
	    {
	        cout<<"\n\t"<<*(s+i*3+0)<<"\t\t"<<*(s+i*3+1)<<"\t"<<*(s+i*3+2);
	        total+=*(s+i*3+2);
	    }
	}
	cout<<"\n\n\tWeight of Min-Spanning Tree is : "<<total;
}




int main()
{
    int *a,n,flag,choice;

    cout<<"\n\t\t**Minimum Spanning Tree using Kruskal's alorithm**\n";
    cout<<"\n\tEnter the No.of Vertices : ";
    cin>>n;
    a=new int[n*n];
    accept(a,n);

    do
    {
		cout<<"\n--------------------MENU--------------------";
		cout<<"\n\t1:Display Adjacency matrix\n\t2:Min. Spanning Tree\n\t0:Exit : ";
		cin>>choice;

		switch(choice)
		{
		    case 1:
		        display(a,n);
		        break;
		    case 2:
		        spantree(a,n);
		        break;
		}
    }while(choice!=0);

    cout<<"\n";
    return 0;
}
