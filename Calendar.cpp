// Calendar.cpp

#include "Calendar.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Calendar::getMonthAndYear()

{
	cout << "What month and year would you like to view its dates? \n";
	cout << "Enter 1 for January, 2 for February, etc. \n";
	cout << "and the year separated by a space. ";
	cin >> month >> year;
}

// This part determines which day will be the first day of that year (0 for Sunday, 1 for Monday, etc.)

void Calendar::setFirstDay()

{

	int day = 1;
	int y = year - (14-month) / 12;
	int m = month + 12 * ((14-month)/12) - 2;

	firstDay = (day + y + y + y/4 + y/100 + y/400 + (31 * m/12)) % 7; 
}

// DISPLAY ONLY 

void Calendar::print()

{

	int NumberOfDaysInMonth;
	int FirstDayOfMonth = 0;
	int DayOfWeekCounter = 1;
	int DateCounter = 1;

	switch(month)

	{
		case 1:
		cout << setw(14) << "January " << year;
		NumberOfDaysInMonth = 31;
		break;

		case 2:
		cout << setw(14) << "February " << year;
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			NumberOfDaysInMonth = 29;
		else 
			NumberOfDaysInMonth = 28;
		break;

		case 3:
		cout << setw(14) << "March " << year;
		NumberOfDaysInMonth = 31;
		break;

		case 4:
		cout << setw(14) << "April " << year;
		NumberOfDaysInMonth = 30;
		break;

		case 5:
		cout << setw(14) << "May " << year;
		NumberOfDaysInMonth = 31;
		break;

		case 6:
		cout << setw(14) << "June " << year;
		NumberOfDaysInMonth = 30;
		break;
		
		case 7:
		cout << setw(14) << "July " << year;
		NumberOfDaysInMonth = 31;
		break;

		case 8:
		cout << setw(14) << "August " << year;
		NumberOfDaysInMonth = 31;
		break;

		case 9: 
		cout << setw(14) << "September " << year;
		NumberOfDaysInMonth = 31;
		break;

		case 10:
		cout << setw(14) << "October " << year;
		NumberOfDaysInMonth = 31;
		break;

		case 11:
		cout << setw(14) << "November " << year;
		NumberOfDaysInMonth = 31;
		break;

		case 12:
		cout << setw(14) << "December " << year;
		NumberOfDaysInMonth = 31;
		break;
	}

// Display the days at the top of each month 

	cout << "\n S  M  T  W  T  F  S \n\n";
	cout << setw(2);

// Determine where the first day begins

	for (FirstDayOfMonth; FirstDayOfMonth < firstDay; ++FirstDayOfMonth)
	{
		cout << setw(11);
	}
	
	int tempFirstDay = firstDay;
	DateCounter = 1;
	DayOfWeekCounter = tempFirstDay;

// This loop represents the date display d will continue to run until 
// the number of days in that month have been reached.

	for (DateCounter; DateCounter <= NumberOfDaysInMonth; ++DateCounter)

	{
		cout << DateCounter << setw(3);
		++DayOfWeekCounter;

		if (DayOfWeekCounter > 6)
		{
			cout << "\n\n" << setw(2);
			DayOfWeekCounter = 0;
		}
	}

	cout << " \n\n"; 

	tempFirstDay = DayOfWeekCounter + 1; 

}

// Print and run the class

int main()

{
	Calendar c;
	c.getMonthAndYear();
	c.setFirstDay();
	c.print();

	return 0; 
}



