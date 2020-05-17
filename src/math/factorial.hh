#ifndef FACTORIAL_HH
#define FACTORIAL_HH

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
        static constexpr double pi = 3.14159265358979;
        static constexpr double ee = 2.71828182845905;

    public:
        Factorial(int);
        ~Factorial();

    public:
        struct Results
        {
            uint64_t fact_;
            double strirling;
            uint8_t arg_copy;
        };

    private:
        Results fact_res;

    public:
        static int fact_function(int arg);
        static double fact_stirling(int arg);
    }; // namespace math
} // namespace math

#endif // FACTORIAL_HH