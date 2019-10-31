#include<iostream>
using namespace std;

class WeatherReport {

	private :
	int day;
	float highTemp;
	float lowTemp;
	float amountRain;
	float amountSnow;

	public:
	WeatherReport(){
		day = 0;
		highTemp = 0;
		lowTemp = 0;
		amountRain = 0;
		amountSnow = 0;
	}
	WeatherReport(int d, float hTemp, float lTemp, float amtRain, float amtSnow){
		day = d;
		highTemp = hTemp;
		lowTemp = lTemp;
		amountRain = amtRain;
		amountSnow = amtSnow;
	}

	void accept();
	void display();

	float getHighTemp(){
		return highTemp;
	}
	float getLowTemp(){
		return lowTemp;
	}
	float getAmountRain(){
		return amountRain;
	}
	float getAmountSnow(){
		return amountSnow;
	}
};

void WeatherReport::accept(){
	cout<<"\nEnter Day of Month :";
	cin>>day;
	cout<<"\nEnter High Temperature :";
	cin>>highTemp;
	cout<<"\nEnter Low Temperature:";
	cin>>lowTemp;
	cout<<"\nEnter Amount of Rain :";
	cin>>amountRain;
	cout<<"\nEnter Amount of Snow :";
	cin>>amountSnow;
}

void WeatherReport::display(){

	cout<<"\n"<<day<<"\t"<<highTemp<<"\t\t"<<lowTemp<<"\t\t"<<amountRain<<"\t\t"<<amountSnow;

}

int main(){
	int choice;
	WeatherReport weatherReport[3];

	do{
		cout<<"\n* WELCOME TO THE WEATHER REPORT *";
		cout<<"\n\nMENU";
		cout<<"\n1.Set Report\n2.Generate Report\n3.Generate Average Report\n4.Exit";
		cout<<"\n\nEnter Choice :";
		cin>>choice;

		switch(choice){
			case 1:
				for(int i=0; i<3; i++){
					cout<<"\n=============================================================================";
					cout<<"\nEnter Weather Report "<<(i+1);
					weatherReport[i].accept();
					cout<<"\n=============================================================================\n";
				}
				break;

			case 2:
				cout<<"\n=============================================================================";
				cout<<"\nDAY\tHIGH TEMP\tLOW TEMP\tAMT.RAIN\tAMT.SNOW";
				cout<<"\n=============================================================================";
				for(int i=0; i<3; i++){
					weatherReport[i].display();
					cout<<"\n-----------------------------------------------------------------------------";
				}
				cout<<"\n=============================================================================\n";
				break;

			case 3:
				float sumHighTemp=0, sumLowTemp=0, sumAmtRain=0, sumAmtSnow=0;

				for(int i=0; i<3; i++){
					sumHighTemp = sumHighTemp + weatherReport[i].getHighTemp();
					sumLowTemp = sumLowTemp + weatherReport[i].getLowTemp();
					sumAmtRain = sumAmtRain + weatherReport[i].getAmountRain();
					sumAmtSnow = sumAmtSnow + weatherReport[i].getAmountSnow();
				}
				float avgHighTemp = sumHighTemp/3;
				float avgLowTemp = sumLowTemp/3;
				float avgAmtRain = sumAmtRain/3;
				float avgAmtSnow = sumAmtSnow/3;

				cout<<"\n=============================================================================";
				cout<<"\n**AVERAGE REPORT**";
				cout<<"\n=============================================================================";
				cout<<"\nHIGH TEMP\tLOW TEMP\tAMT.RAIN\tAMT.SNOW";
				cout<<"\n=============================================================================";
				cout<<"\n"<<avgHighTemp<<"\t\t"<<avgLowTemp<<"\t\t"<<avgAmtRain<<"\t\t"<<avgAmtSnow;
				cout<<"\n=============================================================================";
		}


	}while(choice!=4);
	cout<<"Thank You !!\n\n";
}

/*
**OUTPUT**
student@student-OptiPlex-330:~/Programs$ g++ Ass1-Weather.cpp
student@student-OptiPlex-330:~/Programs$ ./a.out

* WELCOME TO THE WEATHER REPORT *

MENU
1.Set Report
2.Generate Report
3.Generate Average Report
4.Exit

Enter Choice :1

=============================================================================
Enter Weather Report 1
Enter Day of Month :1

Enter High Temperature :50

Enter Low Temperature:20

Enter Amount of Rain :30

Enter Amount of Snow :50

=============================================================================

=============================================================================
Enter Weather Report 2
Enter Day of Month :2

Enter High Temperature :60

Enter Low Temperature:40

Enter Amount of Rain :60

Enter Amount of Snow :0

=============================================================================

=============================================================================
Enter Weather Report 3
Enter Day of Month :3

Enter High Temperature :40

Enter Low Temperature:10

Enter Amount of Rain :90

Enter Amount of Snow :0

=============================================================================

* WELCOME TO THE WEATHER REPORT *

MENU
1.Set Report
2.Generate Report
3.Generate Average Report
4.Exit

Enter Choice :2

=============================================================================
DAY     HIGH TEMP       LOW TEMP        AMT.RAIN        AMT.SNOW
=============================================================================
1       50              20              30              50
-----------------------------------------------------------------------------
2       60              40              60              0
-----------------------------------------------------------------------------
3       40              10              90              0
-----------------------------------------------------------------------------

=============================================================================

* WELCOME TO THE WEATHER REPORT *

MENU
1.Set Report
2.Generate Report
3.Generate Average Report
4.Exit

Enter Choice :3

=============================================================================
**AVERAGE REPORT**
=============================================================================
HIGH TEMP       LOW TEMP        AMT.RAIN        AMT.SNOW
=============================================================================
50              23.3333         60              16.6667
=============================================================================
* WELCOME TO THE WEATHER REPORT *

MENU
1.Set Report
2.Generate Report
3.Generate Average Report
4.Exit

Enter Choice :4
Thank You !!


*/
