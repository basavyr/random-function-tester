#include "derivative.hh"

std::random_device rd;
static std::mt19937 twister{rd()};

static constexpr double max_right = 180;

double Random_Real()
{
    std::uniform_real_distribution<double> r_dist(0, max_right);
    auto r_num = static_cast<double>(r_dist(twister));
    return r_num;
}

math::Derivative::Derivative(double (*function)(double arg))
{
    std::cout << "Class instance started"
              << "\n";
    std::cout << Differentiate<double>(function, Random_Real());
}

math::Derivative::~Derivative()
{
    std::cout << "Derivative calculation finished"
              << "\n";
}

std::vector<math::Derivative::DataSet> math::Derivative::generateFunctionArray(double (*function)(double arg))
{
    std::vector<DataSet> dataset;
    //generate the size of the dataset
    //size of the data set is in the interval 0,max_right
    // size_t SIZE = static_cast<int>(Random_Real());
    size_t SIZE = 10;
    int index = 0;
    for (auto id = 0; id < SIZE; ++id)
    {
        dataset.emplace_back(DataSet());
        dataset.at(index).x = id;
        dataset.at(index).y = function(id);
        ++index;
    }
    return dataset;
}

std::vector<double> math::Derivative::Differentiate_Array(std::vector<math::Derivative::DataSet> &vdiff)
{
    std::vector<double> derivatives;
    for (auto id = 0; id < vdiff.size() - 1; ++id)
    {
        auto dx = vdiff.at(id + 1).x - vdiff.at(id).x;
        auto dfx = vdiff.at(id + 1).y - vdiff.at(id).y;
        derivatives.emplace_back(static_cast<double>(dfx / dx));
    }
    return derivatives;
}

double math::Derivative::Differentiate_Real(double (*function)(double), double arg)
{
    auto dx = static_cast<double>((function(arg + h) + function(arg)) / h);
    return dx;
}