#ifndef DERIVATIVE_HH
#define DERIVATIVE_HH

#include <iostream>
#include <random>
namespace math
{
    class Derivative
    {
    private:
        static constexpr double h = 0.0001;

    public:
        Derivative(double (*function)(double));
        ~Derivative();

    public:
        struct DataSet
        {
            double x;
            double y;
            DataSet()
            {
                x = 0.0;
                y = 0.0;
            }
        };

    public:
        static double Differentiate_Real(double (*)(double), double);

        static std::vector<double> Differentiate_Array(std::vector<DataSet> &vdiff);

        static std::vector<DataSet> generateFunctionArray(double (*)(double));

        template <typename T>
        static T Differentiate(T (*function)(T arg), T arg)
        {
            auto dx = static_cast<T>((function(arg + h) - function(arg)) / h);
            return dx;
        }
    };

} // namespace math

#endif // DERIVATIVE_HH