#include "add.hh"

operations::Add::Add(double a, double b)
{
    result = static_cast<double>(pair(a, b));
}

operations::Add::~Add()
{
    showResult(result);
}

double operations::Add::pair(double a, double b)
{
    auto s = static_cast<double>(a + b);
    return s;
}

double operations::Add::triplet(double a, double b, double c)
{
    auto st = static_cast<double>(a + b + c);
    return st;
}

std::vector<double> operations::Add::arrays(std::vector<double> &v1, std::vector<double> &v2)
{
    std::vector<double> nullv = {};
    if (v1.size() != v2.size())
        return nullv;
    //store the pair of sums
    std::vector<double> sums;
    for (auto id = 0; id < v1.size(); ++id)
    {
        auto s = pair(v1.at(id), v2.at(id));
        sums.emplace_back(s);
    }
    return sums;
}

void operations::Add::showResult(double &res)
{
    std::cout << "The result for the sum of the two numbers is:"
              << "\n";
    std::cout << "s= " << res;
    std::cout << "\n";
}