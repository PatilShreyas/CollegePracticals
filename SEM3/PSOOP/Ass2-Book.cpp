#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
class Book
{
private:
    int id;
    char name[30];
    char author[30];
    char publisher[30];
    float price;
    int av_stock;

    static int tx_success;
    static int tx_failed;

public:
    Book(){}
    void setData(int id, char name[30], char author[30], char publisher[30], float price, int av_stock)
    {
        this->id = id;
        strcpy(this->name,name);
        strcpy(this->author,publisher);
        strcpy(this->publisher,publisher);
        this->price = price;
        this->av_stock = av_stock;
    }

    void display()
    {
        cout<<"\n"<<id<<"\t"<<name<<"\t\t"<<author<<"\t\t"<<publisher<<"\t\t"<<"Rs."<<price<<"\t\t"<<av_stock;
    }

    static int getSuccessTxCount()
    {
        return tx_success;
    }
    static int getFailedTxCount()
    {
        return tx_failed;
    }

    static void success()
    {
        tx_success++;
    }
    static void failed()
    {
        tx_failed++;
    }

    int getID()
    {
        return id;
    }

    void purchase()
    {
        av_stock--;
    }
};
int Book::tx_success;
int Book::tx_failed;

int searchBook(Book book[], int n, int key)
{
    int res = -1;

    for(int i=0; i<n; i++)
    {
        if(key == book[i].getID())
        {
            res = i;
        }
    }
    return res;
}

int addBooks(Book book[], int n)
{
    int total = 0;
    for(int i=0; i<n; i++)
    {
        int id, av_stock;
        char name[30], author[30], publisher[30];
        float price;
        cout<<"\n==============================";
        cout<<"\nEnter The Details of Book"<<(i+1);
        cout<<"\nBook ID :";
        cin>>id;

        if(searchBook(book,n,id) != -1)
        {
            cout<<"\nBOOK ALREADY EXISTS WITH THIS ID...!!!";
            Book::failed();
        }
        else
        {
            cout<<"Book Name :";
            cin>>name;
            cout<<"Author :";
            cin>>author;
            cout<<"Publisher :";
            cin>>publisher;
            cout<<"Price :";
            cin>>price;
            cout<<"Available Stock :";
            cin>>av_stock;

            book[i].setData(id,name,author,publisher,price,av_stock);
            total++;
            Book::success();
        }
    }
    return total;
}



void displayBook(Book book[], int total)
{
    cout<<"\n-----------------------------------------------------------------------------------------";
    cout<<"\nID\tNAME\t\tAUTHOR\t\tPUBLISHER\tPRICE\t\tSTOCK";
    cout<<"\n-----------------------------------------------------------------------------------------";
    for(int i=0; i<total; i++)
    {
        book[i].display();
    }
    cout<<"\n-----------------------------------------------------------------------------------------";
}

void displayBook(Book book)
{
    cout<<"\n-----------------------------------------------------------------------------------------";
    cout<<"\nID\tNAME\t\tAUTHOR\t\tPUBLISHER\tPRICE\t\tSTOCK";
    cout<<"\n-----------------------------------------------------------------------------------------";
    book.display();
    cout<<"\n-----------------------------------------------------------------------------------------";
}

