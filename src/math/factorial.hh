#ifndef GAMMA_HH
#define GAMMA_HH

#include <cmath>
#include <vector>
#include <iostream>

#include "gamma.hh"
namespace math
{
    class Factorial
    {
    private:
        double fact;

    public:
        Factorial(double);
        ~Factorial();

    public:
        static int fact_function(int arg);
        static double fact_stirling(int arg);
    };
} // namespace math

#endif // GAMMA_HH