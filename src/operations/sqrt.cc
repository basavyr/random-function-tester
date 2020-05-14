#include "sqrt.hh"

operations::Sqrt::Sqrt(double x)
{
    result = number(x);
}

operations::Sqrt::~Sqrt()
{
    showResult(result);
}

double operations::Sqrt::number(double x)
{
    auto sq = static_cast<double>(sqrt(x));
    return sq;
}

double operations::Sqrt::pair(double x, double y)
{
    auto sq1 = static_cast<double>(sqrt(x));
    auto sq2 = static_cast<double>(sqrt(y));
    //returns the smallest sqrt of the pair
    return (sq1 < sq2) ? sq1 : sq2;
}

std::vector<double> operations::Sqrt::array(std::vector<double> &v)
{
    std::vector<double> sqrts;
    std::vector<double> nullv = {};
    if (std::any_of(v.begin(), v.end(), [](double element) {
            return element < 0;
        }))
        return nullv;
    for (auto id = 0; id < v.size(); ++id)
    {
        sqrts.emplace_back(number(v.at(id)));
    }
    return sqrts;
}

void operations::Sqrt::showResult(double &result)
{
    std::cout << "The square root of the number " << result << " is"
              << "\n";
    std::cout << "s.r.= " << result << "\n";
}