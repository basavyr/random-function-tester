#include "operations.hh"

std::random_device op_rd;
static std::mt19937 op_twister{op_rd()};
static constexpr double REAL_LIMIT = static_cast<double>(6969);

operations::Operations::Operations(size_t n_ops)
{
    double unique_x;
    double pair_x, pair_y;
    double triplet_x, triplet_y, triplet_z;
    int arr_size = 10000;
    std::vector<double> arr1;
    std::vector<double> arr2;
    //add
    for (auto op = 0; op < n_ops; ++op)
    {
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
}

operations::Operations::~Operations()
{
    std::cout << "ok";
    std::cout << "\n";
}

std::vector<double> operations::Operations::RandomRealArrays(size_t arr_size)
{
    auto max_num = RandomReal(RandomReal(RandomReal(REAL_LIMIT)));
    std::vector<double> results;
    for (auto id = 0; id < arr_size; ++id)
    {
        results.emplace_back(RandomReal(RandomReal(RandomReal(max_num))));
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