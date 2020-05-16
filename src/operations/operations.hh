#ifndef OPERATIONS_HH
#define OPERATIONS_HH

#include <vector>
#include <random>
#include "sqrt.hh"
#include "trig.hh"
#include "add.hh"
#include <ctime>
#include <chrono>
namespace operations
{
    class Operations
    {
    private:
        double result;
        double trig_picker;
        std::chrono::time_point<std::chrono::high_resolution_clock> start;

    public:
        static double
        RandomReal(double);
        static int RandomInt(int);
        static std::vector<double> RandomRealArrays(size_t);
        void stopTimer();
        static void printArray(std::vector<double> &);

    public:
        Operations(size_t);
        ~Operations();

    public:
        static void showResult(double &);

        //add ops
        static double Add_Pair(double, double);
        static double Add_Triplet(double, double, double);
        static std::vector<double> Add_Arrays(std::vector<double> &, std::vector<double> &);

        //sqrt ops
        static double Sqrt_Number(double);
        static double Sqrt_Pair(double, double);
        static std::vector<double> Sqrt_Array(std::vector<double> &);

        //trig ops
        static double Trig_Number(double);
        static std::vector<double> Trig_Array(std::vector<double> &);
    };
} // namespace operations

#endif // OPERATIONS_HH