void updateBook(Book book[], int n)
{
    int id;

    cout<<"\nEnter the ID of Book to Update :";
    cin>>id;

    int s = searchBook(book,n,id);
    if(s == -1)
    {
        cout<<"\nNO BOOK RECORD FOUND WITH THIS ID !!!";
        Book::failed();
        return;
    }
    else
    {
        int id, av_stock;
        char name[30], author[30], publisher[30];
        float price;
        cout<<"\n==============================";
        cout<<"\nEnter The Details of Book";

        cout<<"Book Name :";
        cin>>name;
        cout<<"Author :";
        cin>>author;
        cout<<"Publisher :";
        cin>>publisher;
        cout<<"Price :";
        cin>>price;
        cout<<"Available Stock :";
        cin>>av_stock;

        book[s].setData(id,name,author,publisher,price,av_stock);
        Book::success();
    }
}
int main()
{
    int choice;
    int total=0,n;
    cout<<"\nEnter The Number of Books :";
    cin>>n;

    Book *book = new Book[n];
    do
    {
        cout<<"\n=====================================";
        cout<<"\nTOTAL BOOKS :"<<total;
        cout<<"\nSUCCESSFUL TRANSACTIONS :"<<Book::getSuccessTxCount();
        cout<<"\nFAILED TRANSACTIONS :"<<Book::getFailedTxCount();
        cout<<"\n=====================================";
        cout<<"\nMENU";
        cout<<"\n1.Add\n2.Display\n3.Update\n4.Search\n5.Purchase\n6.Exit";
        cout<<"\n\nEnter Choice :";
        cin>>choice;

        switch(choice)
        {
            case 1:
                total = addBooks(book,n);
                break;

            case 2:
                displayBook(book,total);
                break;

            case 3:
                updateBook(book,total);
                break;

            case 4:
                int id;
                cout<<"\nEnter Book ID to search :";
                cin>>id;
                int s;
                s = searchBook(book,total,id);
                if(s != -1)
                {
                    displayBook(book[s]);
                    Book::success();
                }
                else
                {
                    cout<<"\nBOOK RECORD NOT FOUND !!!";
                    Book::failed();
                }
                break;

            case 5:
                int k;
                cout<<"\nEnter the Book ID to Purchase :";
                cin>>k;

                int r;
                r = searchBook(book,total,k);

                if(r != -1)
                {
                    cout<<"\nBook is Available, Details are below :";
                    displayBook(book[r]);

                    cout<<"\nWant to purchase ? (Yes=1, No=2) :";
                    int ch;
                    cin>>ch;

                    if(ch==1)
                    {
                        book[r].purchase();
                        Book::success();
                        cout<<"\nBook Purchased Successfully....";
                    }
                    else if(ch==2)
                    {
                        cout<<"\nTransaction Canceled....";
                        Book::failed();
                    }
                }
                break;
            case 6: cout<<"\nThank You !!!\n";break;

            default:cout<<"\nINVALID CHOICE\n";break;

        }
    }while(choice != 6);
    return 0;
}

