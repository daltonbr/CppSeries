#include <iostream>
#include <tuple>
#include <string>

std::tuple<std::string, int> TupleTest(std::string inputString, int inputInt)
{
    //return {inputString, inputInt};  // Error until C++17
    return std::make_tuple(inputString, inputInt);
}

int main()
{
    auto tuple = TupleTest("abcde", 42);

    std::cout << "string: " << std::get<0>(tuple) << std::endl;
    std::cout << "int: "    << std::get<1>(tuple) << std::endl;
    
    return 0;
}

/* -- Output

string: abcde
int: 42

*/