#include <iostream>
#include <vector>

#include "../../src/math/derivative.hh"
#include "../../src/math/math.hh"

template <typename T>
void printArray(T &array)
{
    for (auto &&n : array)
        std::cout << n << " ";
    std::cout << "\n";
}

void test_app()
{
    std::vector<double> v;
    for (int i = 0; i < 10; ++i)
    {
        int xx = 1;
        (i % 2 == 0) && v.emplace_back(i);
    }
    printArray<std::vector<double>>(v);
}

double d2x(double x)
{
    return 2.0 * x;
}

void test_derivative()
{
    auto x = math::Derivative::generateFunctionArray(d2x);
    for (auto &&n : x)
    {
        std::cout << "( " << n.x << " , " << n.y << " )"
                  << "\n";
    }
    auto dx = math::Derivative::Differentiate_Array(x);
    for (auto &&n : dx)
        std::cout << n << " ";
    std::cout << "\n";
}

void test_mathclass()
{
    auto x = std::make_unique<math::Math>();
}

int main()
{
    // test_app();
    // test_derivative();
    int n_tests = 1;
    for (auto it = 0; it < n_tests; ++it)
    {
        test_mathclass();
        std::cout << "\n";
    }
}