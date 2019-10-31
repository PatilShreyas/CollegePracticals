#include<iostream>
#include<string.h>

const int SIZE = 2;

using namespace std;

class PersonalInfo
{
	public :
	char name[20];
	
	protected :
	char dob[10];
	char bloodGroup[2];
};

class Physic
{
	protected :
	double height;
	double weight;
};

class Insurance
{
	protected :
	long int policyNo;
	char address[30];
};

class Person : public PersonalInfo, public Physic, public Insurance
{
	protected :
	char telNo[10];
	char drivingLicenceNo[10];
	int status;
	
	public:
	
	void accept()
	{
		cout<<"\nEnter the Name :";
		cin>>name;
		cout<<"\nEnter the Date of Birth:";
		cin>>dob;
		cout<<"\nEnter the Blood Group :";
		cin>>bloodGroup;
		
		cout<<"\nEnter the Height :";
		cin>>height;
		cout<<"\nEnter the Weight :";
		cin>>weight;
		
		cout<<"\nEnter the Policy No :";
		cin>>policyNo;
		cout<<"\nEnter the Address:";
		cin>>address;
		
		cout<<"\nEnter the Contact No :";
		cin>>telNo;
		cout<<"\nEnter the Driving Licence No :";
		cin>>drivingLicenceNo;
		
		status=1;
	}
	
	void display()
	{
		cout<<"\t"<<name<<"\t"<<dob<<"\t"<<bloodGroup<<"\t"<<height<<"\t"<<weight<<"\t"<<policyNo<<"\t"<<address<<"\t"<<telNo<<"\t"<<drivingLicenceNo;				
	}
	
	void remove()
	{
		status = 0;
	}
	
	int getState()
	{
		return status;
	}

	
};

int main()
{
	Person person[SIZE];
	int choice;
	
	do{
		cout<<"\n========================";
		cout<<"\nMENU";
		cout<<"\n1.Insert Data\n2.Display Data\n3.Delete\n4.Search\n5.Exit";
		
		cout<<"\n\nEnter your Choice :";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				for(int i=0; i<SIZE; i++)
				{
					cout<<"\nEnter Data for Person "<<(i+1);
					person[i].accept();
					cout<<"\n-------------------------------------";
				}
				break;
				
			case 2:
	cout<<"\n=========================================================================================";
				cout<<"\nID\tNAME\tDOB\t\tBD.GRP\tHT\tWT\tPOL.NO\tADDRESS\tCONTACT\tDRI.LI.NO";
	cout<<"\n=========================================================================================";
				for(int i=0; i<SIZE; i++)
				{
					if(person[i].getState())
					{
						cout<<"\n"<<(i+1);
						person[i].display();
						cout<<"\n----------------------------------------------------------------------------------------";
					}
				}
	cout<<"\n=========================================================================================";
				break;
				
			case 3:
				cout<<"\nEnter ID to Delete :";
				int id;
				cin>>id;
				
				if(id>=1 && id<=SIZE)
				{
					person[id-1].remove();
					cout<<"\nData is successfully deleted !";
				}
				break;
				
			case 4:
				char search[30];
				cout<<"\nEnter the name to search :";
				cin>>search;			
	cout<<"\n=========================================================================================";
				cout<<"\nID\tNAME\tDOB\t\tBD.GRP\tHT\tWT\tPOL.NO\tADDRESS\tCONTACT\tDRI.LI.NO";
	cout<<"\n=========================================================================================";
	
				for(int i=0; i<SIZE; i++)
				{
					if(person[i].getState())
					{
						if(strcmp(search,person[i].name) == 0)
						{
							cout<<"\n"<<(i+1);
							person[i].display();
							cout<<"\n----------------------------------------------------------------------------------------";
						}
					}
				}				cout<<"\n=========================================================================================";
	
				break;
				
			case 5:
				cout<<"\n\nThank You !\n\n";
				break;
				
			default: cout<<"\n\nEnter correct option !!!";
		}
	}while(choice != 5);
}



/*

 **OUTPUT**
 
student@student-OptiPlex-330:~/Desktop/Shreyas/Shreyas_CPP$ g++ Inheritance.cpp
student@student-OptiPlex-330:~/Desktop/Shreyas/Shreyas_CPP$ ./a.out

========================
MENU
1.Insert Data
2.Display Data
3.Delete
4.Search
5.Exit

Enter your Choice :1

Enter Data for Person 1
Enter the Name :Shreyas

Enter the Date of Birth:12/05/1999

Enter the Blood Group :O

Enter the Height :55

Enter the Weight :66

Enter the Policy No :34544

Enter the Address:Pune

Enter the Contact No :546456

Enter the Driving Licence No :456456

-------------------------------------
Enter Data for Person 2
Enter the Name :Piyush

Enter the Date of Birth:11/12/1997

Enter the Blood Group :O

Enter the Height :66

Enter the Weight :55

Enter the Policy No :34554

Enter the Address:Pune

Enter the Contact No :345645 

Enter the Driving Licence No :345345

-------------------------------------
========================
MENU
1.Insert Data
2.Display Data
3.Delete
4.Search
5.Exit

Enter your Choice :2

====================================================================================
ID	NAME	DOB			BD.GRP	HT	WT	POL.NO	ADDRESS	CONTACT	DRI.LI.NO
====================================================================================
1	Shreyas	12/05/1999	O		55	66	34544	Pune	546456	456456
------------------------------------------------------------------------------------
2	Piyush	11/12/1997	O		66	55	34554	Pune	345645	345345
------------------------------------------------------------------------------------
====================================================================================
========================
MENU
1.Insert Data
2.Display Data
3.Delete
4.Search
5.Exit

Enter your Choice :4

Enter the name to search :Shreyas

====================================================================================
ID	NAME	DOB			BD.GRP	HT	WT	POL.NO	ADDRESS	CONTACT	DRI.LI.NO
====================================================================================
1	Shreyas	12/05/1999	O		55	66	34544	Pune	546456	456456
------------------------------------------------------------------------------------
====================================================================================
========================
MENU
1.Insert Data
2.Display Data
3.Delete
4.Search
5.Exit

Enter your Choice :3

Enter ID to Delete :2

Data is successfully deleted !
========================
MENU
1.Insert Data
2.Display Data
3.Delete
4.Search
5.Exit

Enter your Choice :2

====================================================================================
ID	NAME	DOB			BD.GRP	HT	WT	POL.NO	ADDRESS	CONTACT	DRI.LI.NO
====================================================================================
1	Shreyas	12/05/1999	O		55	66	34544	Pune	546456	456456
------------------------------------------------------------------------------------
====================================================================================
========================
MENU
1.Insert Data
2.Display Data
3.Delete
4.Search
5.Exit

Enter your Choice :5


Thank You !


*/



