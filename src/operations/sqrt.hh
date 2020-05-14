#ifndef SQRT_HH
#define SQRT_HH

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

namespace operations
{
    class Sqrt
    {
    private:
        double result;

    public:
        Sqrt(double);
        ~Sqrt();

    public:
        static double number(double);
        static double pair(double, double);
        static std::vector<double> array(std::vector<double> &);
        static void showResult(double &);
    };
} //namespace operations

#endif // SQRT_HH