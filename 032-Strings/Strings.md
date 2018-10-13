# How Strings work in C++

[Video](https://www.youtube.com/watch?v=ijIxcB9qjaU&t=0s&index=33&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

Char 1 byte of memory (let's forget about +1) UTF-8, let's not consider here UTF-16 (2^16 possibilities)
Let's forget about encoding to simplify things

For C++ we are assume: 1 char occupies 1 byte
Strings are a string of chars, duh =)

String are immutable, you can change and make it bigger.
Strings finish with a '\0'

[`std::basic_string`](https://en.cppreference.com/w/cpp/string/basic_string)

`std::string` is basically `std::basic_string<char>`

Other templates
Type | Definition
--- | ---
`std::string` | `std::basic_string<char>`
`std::wstring` | `std::basic_string<wchar_t>`
`std::u16string` (C++11) | `std::basic_string<char16_t>`
`std::u32string` (C++11) | `std::basic_string<char32_t>`
`std::pmr::string` (C++17) | `std::pmr::basic_string<char>`
`std::pmr::wstring` (C++17) | `std::pmr::basic_string<wchar_t>`
`std::pmr::u16string` (C++17) | `std::pmr::basic_string<char16_t>`
`std::pmr::u32string` (C++17) | `std::pmr::basic_string<char32_t>`

```cpp
#include <iostream>
#include <string>

int main()
{
	// This is an "emulation" of strings in cpp
	// Const is used because strings are immutable
	//const char* name = "Cherno";

	std::string name = "Dalton"; // "Dalton" is a const char*
	std::cout << name << std::endl;

	//std::string hi = "Hello" + " world!";  // Error
	std::string hi = std::string("Hello") + " world!";  // Error
	//name.size();

	// Find a substring
	if (name.find("on") != std::string::npos)	// npos is a illegal position
	{
		std::cout << "find the substring";
	}

	std::cin.get();
}

// we are passing here a copy (value) not reference, it's slow
void PrintString(std::string string)
{
	string += "h";
	std::cout << string << std::endl;
}

// with 'const' if promise to not modify the input parameter and passing by reference (&) it's faster
void PrintString(const std::string& string)
{
	std::cout << string << std::endl;
}

```