/*
* UUDate.cpp
*
* Version information
* Author: Conall Hanley 
* Date: 17/10/2019 
* Description: This file is the implementation file for the UUDate class and defines (implements) the functions of the class
*
* Copyright notice -
*/


#include "UUDate.h"

UUDate::UUDate() {

	//Initialise the date to 01/01/2000
	SetDay(1);
	SetMonth(1);
	SetYear(2000); //I think January 1 1970 is a better date though
}

UUDate::UUDate(int day, int month, int year){
    
    if (month > 0 && month < 13) {
        month_ = month;
    }
    else {
        month_ = 1;
    }
    
    if (year > 0) { 
        year_ = year;
    }
    else {
        year_ = 2000;
    }
    
    if (isvalidday(day) == true) {
        day_ = day;
    }
    else {
        day_ = 1;
    }
}

UUDate::UUDate(std::string date) {
    int day;
    int month;
    int year;
    
	for (int i = 0; i < 3; i++) { // Loop three times for day, month, and year.
        int pos;
        if (i < 2) {
            pos = (int) date.find("/"); // Find the forward slash
        } 
        else {
            pos = (int) date.size(); //Becase by the end we have run out of forward slashes
        }
        std::string num = date.substr(0, pos); 
        date.erase(0, pos + 1);
        int intnum = atoi(num.c_str());
        switch (i) {
            case 0:
                day = intnum;
                break;
            case 1:
                month = intnum;
                break;
            case 2:
                year = intnum;
                break;
            default:
                pos = 50000;
                break;
        }
    }
    
    if (month > 0 && month < 13) {
        month_ = month;
    }
    else {
        month_ = 1;
    }
    
    if (year > 0) { 
        year_ = year;
    }
    else {
        year_ = 2000;
    }
    
    if (isvalidday(day) == true) {
        day_ = day;
    }
    else {
        day_ = 1;
    }
}

void UUDate::IncrementDate() {
	day_++;
	if ( isvalidday(day_) == false ) {
		day_ = 1;
		month_++;
	}
	else if (day_ > 31 && month_ == 12) {
		day_ = 1;
		month_ = 1;
		year_++;
	}
	//TODO - Add your implementation here
}

bool UUDate::isleapyear(int year) {
	if ( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 ) {
		return true;
	}
	return false;
}

int UUDate::getmonthdays(int month, int year) {
	int total = 0;
	switch (month) {
		case 1: total = 0;
            break;
		case 2: total = 31;
            break;
		case 3: total = 59;
            break;
		case 4: total = 90;
            break;
		case 5: total = 120;
            break;
		case 6: total = 151;
            break;
		case 7: total = 181;
            break;
		case 8: total = 212;
            break;
		case 9: total = 243;
            break;
		case 10: total = 273;
            break;
		case 11: total = 304;
            break;
		case 12: total = 334;
            break;
        default:
            total = 0;
            break;
	}
	if (isleapyear(year) && month > 2) {
		total++;
	}
	return total;
}

int UUDate::Between(UUDate date) {
	int days =   date.day_ - day_;
	int months = getmonthdays(date.GetMonth(), date.GetYear()) - getmonthdays(month_, year_);
	int years =  date.year_ - year_;
	int total = 0;
	

    total += years * 365;
    total += years / 4; //Addtional leap days will come from the getmonthdays function
        
    total += months;

    total += days;

	if (total < 0) { //If total is negetive, return a positive value
		total = total * -1;
	}
	return total;
	//TODO - Add your implementation here
}

bool UUDate::isvalidday ( int day ) {
    if ( ( day > 31 && (month_ == 1 || month_ == 3 ||
		month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10) )
		|| ( day > 30 && (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) )
		|| ( day > 29 && month_ == 2 && isleapyear(year_) == true )
		|| (day > 28 && month_ == 2 && isleapyear(year_) == false ) ) {
        return false;
    }

    return true;
}


int UUDate::GetDay() const {
	return day_;
}

void UUDate::SetDay(int day) {
	//TODO - Add your implementation here
    if (isvalidday(day) == true) { 
        day_ = day;
    }
}

int UUDate::GetMonth() const {
	//TODO - Add your implementation here
	return month_;
}

void UUDate::SetMonth(int month) {
	//TODO - Add your implementation here
    if (month > 0 && month < 13) {
        month_ = month;
    }
}

int UUDate::GetYear() const {
	//TODO - Add your implementation here
	return year_;
}

void UUDate::SetYear(int year) {
	//TODO - Add your implementation here
    if (year > 0) {
        year_ = year;
    }
}

std::string UUDate::GetDate() {
	//TODO - Add your implementation here
	return std::to_string(day_) + "/" + std::to_string(month_) + "/" + std::to_string(year_);
}
