/*
* UUDate.cpp
*
* Version information
* Author: TODO - Add your name here
* Date: TODO - Add date you started working on the code
* Description: This file is the implementation file for the UUDate class and defines (implements) the functions of the class
*
* Copyright notice -
*/


#include "UUDate.h"

UUDate::UUDate() {

	//Initialise the date to 01/01/2000
	//TODO - Add your implementation here
	SetDay(1);
	SetMonth(1);
	SetYear(2000);
}

UUDate::UUDate(int day, int month, int year){
	//TODO - Add your implementation here
	SetDay(day);
	SetMonth(month);
	SetYear(year);
}

UUDate::UUDate(std::string date) {
	//TODO - Add your implementation here
}

void UUDate::IncrementDate() {
	day_++;
	if (isleapyear()) {
		day_ = 1;
		month_++;
	}
	//TODO - Add your implementation here
}

bool UUDate::isleapyear() {
	if (day_ > 31 && (month_ == 1 || month_ == 3 ||
		month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)
		|| day_ > 30 && (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)
		|| day_ > 29 && month_ == 2 && year_ % 4 == 0 && year_ % 100 != 0
		|| day_ > 28 && month_ == 2 && (year_ % 4 != 0 || year_ % 4 == 0 && year_ % 100 == 0)) {
		return true;
	}
	return false;
}

int UUDate::getmonthdays(int month) {
	int total = 0;
	switch (month) {
		case 1: total = 0;
	
		case 2: total = 31;

		case 3: total = 59;

		case 4: total = 90;

		case 5: total = 120;

		case 6: total = 151;

		case 7: total = 181;

		case 8: total = 212;

		case 9: total = 243;

		case 10: total = 273;

		case 11: total = 304;

		case 12: total = 334;
	}
	if (isleapyear && month > 2) {
		total++;
	}
	return total;
}

int UUDate::Between(UUDate date) {
	int days =   date.day_ - GetDay();
	int months = getmonthdays(date.month_) - getmonthdays(GetMonth());
	int years =  date.year_ - GetYear();
	int total = 0;
	


	if (years > 0) {
		total += years * 365;
	}

	if (months > 0) {
		total += months;
	}

	if (days > 0) {
		total += days;
	}
	return total;
	//TODO - Add your implementation here
}

int UUDate::GetDay() const {
	return day_;
}

void UUDate::SetDay(int day) {
	//TODO - Add your implementation here
	day_ = day;
}

int UUDate::GetMonth() const {
	//TODO - Add your implementation here
	return month_;
}

void UUDate::SetMonth(int month) {
	//TODO - Add your implementation here
	month_ = month;
}

int UUDate::GetYear() const {
	//TODO - Add your implementation here
	return year_;
}

void UUDate::SetYear(int year) {
	//TODO - Add your implementation here
	year_ = year;
}

std::string UUDate::GetDate() {
	//TODO - Add your implementation here
	return std::to_string(day_) + "/" + std::to_string(month_) + "/" + std::to_string(year_);
}
