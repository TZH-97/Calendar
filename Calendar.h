// Calendar.h

#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar

{

	private: 
		int month;
		int year;
		int firstDay;

	public:
		void getMonthAndYear();
		void setFirstDay();
		void print();

};

#endif