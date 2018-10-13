# Member Initializer Lists in C++

[Video](https://www.youtube.com/watch?v=1nfuYMXjZsA&index=36&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

It's a way to us to initialize our class members
It's usually made in the constuctor

Initialize the class member in the same order as they are declared, just to avoid any dependency problem

- It makes our constructor cleaner
- You should always use it, because it avoid duplication of instantiate member of the class. It is a waste of performance

```cpp
#include <string>
#include <iostream> // std::cout

class Entity
{
private:
	std::string m_Name;
	int m_Score;
public:
	// traditional constructor
	/*Entity()		
	{
		m_Name = "Unknown";
	}*/

	// using member initializer lists
	Entity()
		: m_Name("Unknown"), m_Score(0)
	{		
	}

	// old way - not efficient
	Entity(const std::string& name)
	{
		m_Name = name;
		m_Score = 0;
	}

	const std::string& GetName() const
	{
		return m_Name;
	}
};

int main()
{
	Entity e0;
	std::cout << e0.GetName() << std::endl;

	Entity e1("Cherno");
	std::cout << e1.GetName() << std::endl;
	
	std::cin.get();
}
```