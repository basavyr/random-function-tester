#ifndef GAMMA_HH
#define GAMMA_HH

#include <vector>
#include <cmath>
#include <iostream>
namespace math
{
    class Gamma
    {
    private:
        double fgresult;

    public:
        Gamma(double);
        ~Gamma();

    public:
        static std::vector<double> array(std::vector<double> &vargs);

        template <typename T>
        static T fgamma(T arg)
        {
            if (isnan(arg))
                return static_cast<T>(0);
            auto fg = gamma(arg);
            return static_cast<T>(fg);
        }
        };
} // namespace math

#endif // GAMMA_HH