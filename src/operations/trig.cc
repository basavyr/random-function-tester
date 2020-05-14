#include "trig.hh"

operations::Trig::Trig(double x)
{
    result = 1;
}

operations::Trig::~Trig()
{
    showResult(result);
}

void operations::Trig::showResult(double &result)
{
    std::cout << "The result of the trigonometric function:"
              << "\n";
    std::cout << "f(x) = " << result;
    std::cout << "\n";
}