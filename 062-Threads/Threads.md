# Threads in C++

```cpp
#include <iostream>
#include <thread>
#include <chrono>

static bool = s_Finished = false;

void DoWork()
{
    while (!s_Finished)
    {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);
    }

}

int main()
{
    std::thread worker(DoWork);
    std::cin.get();
    s_Finished = true;

    worker.join();

    std::cin.get();
}

```
