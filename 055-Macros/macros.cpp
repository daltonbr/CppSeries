#include <iostream>
#include <string>

// We can define PR_DEBUG as a PREPROCESSOR in our IDE 

#ifdef PR_DEBUG
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif

int main()
{
    LOG("Hello");
    std::cin.get();
}