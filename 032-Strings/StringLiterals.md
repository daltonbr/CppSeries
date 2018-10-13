# String Literals in C++

[Video](https://www.youtube.com/watch?v=FeHZHF0f2dw&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=33)

String literals like `"Cherno"` are store in a read-only section of memory. 

```cpp
const char* name = u8"Cherno"; //u8 is optional - 1 byte

// A wide char 'string' literal
const wchar_t* name2 = L"Dalton";  // 2 or 4 bytes per character (on Windows, 4 on Linux and maybe OSx) it's up to the compiler to decide this size, it can be even 1 byte

// guaranteed size, used for UTF-16 and UTF-32
const char16_t* name3 = u"Cherno"; // 2 bytes per character
const char32_t* name4 = U"Cherno"; // 4 bytes per character

```

```cpp
int main()
{
    using namespace std::string_literals;

        std::string name0 = "Cherno"s + " hello";
        std::u32string name1 = U"Cherno"s + U" hello";

        // ignore escape character
        const char* example = R"(Line1
            Line2  \0
    		Line3)";
}
```