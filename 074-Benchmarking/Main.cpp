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
        m_StartTimepoint = std::chrono::high_resolution_clock::now();
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
