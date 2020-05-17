#include "math.hh"

std::random_device math_rd;
static std::mt19937 math_rng{math_rd()};

std::chrono::seconds generate_sleep_time(int secs)
{
    std::uniform_int_distribution<int> int_dist(0, secs);
    auto rand_int = int_dist(math_rng);
    auto int_to_sec = std::chrono::duration<int>(rand_int);
    return int_to_sec;
}

math::Math::Math()
{
    start_time = std::chrono::high_resolution_clock::now();
}

math::Math::~Math()
{
    //sleep this thread randomly
    auto sleep_time = std::chrono::seconds(generate_sleep_time(3).count());
    std::this_thread::sleep_for(sleep_time);

    // auto id_of_thread = std::this_thread::get_id();
    // std::cout << (id_of_thread) << "\n";
    //shows the time measurement for the life-time of the class instance
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