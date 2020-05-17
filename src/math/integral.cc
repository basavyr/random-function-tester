#include "integral.hh"

math::Integral::Integral(double (*function)(double arg), double left, double right)
{
    intx = Int_f<double>(function, left, right);
}

math::Integral::~Integral()
{
    std::cout << "The integration calculus finished succsessfully...";
    std::cout << "\n";
}