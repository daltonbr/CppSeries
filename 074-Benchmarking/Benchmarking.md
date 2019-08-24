# Benchmarking

[RAII - Resource acquisition is initialization](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization

Resource acquisition is initialization (RAII)[1] is a programming idiom[2] used in several object-oriented languages to describe a particular language behavior. In RAII, holding a resource is a class invariant, and is tied to object lifetime: resource allocation (or acquisition) is done during object creation (specifically initialization), by the constructor, while resource deallocation (release) is done during object destruction (specifically finalization), by the destructor. In other words, resource acquisition must succeed for initialization to succeed. Thus the resource is guaranteed to be held between when initialization finishes and finalization starts (holding the resources is a class invariant), and to be held only when the object is alive. Thus if there are no object leaks, there are no resource leaks.

```cpp
#include <iostream>
#include <memory>
#include <chrono>

// RAII - Resource acquisition is initialization
class Timer
{
public:
    Timer()
    {
        std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << "us (" << ms << "ms)\n";
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};

int main()
{
    int value = 0;
    {
        Timer timer;

        for (int i = 0; i < 1000000; i++)
        {
            value += 2;
        }
    }

    std::cout << value << std::endl;

    //__debugbreak();
    return 0;

}
```

Using MSVC compiler we see an interesting effect when compiling with DEBUG or RELEASE settings.
In Release settings, the compiler is smart enough to optimize this trivial loop and set the final loop value all at once, and because of that there is no much work to be done at Run-Time, which is nice. The lesson here is to confirm if the work that we want to benchmark is really what we expect, and for that we can inspect the generated Assembly code.

Always remember to benchmark your code in RELEASE mode, because the extra overhead is generally high, and we aren't shipping code in DEBUG mode.

## Benchmarking pointers

```cpp
#include <iostream>
#include <memory>
#include <chrono>
#include <array>

// RAII - Resource acquisition is initialization
class Timer
{
public:
    Timer()
    {
        std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << "us (" << ms << "ms)\n";
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};

int main2()
{
    struct Vector2
    {
        float x, y;
    };

    std::cout << "Make Shared" << std::endl;
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer;
        for (size_t i = 0; i < sharedPtrs.size(); i++)
        {
            sharedPtrs[i] = std::make_shared<Vector2>();
        }
    }

    std::cout << "New Shared" << std::endl;
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer;
        for (size_t i = 0; i < sharedPtrs.size(); i++)
        {
            sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
        }
    }

    std::cout << "Make Unique" << std::endl;
    {
        std::array<std::unique_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer;
        for (size_t i = 0; i < sharedPtrs.size(); i++)
        {
            sharedPtrs[i] = std::make_unique<Vector2>();
        }
    }

    //__debugbreak();
    return 0;

}
```
