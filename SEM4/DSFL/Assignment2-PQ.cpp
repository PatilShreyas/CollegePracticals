#include<iostream>
#include<string.h>

using namespace std;

//Structure Patient for patient information
typedef struct Patient
{
	int id;
	char name[20];
	struct Patient *next;	
}Patient;
//End Patient

//Class Queue for implementation of Queue using Linked List
class Queue
{
	Patient *front, *rear;
	
public:	
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	
	//Function to Check whether this queue is empty or not
	int isEmpty()
	{
		return ((front==NULL)?1:0);
	}
	
	//Function to insert patient in queue
	void enqueue(int id, char name[])
	{
		Patient *patient = new Patient();
		patient->id = id;
		strcpy(patient->name,name);
		patient->next = NULL;
		
		if(front == NULL)
		{
			front = patient;
			rear = patient;
		}
		else
		{
			rear->next = patient;
			rear = rear->next;
		}
	}
	
	//Function to delete front patient from queue
	void dequeue()
	{
		Patient *patient;
		patient = front;
		cout<<"\n-----------------------------------------";
		cout<<"\nPatient ID :"<<(front->id)<<"\nPatient Name : "<<(front->name)<<endl;
		cout<<"\n-----------------------------------------";
		if(front==rear)
		{
			front = NULL;
			rear = NULL;
		}
		else
		{
			front=front->next;
		}
		delete patient;
	}
	
	//Function to display all Patients in queue
	void display()
	{
		for(Patient *p=front;p!=NULL; p=p->next)
		{
			cout<<"\n"<<(p->id)<<"\t\t"<<(p->name); 
		}
	}
};
//End Queue

//Class PriorityQueue to Implement Priority Queue for Patients
class PriorityQueue
{
	Queue queue[3];
	
public :
	//Function to insert arrival information of patient in PriorityQueue
	void arrive()
	{
		char name[20]; 
		int type;
		int id;
		cout<<"\n Enter Patient ID : ";
		cin>>id;
		cout<<" Enter Patient Name : ";
		cin>>name;
		cout<<"\n---------\n0 = Serious\n1 = Medium\n2 = General\n---------\nSelect type of the Patient :";
		cin>>type;
		if(type<3 && type>=0)
		{
			queue[type].enqueue(id,name);
		}
		else
		{
			cout<<"\n\nINVALID PATIENT TYPE !!!";
		}
	   cout<<"\nPATIENT IS ADMITTED SUCCESSFULLY !!";
	}
	
	//Function to provide service or treat patient and discharge 
	void service()
	{
		int i=0;
		while(i<3 && queue[i].isEmpty())
		{
		  	i++;
		}
		if(i==3)
		{
		  	cout<<"\n NO PATIENTS TO BE SERVICED !!"<<endl;
		}
		else
		{ 
			queue[i].dequeue();
		}
	}
	
	//Function to display all Patients in PriorityQueue
	void display()
	{
		cout<<"\n=======================================";
		cout<<"\nPATIENT ID\tPATIENT NAME";
		cout<<"\n=======================================";
		cout<<"\n*** Serious Patient ***";
		cout<<"\n-----------------------------------";
		queue[0].display();
		cout<<"\n-----------------------------------";
		cout<<"\n*** Medium Illness ***";
		cout<<"\n-----------------------------------";
		queue[1].display();
		cout<<"\n-----------------------------------";
		cout<<"\n*** General ***";
		cout<<"\n-----------------------------------";
		queue[2].display();
		cout<<"\n=======================================";
	}
};

//Function main
int main()
{ 
	PriorityQueue priorityQueue;
	int choice;
	do
	{
		cout<<"\n=======================================";
		cout<<"\n**Main Menu**\n\n1.Arrival of Patient \n2.Service a Patient \n3.Print \n4.Exit \n\nEnter your choice :";
	   	cin>>choice;
	   	switch(choice)
		{
			  case 1:priorityQueue.arrive();
					 break;
			  case 2:priorityQueue.service();
					 break;
			  case 3:priorityQueue.display();
					 break;
			  case 4:cout<<"\n\nThank You !!\n";return 0;
			  default:cout<<"\n\nINVALID CHOICE!! ";
		}
	}while(choice != 4);
}

/*
**OUTPUT**

student@student-OptiPlex-330:~/Desktop/Shreyas$ g++ Assignment2-PQ.cpp
student@student-OptiPlex-330:~/Desktop/Shreyas$ ./a.out

=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :1

 Enter Patient ID : 1
 Enter Patient Name : Piyush

---------
0 = Serious
1 = Medium
2 = General
---------
Select type of the Patient :0

PATIENT IS ADMITTED SUCCESSFULLY !!
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :1

 Enter Patient ID : 2
 Enter Patient Name : Shreyas

---------
0 = Serious
1 = Medium
2 = General
---------
Select type of the Patient :2

PATIENT IS ADMITTED SUCCESSFULLY !!
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :1

 Enter Patient ID : 3
 Enter Patient Name : Aditya

---------
0 = Serious
1 = Medium
2 = General
---------
Select type of the Patient :1

PATIENT IS ADMITTED SUCCESSFULLY !!
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :1

 Enter Patient ID : 4
 Enter Patient Name : ABC

---------
0 = Serious
1 = Medium
2 = General
---------
Select type of the Patient :0

PATIENT IS ADMITTED SUCCESSFULLY !!
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :1

 Enter Patient ID : 5
 Enter Patient Name : XYZ

---------
0 = Serious
1 = Medium
2 = General
---------
Select type of the Patient :2

PATIENT IS ADMITTED SUCCESSFULLY !!
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :3

=======================================
PATIENT ID	PATIENT NAME
=======================================
*** Serious Patient ***
-----------------------------------
1			Piyush
4			ABC
-----------------------------------
*** Medium Illness ***
-----------------------------------
3			Aditya
-----------------------------------
*** General ***
-----------------------------------
2			Shreyas
5			XYZ
=======================================
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :2

-----------------------------------------
Patient ID :1
Patient Name :Piyush

-----------------------------------------
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :2

-----------------------------------------
Patient ID :4
Patient Name :ABC

-----------------------------------------
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :2

-----------------------------------------
Patient ID :3
Patient Name :Aditya

-----------------------------------------
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :2

-----------------------------------------
Patient ID :2
Patient Name :Shreyas

-----------------------------------------
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :2

-----------------------------------------
Patient ID :5
Patient Name :XYZ

-----------------------------------------
=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :2

 NO PATIENTS TO BE SERVICED !!

=======================================
**Main Menu**

1.Arrival of Patient 
2.Service a Patient 
3.Print 
4.Exit 

Enter your choice :4


Thank You !!


*/

