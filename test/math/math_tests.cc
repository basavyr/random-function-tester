#include <iostream>
#include <vector>

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
        (i % 2 == 0) && v.emplace_back(i);
    }
    printArray<std::vector<double>>(v);
}

int main()
{
    test_app();
}