/*
    **OUTPUT**

student@student-OptiPlex-330:~/Programs$ g++ Ass2-Book.cpp
student@student-OptiPlex-330:~/Programs$ ./a.out

Enter The Number of Books :2

=====================================
TOTAL BOOKS :0
SUCCESSFUL TRANSACTIONS :0
FAILED TRANSACTIONS :0
=====================================
MENU
1.Add
2.Display
3.Update
4.Search
5.Purchase
6.Exit

Enter Choice :1

==============================
Enter The Details of Book1
Book ID :1
Book Name :CProgramming
Author :SSP
Publisher :SSP
Price :100
Available Stock :101

==============================
Enter The Details of Book2
Book ID :2
Book Name :C++Programming
Author :SSP
Publisher :SSP
Price :200
Available Stock :101

=====================================
TOTAL BOOKS :2
SUCCESSFUL TRANSACTIONS :2
FAILED TRANSACTIONS :0
=====================================
MENU
1.Add
2.Display
3.Update
4.Search
5.Purchase
6.Exit

Enter Choice :2

-----------------------------------------------------------------------------------------
ID      NAME                    AUTHOR          PUBLISHER       PRICE           STOCK
-----------------------------------------------------------------------------------------
1       CProgramming            SSP             SSP             Rs.100          101
2       C++Programming          SSP             SSP             Rs.200          101
-----------------------------------------------------------------------------------------
=====================================
TOTAL BOOKS :2
SUCCESSFUL TRANSACTIONS :2
FAILED TRANSACTIONS :0
=====================================
MENU
1.Add
2.Display
3.Update
4.Search
5.Purchase
6.Exit

Enter Choice :3

Enter the ID of Book to Update :4

NO BOOK RECORD FOUND WITH THIS ID !!!
=====================================
TOTAL BOOKS :2
SUCCESSFUL TRANSACTIONS :2
FAILED TRANSACTIONS :1
=====================================
MENU
1.Add
2.Display
3.Update
4.Search
5.Purchase
6.Exit

Enter Choice :3

Enter the ID of Book to Update :1

==============================
Enter The Details of BookBook Name :C_Progamming
Author :SSP
Publisher :SSP
Price :202
Available Stock :200

=====================================
TOTAL BOOKS :2
SUCCESSFUL TRANSACTIONS :3
FAILED TRANSACTIONS :1
=====================================
MENU
1.Add
2.Display
3.Update
4.Search
5.Purchase
6.Exit

Enter Choice :2

-----------------------------------------------------------------------------------------
ID      NAME                    AUTHOR          PUBLISHER       PRICE           STOCK
-----------------------------------------------------------------------------------------
16      C_Progamming            SSP             SSP             Rs.202          200
2       C++Programming          SSP             SSP             Rs.200          101
-----------------------------------------------------------------------------------------
=====================================
TOTAL BOOKS :2
SUCCESSFUL TRANSACTIONS :3
FAILED TRANSACTIONS :1
=====================================
MENU
1.Add
2.Display
3.Update
4.Search
5.Purchase
6.Exit

Enter Choice :4

Enter Book ID to search :2

-----------------------------------------------------------------------------------------
ID      NAME                    AUTHOR          PUBLISHER       PRICE           STOCK
-----------------------------------------------------------------------------------------
2       C++Programming          SSP             SSP             Rs.200          101
-----------------------------------------------------------------------------------------
=====================================
TOTAL BOOKS :2
SUCCESSFUL TRANSACTIONS :4
FAILED TRANSACTIONS :1
=====================================
MENU
1.Add
2.Display
3.Update
4.Search
5.Purchase
6.Exit

Enter Choice :5

Enter the Book ID to Purchase :2

Book is Available, Details are below :
-----------------------------------------------------------------------------------------
ID      NAME                    AUTHOR          PUBLISHER       PRICE           STOCK
-----------------------------------------------------------------------------------------
2       C++Programming          SSP             SSP             Rs.200          101
-----------------------------------------------------------------------------------------
Want to purchase ? (Yes=1, No=2) :2

Transaction Canceled....
=====================================
TOTAL BOOKS :2
SUCCESSFUL TRANSACTIONS :4
FAILED TRANSACTIONS :2
=====================================
MENU
1.Add
2.Display
3.Update
4.Search
5.Purchase
6.Exit

Enter Choice :5

Enter the Book ID to Purchase :2

Book is Available, Details are below :
-----------------------------------------------------------------------------------------
ID      NAME                    AUTHOR          PUBLISHER       PRICE           STOCK
-----------------------------------------------------------------------------------------
2       C++Programming          SSP             SSP             Rs.200          101
-----------------------------------------------------------------------------------------
Want to purchase ? (Yes=1, No=2) :1

Book Purchased Successfully....
=====================================
TOTAL BOOKS :2
SUCCESSFUL TRANSACTIONS :5
FAILED TRANSACTIONS :2
=====================================
MENU
1.Add
2.Display
3.Update
4.Search
5.Purchase
6.Exit

Enter Choice :4

Enter Book ID to search :2

-----------------------------------------------------------------------------------------
ID      NAME                    AUTHOR          PUBLISHER       PRICE           STOCK
-----------------------------------------------------------------------------------------
2       C++Programming          SSP             SSP             Rs.200          100
-----------------------------------------------------------------------------------------
=====================================
TOTAL BOOKS :2
SUCCESSFUL TRANSACTIONS :6
FAILED TRANSACTIONS :2
=====================================
MENU
1.Add
2.Display
3.Update
4.Search
5.Purchase
6.Exit

Enter Choice :6

Thank You !!!


*/
