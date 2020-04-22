
#include<stdio.h>
void sum(int a[10],int n);
void main()

{
int i,j,a[10],n,temp;
printf("\nenter the number of process");
scanf("%d",&n);
printf("\nenter the size of process");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]==a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\nthe sorted process is \n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
sum(a,n);
}
 void sum(int a[20],int n)
 
 {
 int psum=0,sum=0,i,avg;
 for(i=0;i<n;i++)
 {
 psum=psum+a[i];
sum=sum+psum;
}
printf("\ntotal retrival time is %d\n",sum);
avg=sum/n;
printf("\nAverage retrival time is %d\n",avg);
}
/*
student@student:~$ gcc singletape.c
student@student:~$ ./a.out

enter the number of process5

enter the size of process25
35
15
40
22

the sorted process is 
25	35	15	40	22	

total retrival time is 412

Average retrival time is 82
*/



