#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>

class ScopedTimer
{
public:
    ScopedTimer()
    {
        m_start = std::chrono::high_resolution_clock::now();
    }
    ScopedTimer(std::string target)
    {
        m_target = target;
        m_start = std::chrono::high_resolution_clock::now();
    }
    ~ScopedTimer()
    {
        m_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = m_end - m_start;
        std::cout << "[ScopedTimer] " << m_target << " latency : " << std::fixed << std::setprecision(4) << elapsed.count() << "ms" << std::endl;
    }
private:
    std::string m_target = "";
    std::chrono::high_resolution_clock::time_point m_start;
    std::chrono::high_resolution_clock::time_point m_end;
};