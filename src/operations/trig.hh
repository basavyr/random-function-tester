#ifndef TRIG_HH
#define TRIG_HH

#include <iostream>
#include <random>
#include <cassert>
#include <limits>
#include <cmath>
#include <vector>
#include <cstring>
namespace operations
{

    class Trig
    {
    private:
        double result;
        double arg_copy;

    public:
        enum Functions
        {
            SIN,
            COS,
            TAN,
            CTAN,
            ASIN,
            ACOS,
            ATAN,
            ARCTAN,
            MAXENUM //safety mechanism for keeping track of the number of trigonometric implementations
            //just a trick!
        };

    private:
        static Functions trigfunction;
        Functions chosen_function;

    public:
        Trig(double);
        ~Trig();

    public:
        static double computeTrigFunction(Functions, double);
        static std::vector<double> computeTrigArray(std::vector<double> &);
        static void showResult(Functions &, double &, double &);
        static std::string functionName(Functions &);
        Functions generateRandomTrigFunction();
    };

} //namespace operations

#endif // TRIG_HH