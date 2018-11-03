# Copying and Copy Constructors

[Video](https://www.youtube.com/watch?v=BvR1Pgzzr38&index=46&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&t=1s)

It's good to avoid copying when it's possible because it waste performance.

```cpp
int main()
{
    int a = 3;
    int b = a;

    // Here we have two different variables in memory
}
```


```cpp
int main()
{
    Vector2 a = { 2, 3 };
    Vector2 b = a;

    b.x = 5;

    // Here we also have two different memory addresses

    Vector2* c = new Vector2();
    Vector2* d = c;

    c->x = 5;

    // Here we are working with one memory address

    std::cin.get();
}
```
A basic **shallow copy constructor** is supplied for us by default.

```cpp
    /* Copy Constructor
     * This is supplied for us by default 
     * This is a shallow copy
     */
    String(const String& other)
        : m_Buffer(other.m_Buffer), m_Size(other.m_Size)
    {
        // or we could write like that
        //memcpy(this, &other, sizeof(String));
    }
```

A **deep copy** copies the entire object, it copy the content of the pointers.

A **copy constructor** is a constructor that is called when you copy the object.


If we don't want a copy constructor, we can make something like this:

```cpp
String(const String& other) = delete;
```

```cpp
#include <string>
#include <iostream> // std::cout
#include <memory>

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(this->m_Buffer, string, this->m_Size);
        m_Buffer[m_Size] = 0;
    }

    /* Copy Constructor
     * A deep copy */
    String(const String& other)
        : m_Size(other.m_Size)
    {
        std::cout << "Copied String" << std::endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }


    friend std::ostream& operator<<(std::ostream& stream, const String& string);

};

// passing parameters using 'const' and by reference is a good practice here
// it avoid unnecessary copies
void PrintString(const String& string)
{
    std::cout << string << std::endl;	
}

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main()
{
    String string = "Cherno";
    String second = string;

    second[2] = 'a';

    PrintString(string);
    PrintString(second);
    
    std::cin.get();
}
```