#include "math.hh"

math::Math::Math()
{
    start_time = std::chrono::high_resolution_clock::now();
}

math::Math::~Math()
{
    Timer();
}

void math::Math::Timer()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> stop_time = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_time).time_since_epoch().count();
    auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(stop_time).time_since_epoch().count();
    auto duration_ms = static_cast<double>((stop - start) * 0.001);
    std::cout << "Math instance ended after " << duration_ms << " ms"
              << "\n";
}