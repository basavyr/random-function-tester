#include "operations.hh"

std::random_device op_rd;
static std::mt19937 op_twister{op_rd()};

operations::Operations::Operations(size_t n_ops)
{
    double unique_x;
    double pair_x, pair_y;
    double triplet_x, triplet_y, triplet_z;
    int arr_size = 10000;
    auto arr1 = RandomRealArrays(arr_size);
    auto arr2 = RandomRealArrays(arr_size);
}

std::vector<double> operations::Operations::RandomRealArrays(size_t arr_size)
{
    auto max_num = RandomReal(RandomReal(RandomReal(6969)));
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