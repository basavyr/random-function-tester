#include "operations.hh"

std::random_device op_rd;
static std::mt19937 op_twister{op_rd()};

static constexpr double REAL_LIMIT = static_cast<double>(6969);
static constexpr size_t arr_size = 10000;
static const double pi = 3.141592654;

void operations::Operations::printArray(std::vector<double> &v)
{
    for (auto &&n : v)
        std::cout << n << " ";
    std::cout << "\n";
}

operations::Operations::Operations(size_t n_ops)
{
    start = std::chrono::high_resolution_clock::now();

    //vars
    double unique_x;
    double pair_x, pair_y;
    double triplet_x, triplet_y, triplet_z;
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

    //ops
    //add
    auto addpair = Add_Pair(pair_x, pair_y);
    auto addtriplet = Add_Triplet(triplet_x, triplet_y, triplet_z);
    auto addarr = Add_Arrays(arr1, arr2);
    //sqrt
    auto sqrtnumber = Sqrt_Number(unique_x);
    auto sqrtpair = Sqrt_Pair(pair_x, pair_y);
    auto sqrtarr = Sqrt_Array(arr1);
    //trig
    auto trignumber = Trig_Number(unique_x);
    auto trigarr = Trig_Array(arr1);
    // printArray(addarr);
    // printArray(sqrtarr);
    // printArray(trigarr);
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
    auto duration_ms = static_cast<double>(stoptime - startime) * 0.001;
    // std::cout << "Operation class took: " << duration_ms << " ms"<< "\n";
}

std::vector<double> operations::Operations::RandomRealArrays(size_t arr_size)
{
    std::vector<double> results;
    for (auto id = 0; id < arr_size; ++id)
    {
        results.emplace_back(RandomReal(pi));
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

double operations::Operations::Add_Pair(double x, double y)
{
    auto adder = Add::pair(x, y);
    return static_cast<double>(adder);
}

double operations::Operations::Add_Triplet(double x, double y, double z)
{
    auto adder = Add::triplet(x, y, z);
    return static_cast<double>(adder);
}

std::vector<double> operations::Operations::Add_Arrays(std::vector<double> &v1, std::vector<double> &v2)
{
    std::vector<double> results = Add::arrays(v1, v2);
    return results;
}

double operations::Operations::Sqrt_Number(double x)
{
    auto sq_res = Sqrt::number(x);
    return static_cast<double>(sq_res);
}

double operations::Operations::Sqrt_Pair(double x, double y)
{
    auto sq_res = Sqrt::pair(x, y);
    return static_cast<double>(sq_res);
}

std::vector<double> operations::Operations::Sqrt_Array(std::vector<double> &v)
{
    std::vector<double> results = Sqrt::array(v);
    return results;
}

double operations::Operations::Trig_Number(double x)
{
    auto trig_fct = Trig::generateRandomTrigFunction();
    auto tr_res = Trig::computeTrigFunction(trig_fct, x);
    return static_cast<double>(tr_res);
}

std::vector<double> operations::Operations::Trig_Array(std::vector<double> &v)
{
    auto trig_fct = Trig::generateRandomTrigFunction();
    auto results = Trig::computeTrigArray(trig_fct, v);
    return results;
}

void operations::Operations::showResult(double &result)
{
    std::cout << result;
    std::cout << "\n";
}