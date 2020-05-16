#include "derivative.hh"

math::Derivative::Derivative()
{
    std::cout << "Class instance started"
              << "\n";
}

math::Derivative::~Derivative()
{
    std::cout << "Derivative calculation finished"
              << "\n";
}

double math::Derivative::Differentiate_Real(double (*function)(double), double arg)
{
    auto dx = static_cast<double>((function(arg + h) + function(arg)) / h);
    return dx;
}