//don't have to be necessarily included
#include "../../src/geometry/area.hh"
#include "../../src/geometry/perimeter.hh"

#include "../../src/geometry/rectangle.hh"
#include "../../src/geometry/triangle.hh"
#include "../../src/geometry/square.hh"
#include "../../src/geometry/polygon.hh"
#include "../../src/geometry/shapes.hh"

#include <random>

inline void newline()
{
    std::cout << "\n";
}

std::random_device test_rd;
static std::mt19937 test_engine{test_rd()};

template <typename T>
T give_random(T left, T right)
{
    std::uniform_real_distribution<T> dist(left, right);
    //random number for return value
    auto rn = dist(test_engine);
    return static_cast<T>(rn);
}

int generate_int(int left, int right)
{
    std::uniform_int_distribution<int> int_dist(left, right);
    auto intn = static_cast<int>(int_dist(test_engine));
    return intn;
}

void generate_rectangles()
{
    int length = generate_int(1, 10);
    int width = generate_int(1, 15);
    auto x = std::make_unique<geometry::Rectangle>(length, width);
}

void random_test()
{
    //generate the number of tests
    auto n_tests = static_cast<int>(generate_int(0, 100));
    if (n_tests)
    {
        for (int i = 0; i < n_tests; ++i)
        {
            std::cout << "********* TEST" << i + 1 << " *********"
                      << "\n";
            generate_rectangles();
        }
        std::cout << "Simulation ended successfully after " << n_tests << " test runs";
        newline();
    }
    else
    {
        std::cout << "No tests to perform...";
        newline();
        std::cout << "Program finished completely!";
        newline();
    }
}

//run a test from user input
void user_test()
{
    int n_tests;
    std::cout << "Number of geometry tests to be performed";
    std::cout << "\n";
    std::cin >> n_tests;
    if (n_tests)
    {
        for (int i = 0; i < n_tests; ++i)
        {
            generate_rectangles();
        }
        std::cout << "Simulation ended successfully after " << n_tests << " test runs";
        newline();
    }
    else
    {
        std::cout << "No tests to perform...";
        newline();
        std::cout << "Program finished completely!";
        newline();
    }
}

enum test
{
    item1,
    item2,
    item3,
    item4
};

void shape_test()
{
    auto x = std::make_unique<geometry::Shapes>();
}

int main()
{
    // static constexpr int nreps = 1000;
    int nreps = 1000;
    std::cout << "Number of geometry tests to be performed: "
              << "\n";
    // std::cin >> nreps;
    auto start = std::chrono::high_resolution_clock::now();
    for (nreps; nreps; nreps--)
    {
        std::cout << "********* "
                  << "TEST " << nreps << " *********";
        std::cout << "\n";
        shape_test();
        generate_rectangles();
        std::cout << "\n";
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Geometry testing finished after " << static_cast<double>(duration / 1000.0) << " ms";
    newline();
}