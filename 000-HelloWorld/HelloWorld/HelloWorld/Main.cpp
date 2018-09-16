#include <iostream>

void Log(const char* message);

int main()
{
	Log("Hello Wolrd!");
	int var = 8;
	void* ptr = &var;
	std::cin.get();	
}