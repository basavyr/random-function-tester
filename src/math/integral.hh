#ifndef INTEGRAL_HH
#define INTEGRAL_HH

#include <iostream>

namespace math
{
    class Integral
    {
    private:
        double intx;
        static constexpr double h = 0.001;

    public:
        Integral(double (*)(double), double, double);
        ~Integral();

    public:
        template <typename T>
        static T Int_f(T (*function)(T), T left, T right)
        {
            T sum = 0;
            auto ht = static_cast<T>(h);
            for (auto dx = left; dx <= right; dx += ht)
            {
                sum += static_cast<T>((function(dx + ht) + function(dx)) / 2.0) * ht;
            }
            return static_cast<T>(sum);
        }
    };
} // namespace math

#endif // INTEGRAL_HH