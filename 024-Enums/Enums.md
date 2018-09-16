# Enums

[Video #024](https://www.youtube.com/watch?v=x55jfOd5PEE&index=24&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

Enums is a short for Enumerations.

It help us define a set of Integer values, and avoid that someone messes with our values.

It make your code more readable and cleaner.

Enums defaults to 32 bit integer
You can specify what types of Integer you want for your Enums
i.e
`enum Example : unsigned char`
`enum Example : char`
`enum Example : float   // invalid`

```cpp
enum Example : unsigned char
{
    A, B, C     // they are setted to 0, 1, 2...
    // or we can set the values
    // A = 1, B = 2, C = 4
    // A = 5, B, C 
};

int main()
{
    Example value = 5; // gives us an error

    if (value == 1)
    {
        // Do something
    }
    std::cin.get();    
}
```