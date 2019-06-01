#include <iostream>
#include <string>

template<typename T, int N>
class Array
{
private:
    T m_Array[N];
public:
    int GetSize() const { return N; }
};

int main()
{
    Array<int, 5> arrayInt;
    std::cout << arrayInt.GetSize() << std::endl;

    Array<std::string, 2> arrayString;
    std::cout << arrayString.GetSize() << std::endl;

    std::cin.get();
}
