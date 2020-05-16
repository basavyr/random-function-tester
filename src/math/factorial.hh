#ifndef GAMMA_HH
#define GAMMA_HH

#include <cmath>
#include <vector>
namespace math
{
    class Gamma
    {
    private:
        double result;

    public:
        Gamma();
        ~Gamma();

    public:
        template <typename T>
        static T fgamma(T arg);
        {
            if (isnan(arg))
                return static_cast<T>(0);
            auto fg = gamma(arg);
            return static_cast<T>(fg);
        }
        static double gamma_real(std::vector<double> &vargs)
    };
} // namespace math

#endif // GAMMA_HH