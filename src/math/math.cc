#include "math.hh"

std::random_device math_rd;
static std::mt19937 math_rng{math_rd()};

static constexpr size_t ARR_SIZE = 100;
static constexpr double max_num = 150;

double generate_integer(int right)
{
    std::uniform_int_distribution<int> int_dist(0, right);
    auto int_num = int_dist(math_rng);
    return static_cast<int>(int_num);
}

double generate_real(double right)
{
    std::uniform_real_distribution<double> r_dist(0, right);
    auto real_num = r_dist(math_rng);
    return static_cast<double>(real_num);
}

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
    // auto sleep_time = std::chrono::seconds(generate_sleep_time(3).count());
    // std::this_thread::sleep_for(sleep_time);

    // auto id_of_thread = std::this_thread::get_id();
    // std::cout << (id_of_thread) << "\n";
    //shows the time measurement for the life-time of the class instance
    Timer();
}

//testing procedures

inline void show(const std::string &s)
{
    std::cout << s;
    std::cout << "\n";
}

double math::Math::special_math_function(double arg)
{
    return static_cast<double>(arg + sqrt(arg));
}

void math::Math::test_factorial()
{
    const std::string start_msg = "Starting the factorial implementation test procedure...";
    const std::string stop_msg = "Testing factorial implementation finished succsessfully...";
    std::vector<math::Factorial::Results> fact_res;
    show(start_msg);
    for (int id = 0; id < ARR_SIZE; ++id)
    {
        // auto r_int = static_cast<int>(math::Derivative::Random_Real());
        auto r_int = generate_integer(10);
        fact_res.emplace_back(math::Factorial::Results());
        fact_res.at(id).fact_ = math::Factorial::fact_function(r_int);
        fact_res.at(id).strirling = math::Factorial::fact_stirling(r_int);
        fact_res.at(id).arg_copy = r_int;
    }
    show(stop_msg);
}

void math::Math::test_gamma()
{
    const std::string start_msg = "Starting the gamma implementation test procedure...";
    const std::string stop_msg = "Testing gamma implementation finished succsessfully...";
    std::vector<double> gm_v;
    show(start_msg);
    for (auto id = 0; id < ARR_SIZE; ++id)
    {
        auto r_int = generate_real(10.0);
        auto gammax = math::Gamma::fgamma<double>(r_int);
        gm_v.emplace_back(gammax);
    }
    auto gm_arr = math::Gamma::array(gm_v);
    show(stop_msg);
}

void math::Math::test_derivative()
{
    const std::string start_msg = "Starting the derivative implementation test procedure...";
    const std::string stop_msg = "Testing derivative implementation finished succsessfully...";
    show(start_msg);
    for (auto id = 0; id < ARR_SIZE; ++id)
    {
        auto rnum = generate_real(max_num);
        auto data_set = math::Derivative::generateFunctionArray(special_math_function);
        auto derivs = math::Derivative::Differentiate_Array(data_set);
        auto dx = math::Derivative::Differentiate<double>(special_math_function, rnum);
    }
    show(stop_msg);
}

void math::Math::test_integration()
{
    const std::string start_msg = "Starting the integration implementation test procedure...";
    const std::string stop_msg = "Testing integration implementation finished succsessfully...";
    show(start_msg);
    math::Integral::Int_f<double>(special_math_function, 0.0, 100.0);
    show(stop_msg);
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