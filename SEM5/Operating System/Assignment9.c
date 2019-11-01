#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

// Function Declarations
int show_and_get_choice();
int create_file();
int open_file(int);
void read_file_and_display();
void write_file(char[]);
// END Declarations

// Constants for File Opening Mode
const int FILE_MODE_READ = 1;
const int FILE_MODE_WRITE = 2;

// Flags for file opening modes.
int FLAG_MODE_READ = 0;
int FLAG_MODE_WRITE = 0;

// Constant for FAILURE
const int FAILURE = -1;

// File descriptor
int file_d;

// File Opening mode
int mode;

// Store File name
char filename[20];


int main()
{
	// To store use choice input
	int choice;
	
	// For File Data/Content to write
	char data[30];
	
	// Show Menu Driven structure.	
	do
	{
		switch((choice = show_and_get_choice()))
		{
			case 1: 
				// Create File
				file_d = create_file();
				
				if (file_d == FAILURE)
				{
					printf("\nFile Creation FAILED!");
				}
				else
				{
					printf("\nFile Created SUCCESSFULLY!");
				}
				break;
				
			case 2: 
				// Open File with Read/Write mode
				printf("\n\nSelect File Opening Mode::: [1]Read [2]Write : ");
				scanf("%d", &mode);
				
				file_d = open_file(mode);
				
				if (file_d)
				{
					printf("\nFile is Opened. MODE: %s", ((mode == FILE_MODE_READ) ? "READ" : "WRITE"));
				}
				else 
				{
					printf("\nENTER CORRECT FILE MODE!");
				}
				
				break;
				
			case 3: 
				// Read from File
				
				if (FLAG_MODE_READ)
				{
					read_file_and_display();
				}
				else
				{
					printf("\nFILE NOT IN READ MODE!");
				}
				break;
				
			case 4: 
				// Write into File
				if (FLAG_MODE_WRITE)
				{
					printf("\nEnter the Data to write in file (Type ESC to finish) :\n");
					
					// Read data from keyboard until delimiter ESC is input.
					while(1)
					{
						scanf("%s", data);
						
						if (!strcmp(data, "ESC"))
						{
							break;
						}
						
						// Write data into file. Added Extra whitespace at the end of data.
						write_file(strcat(data, " "));
					}
				}
				else
				{
					printf("\nFILE NOT IN WRITE MODE!");
				}
				break;
				
			case 5: 
				// Seek to the Start of File
				lseek(file_d, 0, SEEK_SET);
				printf("\nFile Pointer is set to the START");
				
				// Seek to the End of File
				lseek(file_d, 0, SEEK_END);
				printf("\nFile Pointer is set to the END");
				
				break;
				
			case 6: 
				// Close File and Terminate Program
				printf("\nClosing File & Exiting Program!\n\n"); 
				close(file_d);
				break;
			
			default: printf("\n\nINVALID CHOICE\n\n");																				
		}
	}while(choice != 6);
}

// Creates file and returns status
int create_file()
{
	// Get name of file from keyboard input
	printf("Enter the Filename: ");
	scanf("%s", filename);
	
	// This function (creat(char* fname, int permission)) creates file in directory.
	// with specified fname and permission.
	// If it returns -1 then operation is failed.
	return creat(filename, 0666);	
}

// Opens file with specified mode.
int open_file(int mode)
{
	// int open(char* path, int flags); Opens file in path with opening file mode.
	
	if (mode == FILE_MODE_READ)
	{
		// Update Flags
		FLAG_MODE_READ = 1;
		FLAG_MODE_WRITE = 0;
		
		// Open File in Read Mode
		return open(filename, O_RDONLY);
	}
	else if (mode == FILE_MODE_WRITE)
	{
		// Update Flags
		FLAG_MODE_READ = 0;
		FLAG_MODE_WRITE = 1;
		
		// Open File in Write Mode
		return open(filename, O_WRONLY);
	}
	else
	{
		// Invalid Mode
		return 0;
	}
}

void read_file_and_display()
{
	char data[30];
	
	// Change Location of Read pointer in file descriptor
	// off_t lseek(int fd, off_t offset, int whence); Sets offset in file descriptor with interpreted whence.
	lseek(file_d, 0, SEEK_SET);
	
	printf("\n\nFile Contents :::");
	
	// Read file using read(fd, buf, cnt); Reads file from fd into buf with buffer length.
	while (read(file_d, data, 30))
	{
		printf("%s", data);
	}
}

// Writes data content into file
void write_file(char data[])
{
	// Seek to the end of file
	lseek(file_d, 0, SEEK_END);
	
	// Write data with specificed length into file descriptor.
	write(file_d, data, strlen(data));
}

// Displays menu and returns user's choice.
int show_and_get_choice()
{
	int choice;
	
	printf("\n===================================");
	printf("\nMENU");
	printf("\n===================================");
	printf("\n1. Create File");
	printf("\n2. Open File");
	printf("\n3. Read Data");
	printf("\n4. Write Data");
	printf("\n5. Seek File");		
	printf("\n6. Exit");
	
	printf("\n\nEnter Choice: ");
	scanf("%d", &choice);
	
	return choice;
}

