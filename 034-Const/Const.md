# Const in C++

[Video](https://www.youtube.com/watch?v=4fJBrditnJU&index=34&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

`const` is a keyword in cpp that 'promises' to not change something. this thing will be 'constant' =)
You can break that promises too.

```cpp
#include <iostream>
#include <string>
#include <stdlib.h>  // some C functions

int main()
{
	const int MAX_AGE = 5;

	// the compiler will warn you if you try to change it
	//MAX_AGE = 90;


	// const int*
	const int* a = new int; 	//the same as int const* a = new int;
	//*a = 2; // Cannot do this, we cannot change the value, to where it is pointing
	a = &MAX_AGE;

	// int* const
	int* const b = new int;
	*b = 2;
	// Cannot do this, we cannot change the pointer itself
	//b = &MAX_AGE;

	// Cannot change anything
	const int* const c = new int(8);
	// *c = &MAX_AGE;
	// *c = 7;

	std::cout << *a << std::endl;
	std::cout << MAX_AGE << std::endl;
	std::cout << *b << std::endl;
	std::cout << *c << std::endl;
	std::cin.get();
}

// const in class
class Entity
{
private:
	int m_X, m_Y;
	int* ptr;
	int* a, b;	// b is int, not int*
	int* c, *d;
	mutable int var;
public:
	// this method will not modify any of this private values in class
	int GetX() const
	{
		// This lines gives us compiler errors
		//m_X = 3;
		//m_Y = 5;
		var = 2; // we CAN modify mutable variables in const methods
		return m_X;
	}

	// 1st const: Returning a pointer that can't be modified
	// 2nd const: The content of the pointer returned cannot be modified
	// 3rd const: this method promises to not modified the entity class
	const int* const GetPrt() const
	{
		return ptr;
	}

	// Not using const in Setters
	int SetX(int x)
	{
		m_X = x;
	}

	// passing by reference, can only use const methods
	void PrintEntity(const Entity& e)
	{		
		std::cout << e.GetX() << std::endl;
	}
};
```