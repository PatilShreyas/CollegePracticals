#include<stdio.h>
int i,j,n,t=3;
int p[30],l[30],temp,m,tape[10][10],tape1[30][30];
int itemcount[10];
int c1=0,c2=0,c3=0;
float mrt[10];
void getval()
{
printf("\nenter the number of program");
scanf("%d",&n);
printf("\nenter the numberof tapes");
scanf("%d",&t);
for(i=0;i<n;i++)
{
printf("Enter length of program %d",i+1);
scanf("%d",&l[i]);
p[i]=i;
}
for(i=1;i<t;i++)
{
for(j=0;j<30;j++)
tape[i][j]=0;
}
}

void sort()
{
for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(l[i]>l[j+1])
{
temp=l[j];
l[j]=l[j+1];
l[j+1]=temp;

m=p[j];
p[j]=p[j+1];
p[j+1]=m;

}
}
}

for(i=0;i<n;i++)
{
printf("program %d\t",p[i]);
printf("length %d\n",l[i]);
}
}

void arrange()
{
int count=0;
int r=0;
for(i=0;i<10;i++)
itemcount[i]=0;
for(i=0;i<n;i++)
{
count++;
tape[count][r]=l[i];
itemcount[count]++;
if(count==t)
{
r++;
count=0;
}
}
}
void printtape()
{
int r=0;
for(i=1;i<=t;i++)
{
printf("\ntape %d",i);
while(tape[i][r]!=0)
{
printf("%d\t",tape[i][r]);
r++;
}
printf("\n");
r=0;
}
}
void calmrt()
{
int r=0,it,k;
float sum[10];
for(i=0;i<10;i++)
{
sum[i]=0;
}
j=0;
for(i=1;i<=t;i++)
{

for(j=0;j<itemcount[i];j++)
{
for(k=0;k<=j;k++)
{
sum[i]=sum[i]+tape[i][k];
}
r++;
it--;
}
r=0;
mrt[i]=sum[i]/itemcount[i];
printf("Mrt of tape %d is %f\n",i,mrt[i]);
}
}

void finalmrt()
{
float final_mrt=0;
for(i=1;i<=t;i++)
{
final_mrt+=mrt[i];
}
final_mrt=final_mrt/t;
printf("finalmrts %f\n",final_mrt);
}

int main()
{
getval();
sort();
arrange();
printtape();
calmrt();
finalmrt();
return 0;
}

/*
student@student:~$ gcc multitape.c
student@student:~$ ./a.out

enter the number of program5

enter the numberof tapes3
Enter length of program 12
Enter length of program 21
Enter length of program 33
Enter length of program 44
Enter length of program 55
program 2	length 3
program 0	length 2
program 3	length 4
program 1	length 1
program 4	length 5

tape 13	1	

tape 22	5	

tape 34	
Mrt of tape 1 is 3.500000
Mrt of tape 2 is 4.500000
Mrt of tape 3 is 4.000000
finalmrts 4.000000
*/

*/

