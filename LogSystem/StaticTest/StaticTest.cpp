// StaticTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

extern int s_Variable;

void Function()
{
	
}

int main()
{
	std::cout << s_Variable << std::endl;
	std::cin.get();
}