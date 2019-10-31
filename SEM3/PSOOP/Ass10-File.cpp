// Program for File Handling
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
class File
{
	public:
	char fileName[30];
	string content;
	ifstream fin;
	ofstream fout;
	
	//Constructor to initialize
	File(char file[30])
	{
		strcpy(fileName,file);
	}
	
	//Destructor for file closing
	~File()
	{
		fin.close();
		fout.close();
		cout<<"\nFile Closed\n";
	}
	
	void writeFile();
	void readFile();
};

void File::readFile()
{
	fin.open(fileName);
	
	string line;
	
	cout<<"\n==========================";
	cout<<"\nFILE CONTENT :";
	while(getline(fin,line))
	{
			cout<<"\n"<<line;
	}
	fin.close();
	cout<<"\n==========================";
}

void File::writeFile()
{
	cout<<"\nEnter File content to write :";
	cin>>content;
	fout.open(fileName,ios::app);
	fout<<content;
	cout<<"\nFile Written Successfully...!!!";
	fout.close();
}

int main()
{
	int choice;
	char fileName[30];
	cout<<"\nEnter a file name to create :";
	cin>>fileName;
	File file(fileName);
	do
	{
		cout<<"\n==========================";
		cout<<"\nFile: "<<fileName;
		cout<<"\n==========================";
		cout<<"\nMENU";
		cout<<"\n1.Write File";
		cout<<"\n2.Read File";
		cout<<"\n3.Exit";
		
		cout<<"\n\nEnter Choice :";
		cin>>choice;
		
		switch(choice)
		{
			case 1: file.writeFile(); break;
			case 2: file.readFile(); break;
			case 3: cout<<"\nClosing File\n"; break;
			default: cout<<"\nInvalid Choice\n";
		}
	}while(choice != 3);
}

/*
**OUTPUT**
student@student-OptiPlex-330:~/Programs$ g++ Ass10-File.cpp
student@student-OptiPlex-330:~/Programs$ ./a.out

Enter a file name to create :Ass101.txt

==========================
File: Ass101.txt
==========================
MENU
1.Write File
2.Read File
3.Exit

Enter Choice :1

Enter File content to write :HelloWorldHii

File Written Successfully...!!!
==========================
File: Ass101.txt
==========================
MENU
1.Write File
2.Read File
3.Exit

Enter Choice :2

==========================
FILE CONTENT :
HelloWorldHii
==========================
==========================
File: Ass101.txt
==========================
MENU
1.Write File
2.Read File
3.Exit

Enter Choice :3

Closing File
File Closed

[file : Ass101.txt]
HelloWorldHii
*/