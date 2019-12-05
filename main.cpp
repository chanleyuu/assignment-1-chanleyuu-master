/*
* main.cpp
*
* Version information
* Author: Conall Hanley
* Date: 17/10/2019
* Description: This file is the driver for the project, use it to test your code. 
*
* Copyright notice - 
*/  

//#pragma once 
#include <iostream>

#include "UUDate.h"

using namespace std;

int main() {
	   	
	//TODO - Add your test code here

	//Remember to test your code thoroughly before running it against the tests in github

    UUDate x(12, 10, 1999);
    UUDate u("32/16/0");
    cout << u.GetDate() << endl;
    cout << x.GetDate() << endl;
    cout << x.Between(u) << endl;
 //   x.IncrementDate();
    x.SetDay(55);
    cout << x.GetDate() << endl;
	return 0;
}
