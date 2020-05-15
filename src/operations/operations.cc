#include "operations.hh"
#include "sqrt.hh"
#include "trig.hh"
#include "add.hh"

operations::Operations::Operations()
{
    std::random_device rd;
    static std::mt19937 twister{rd()};
}

void operations::Operations::showResult(double &result)
{
    std::cout << result;
    std::cout << "\n";
}