#ifndef DERIVATIVE_HH
#define DERIVATIVE_HH

#include <iostream>
namespace math
{
    class Derivative
    {
    private:
        static constexpr double h = 0.0001;

    public:
        Derivative();
        ~Derivative();

    public:
        static double Differentiate_Real(double (*)(double), double);

        template <typename T>
        static T Differentiate(T (*function)(T arg), T arg)
        {
            auto dx = static_cast<T>((function(arg + h) - function(arg)) / h);
            return dx;
        }
    };

} // namespace math

#endif // DERIVATIVE_HH