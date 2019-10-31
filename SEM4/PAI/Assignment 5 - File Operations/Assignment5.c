#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<conio.h>
void main()
{
	int ch;
	char name[20];
	union REGS i,o;
	clrscr();
	do
	{
		printf("\n## MENU ##\n\n1.Create directory\n2.Delete directory\n3.Create File\n4.Delete File\n5.Exit\n\nEnter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the name of directory to be created:");
				scanf("%s",name);
				i.h.ah=0x39;
				i.x.dx=FP_OFF(name);
				int86(0x21,&i,&o);
				printf("\n%s (Directory)Has been Created successfully",name);
				break;
				
			case 2:
				printf("\nEnter the name of file to be deleted:");
				scanf("%s",name);
				i.h.ah=0x3A;
				i.x.dx=FP_OFF(name);
				int86(0x21,&i,&o);
				printf("\n%s (Directory)Has been deleted successfully",name);
				break;
				
			case 3:
				printf("\nEnter the name of file to be created:");
				scanf("%s",name);
				i.h.ah=0x3C;
				i.x.dx=FP_OFF(name);
				int86(0x21,&i,&o);
				printf("\n%s (file)Has been Created successfully",name);
				break;
			case 4:
				printf("\nEnter the name of file to be deleted:");
				scanf("%s",name);
				i.h.ah=0x41;
				i.x.dx=FP_OFF(name);
				int86(0x21,&i,&o);
				printf("\n%s (file)Has been deleted successfully",name);
				break;
				
			case 5:break;
		}
	}while(ch!=5)
}