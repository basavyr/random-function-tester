#include "factorial.hh"


math::Factorial::Factorial(double arg)
{
    fact = fact_function(arg);
}

math::Factorial::~Factorial()
{
    std::cout << "The Factorial function finished succsessfully"
              << "\n";
}

int math::Factorial::fact_function(int arg)
{
    double fx;
    (arg > 0) &&fx = math::Gamma::fgamma<int>(arg - 1);

    auto x=math::Gamma::Gamma(1);
}