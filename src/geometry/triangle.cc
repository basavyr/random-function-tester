#include "triangle.hh"

geometry::Triangle::Triangle(double side1, double side2, double side3)
{
    a = side1;
    b = side2;
    c = side3;
}

geometry::Triangle::~Triangle()
{
    auto A = geometry::Area::triangle(a, b, c);
    auto P = geometry::Perimeter::triangle(a, b, c);
    std::cout << "The triangle has: "
              << "\n";
    std::cout << "A= " << A;
    std::cout << "\n";
    std::cout << "P= " << P;
    std::cout << "\n";
}
