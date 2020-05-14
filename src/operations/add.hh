#ifndef ADD_HH
#define ADD_HH

#include <vector>
#include <iostream>

namespace operations
{

    class Add
    {
    private:
        double result;

    public:
        //default constructor will calculate the sum of two numbers;
        Add(double, double);
        ~Add();

    public:
        //calculates the sum two of user-predefined numbers
        static double pair(double, double);
        //calculates the sum of three user-predefined numbers
        static double triplet(double, double, double);
        //calculates the sum of two arrays user-predefined numbers (results a new array where each element is the sums of the pair of the elements in the initial vectors at their coresponding index.)
        static std::vector<double> arrays(std::vector<double> &, std::vector<double> &);
        //shows the results
        static void showResult(double &);
    };
} // namespace operations

#endif // ADD_HH