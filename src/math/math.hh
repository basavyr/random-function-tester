#ifndef MATH_HH
#define MATH_HH

#include <chrono>

#include "integral.hh"
#include "factorial.hh"
#include "derivative.hh"
#include "gamma.hh"
#include <thread>
#include <random>

namespace math
{
    class Math
    {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time;

    public:
        Math();
        ~Math();

    public:
        void Timer();
        static double Number_Eval();
        template <typename T>
        static std::vector<T> Vector_Eval()
        {
            std::vector<T> f_evals;
            return f_evals;
        }
    };
} // namespace math

#endif // MATH_HH
