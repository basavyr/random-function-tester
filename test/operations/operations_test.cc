#include "../../src/operations/operations.hh"

#include <iostream>

std::random_device test_rd;
static std::mt19937 test_engine{test_rd()};

//generate random number in a predefined interval
int GiveRandomNumber(int right)
{
    std::uniform_int_distribution<int> dist(0, right);
    auto num = dist(test_engine);
    return num;
}

double GiveRandomReal(double right)
{
    std::uniform_real_distribution<double> rdist(0, right);
    auto rnum = rdist(test_engine);
    return rnum;
}

static const double pi = 3.141592654;

void generate_random_tests()
{
    // auto x = std::make_unique<operations::Trig>(GiveRandomReal(pi));
}

void generateTrigTest(uint32_t n_tests)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Testing started...";
    std::cout << "\n";
    for (int id = 0; id < n_tests; ++id)
    {
        // std::cout << "******** TEST " << id << " ********"<< "\n";
        generate_random_tests();
        // std::cout << "\n";
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "The testing finished succsessfully after " << static_cast<double>(duration / 1000000.0) << " s"
              << "\n";
    std::cout << "N= " << n_tests << " were executed..."
              << "\n";
}

void generateOperationsTest(uint32_t n_tests)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Testing started...";
    std::cout << "\n";
    for (int id = 0; id < n_tests; ++id)
    {
        // std::cout << "******** TEST " << id << " ********"<< "\n";
        // auto x = std::make_unique<operations::Operations>(n_tests);
        // std::cout << "\n";
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "The testing finished succsessfully after " << static_cast<double>(duration / 1000000.0) << " s"
              << "\n";
    std::cout << "N= " << n_tests << " were executed..."
              << "\n";
}

int main()
{
    std::cout << "How many times to repeat the test?"
              << "\n";
    int reps;
    std::cin >> reps;
    for (reps; reps; reps--)
    {
        auto n_tests = GiveRandomNumber(1000);
        generateOperationsTest(n_tests);
    }
}