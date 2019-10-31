// Program to implement sequential file for students database

#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class Student
{
	private:
	int id;
	char name[30];
	int age;
	double marks;

	public:
	void accept()
	{
		cout<<"\nEnter Following Details :\n";
		cout<<"ID :";
		cin>>id;
		cout<<"Name :";
		cin>>name;
		cout<<"Age :";
		cin>>age;
		cout<<"Marks (%) :";
		cin>>marks;
	}

	void display()
	{
		cout<<"\n"<<id<<"\t"<<name<<"\t\t"<<age<<"\t"<<marks<<"%";
	}

	int getID()
	{
		 return id;
	}
};

class File
{
	public:
	char fileName[30];
	ifstream fin;
	ofstream fout;

	File()
	{
		strcpy(fileName,"Student.dat");
	}
	//Destructor for file closing
	~File()
	{
		fin.close();
		fout.close();
		cout<<"\nFile Closed\n";
	}

	void writeRecord(Student);
	void displayRecords();
	int modifyRecord(int);
	int deleteRecord(int);
};

int File::modifyRecord(int id)
{
    int flag = -1;
	fstream fil;
	ofstream o;
	Student s;
	o.open("new.dat",ios::out|ios::binary);
	fil.open(fileName,ios::in| ios::binary);
	fil.read((char*)&s, sizeof(Student));
	while(!fil.eof())
	{
		if(id == s.getID())
		{
			cout<<"\nEnter new Record :";
			s.accept();
			flag = 1;
		}
		o.write((char*)&s, sizeof(Student));
		fil.read((char*)&s, sizeof(Student));
	}
	o.close();
	fil.close();
	remove(fileName);
	rename("new.dat", fileName);

	return flag;
}


int File::deleteRecord(int id)
{
	int flag = -1;
	fstream fil;
	ofstream o;
	Student s;
	o.open("new.dat",ios::out|ios::binary);
	fil.open(fileName,ios::in| ios::binary);
	fil.read((char*)&s, sizeof(Student));
	while(!fil.eof())
	{
		if(id != s.getID())
		{
			o.write((char*)&s, sizeof(Student));
			flag = 1;
		}

		fil.read((char*)&s, sizeof(Student));
	}
	o.close();
	fil.close();
	remove(fileName);
	rename("new.dat", fileName);
	return flag;
}

void File::displayRecords()
{
	fin.open(fileName);
	Student s;
	while(fin.read((char*)&s, sizeof(Student)))
		s.display();

	fin.close();
}

void File::writeRecord(Student student)
{
	fout.open(fileName,ios::app);
	fout.write((char*)&student, sizeof(student));
	fout.close();
}

void createDatabase()
{
	File file;
	int size;
	cout<<"\nEnter Number of Records :";
	cin>>size;

	Student *student = new Student[size];
	for(int i=0; i<size; i++)
	{
		cout<<"\nEnter Student Record "<<(i+1);
		student[i].accept();
		file.writeRecord(student[i]);
	}

}

void addRecord()
{
	File file;
	Student student;
	cout<<"\nEnter Student Record :";
	student.accept();
	file.writeRecord(student);
	cout<<"\nStudent Record stored successfully !";
}

void modifyRecord()
{
	File file;
	int id;
	cout<<"\nEnter ID to Modify :";
	cin>>id;

	int flag = file.modifyRecord(id);

	if(flag == 1)
		cout<<"\nStudent Record modified successfully !";
	else
		cout<<"\nStudent Record not modified !";
}

void deleteRecord()
{
	File file;
	int id;
	cout<<"\nEnter ID to Delete :";
	cin>>id;

	int flag = file.deleteRecord(id);

	if(flag == 1)
		cout<<"\nStudent Record deleted successfully !";
	else
		cout<<"\nStudent Record not deleted !";
}

void displayRecord()
{
	File file;

	cout<<"\n========================================";
	cout<<"\nID\tNAME\t\tAGE\tMARKS";
	cout<<"\n========================================";
	file.displayRecords();
	cout<<"\n========================================";
}


int main()
{
	int choice;
	do
	{
		cout<<"\n==========================";
		cout<<"\nMENU";
		cout<<"\n1.Create Database";
		cout<<"\n2.Display Database";
		cout<<"\n3.Add Record";
		cout<<"\n4.Modify Record";
		cout<<"\n5.Delete Record";
		cout<<"\n6.Exit";

		cout<<"\n\nEnter Choice :";
		cin>>choice;

		switch(choice)
		{
			case 1: createDatabase(); break;
			case 2: displayRecord(); break;
			case 3: addRecord(); break;
			case 4: modifyRecord(); break;
			case 5: deleteRecord(); break;
			case 6: cout<<"\nExiting...\n"; break;
			default: cout<<"\nInvalid Choice\n";
		}
	}while(choice != 6);
}

/*
**OUTPUT**
student@student-OptiPlex-330:~/Programs$ g++ Ass10-File.cpp
student@student-OptiPlex-330:~/Programs$ ./a.out

==========================
MENU
1.Create Database
2.Display Database
3.Add Record
4.Modify Record
5.Delete Record
6.Exit

Enter Choice :1

Enter Number of Records :2

Enter Student Record 1
Enter Following Details :
ID :1
Name :Shreyas
Age :19
Marks (%) :90

Enter Student Record 2
Enter Following Details :
ID :2
Name :Ankit
Age :19
Marks (%) :80

File Closed

==========================
MENU
1.Create Database
2.Display Database
3.Add Record
4.Modify Record
5.Delete Record
6.Exit

Enter Choice :2

========================================
ID      NAME            AGE     MARKS
========================================
1       Shreyas         19      90%
2       Ankit           19      80%
File Closed

==========================
MENU
1.Create Database
2.Display Database
3.Add Record
4.Modify Record
5.Delete Record
6.Exit

Enter Choice :3

Enter Student Record :
Enter Following Details :
ID :3
Name :Patil
Age :20
Marks (%) :91.90

Student Record stored successfully !
File Closed

==========================
MENU
1.Create Database
2.Display Database
3.Add Record
4.Modify Record
5.Delete Record
6.Exit

Enter Choice :2

========================================
ID      NAME            AGE     MARKS
========================================
1       Shreyas         19      90%
2       Ankit           19      80%
3       Patil           20      91.9%
File Closed

==========================
MENU
1.Create Database
2.Display Database
3.Add Record
4.Modify Record
5.Delete Record
6.Exit

Enter Choice :4

Enter ID to Modify :2

Enter new Record :
Enter Following Details :
ID :2
Name :Ankit
Age :22
Marks (%) :95.00

Student Record modified successfully !
File Closed

==========================
MENU
1.Create Database
2.Display Database
3.Add Record
4.Modify Record
5.Delete Record
6.Exit

Enter Choice :2

========================================
ID      NAME            AGE     MARKS
========================================
1       Shreyas         19      90%
2       Ankit           22      95%
3       Patil           20      91.9%
File Closed

==========================
MENU
1.Create Database
2.Display Database
3.Add Record
4.Modify Record
5.Delete Record
6.Exit

Enter Choice :5

Enter ID to Delete :3

Student Record deleted successfully !
File Closed

==========================
MENU
1.Create Database
2.Display Database
3.Add Record
4.Modify Record
5.Delete Record
6.Exit

Enter Choice :2

========================================
ID      NAME            AGE     MARKS
========================================
1       Shreyas         19      90%
2       Ankit           22      95%
File Closed

==========================
MENU
1.Create Database
2.Display Database
3.Add Record
4.Modify Record
5.Delete Record
6.Exit

Enter Choice :6

Exiting...

*/
