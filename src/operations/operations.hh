#ifndef OPERATIONS_HH
#define OPERATIONS_HH

#include <vector>
#include <random>
#include "sqrt.hh"
#include "trig.hh"
#include "add.hh"

namespace operations
{
    class Operations
    {
    private:
        double result;
        double trig_picker;

    public:
        static double RandomReal(double);
        static int RandomInt(int);
        static std::vector<double> RandomRealArrays(size_t);

    public:
        Operations(size_t);
        ~Operations();

    public:
        static void showResult(double &);
        static double Add_Pair(double, double);
        static double Add_Triplet(double, double, double);
        static double Add_Arrays(std::vector<double> &, std::vector<double> &);
        static double Sqrt_Number(double);
        static double Sqrt_Pair(double, double);
        static double Sqrt_Array(std::vector<double> &);
        static double Trig_Number(double);
        static double Trig_Array(std::vector<double> &);
    };
} // namespace operations

#endif // OPERATIONS_HH