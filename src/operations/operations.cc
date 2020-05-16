#include "operations.hh"

std::random_device op_rd;
static std::mt19937 op_twister{op_rd()};
static constexpr double REAL_LIMIT = static_cast<double>(6969);

operations::Operations::Operations(size_t n_ops)
{
    start = std::chrono::high_resolution_clock::now();

    double unique_x;
    double pair_x, pair_y;
    double triplet_x, triplet_y, triplet_z;
    int arr_size = 10000;
    std::vector<double> arr1;
    std::vector<double> arr2;
    unique_x = RandomReal(REAL_LIMIT);
    pair_x = RandomReal(REAL_LIMIT);
    pair_y = RandomReal(REAL_LIMIT);
    triplet_x = RandomReal(REAL_LIMIT);
    triplet_y = RandomReal(REAL_LIMIT);
    triplet_z = RandomReal(REAL_LIMIT);
    arr1 = RandomRealArrays(arr_size);
    arr2 = RandomRealArrays(arr_size);
    // auto addpair=Add_Pair(pair_x,pair_y);
}

operations::Operations::~Operations()
{
    stopTimer();
}

void operations::Operations::stopTimer()
{
    auto stop = std::chrono::high_resolution_clock::now();
    auto startime = std::chrono::time_point_cast<std::chrono::microseconds>(start).time_since_epoch().count();
    auto stoptime = std::chrono::time_point_cast<std::chrono::microseconds>(stop).time_since_epoch().count();
    // return static_cast<double>(stoptime - startime);
    std::cout << "Operation class took: " << static_cast<double>(duration * 0.001) << " ms"
              << "\n";
}

std::vector<double> operations::Operations::RandomRealArrays(size_t arr_size)
{
    auto max_num = RandomReal(REAL_LIMIT);
    std::vector<double> results;
    for (auto id = 0; id < arr_size; ++id)
    {
        results.emplace_back(RandomReal(max_num));
    }
    return results;
}

double operations::Operations::RandomReal(double l)
{
    std::uniform_real_distribution<double> r_dist(0.0, l);
    auto rnum = r_dist(op_twister);
    return rnum;
}

int operations::Operations::RandomInt(int l)
{
    std::uniform_int_distribution<int> dist(0, l);
    auto i_num = dist(op_twister);
    return i_num;
}

void operations::Operations::showResult(double &result)
{
    std::cout << result;
    std::cout << "\n";
}