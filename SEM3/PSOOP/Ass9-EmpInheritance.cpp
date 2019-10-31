#include<iostream>
#include<stdio.h>

using namespace std;

class PersonalRecord
{
	protected :
	char name[30];
	char dob[15];
	char bloodGroup[5];
};

class ProfessionalRecord
{ 
	protected :
	char specialization[20];
	double experience;
};

class AcademicRecord
{
	protected :
	char exam[30];
	double aggregate;
};

class Employee : public PersonalRecord, public ProfessionalRecord, public AcademicRecord
{
	public:
	
	void accept()
	{
		cout<<"\nEnter The Following Values :";
		
		cout<<"\nName :";
		cin>>name;
		cout<<"\nDate of Birth (DD/MM/YYYY) :";
		cin>>dob;
		cout<<"\nBlood Group :";
		cin>>bloodGroup;
		
		cout<<"\nSpecialization:";
		cin>>specialization;
		cout<<"\nExperience (In Years):";
		cin>>experience;
		
		cout<<"\nExam Appeared :";
		cin>>exam;
		cout<<"\nAggregate (%) :";
		cin>>aggregate;
		
	}
	
	void display()
	{		
		cout<<"\n===================================";			
		cout<<"\n\n**BIO DATA**";
		cout<<"\n===================================";		
		cout<<"\n\nPERSONAL DETAILS :::";	
		cout<<"\nName :"<<name;
		cout<<"\nDate of Birth :"<<dob;
		cout<<"\nBlood Group :"<<bloodGroup;
		cout<<"\n---------------------------------------";
		cout<<"\n\nPROFESSIONAL DETAILS :::";	
		cout<<"\nSpecialization : "<<specialization;
		cout<<"\nExperience :"<<experience<<" Years";
		cout<<"\n---------------------------------------";
		cout<<"\n\nACADEMIC DETAILS :::";
		cout<<"\nExam :"<<exam;
		cout<<"\nAggregate :"<<aggregate<<"%";
		cout<<"\n---------------------------------------";
	}
};

int main()
{
	Employee employee;
	int choice;
	
	do{
		cout<<"\n========================";
		cout<<"\nMENU";
		cout<<"\n1.Insert Data\n2.Display Bio Data\n3.Exit";
		
		cout<<"\n\nEnter your Choice :";
		cin>>choice;
		
		switch(choice)
		{
			case 1: employee.accept();break;
			case 2: employee.display();break;
			case 3: cout<<"\n\nThank You !\n\n";break;
				
			default: cout<<"\n\nEnter correct option !!!";
		}
	}while(choice != 3);
}

/*
	**OUTPUT**
	
student@student-OptiPlex-330:~/Programs$ g++ Ass9-Emp.cpp
student@student-OptiPlex-330:~/Programs$ ./a.out

========================
MENU
1.Insert Data
2.Display Bio Data
3.Exit

Enter your Choice :1

Enter The Following Values :
Name :Shreyas_Patil        

Date of Birth (DD/MM/YYYY) :12/05/1999

Blood Group :O+

Specialization:Java

Experience (In Years):5

Exam Appeared :Diploma_MSBTE

Aggregate (%) :87.56

========================
MENU
1.Insert Data
2.Display Bio Data
3.Exit

Enter your Choice :2

===================================

**BIO DATA**
===================================

PERSONAL DETAILS :::
Name :Shreyas_Patil
Date of Birth :12/05/1999
Blood Group :O+
---------------------------------------

PROFESSIONAL DETAILS :::
Specialization : Java
Experience :5 Years
---------------------------------------

ACADEMIC DETAILS :::
Exam :Diploma_MSBTE
Aggregate :87.56%
---------------------------------------
========================
MENU
1.Insert Data
2.Display Bio Data
3.Exit

Enter your Choice :3


Thank You !



*/
