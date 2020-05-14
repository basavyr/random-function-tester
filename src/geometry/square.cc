#include "square.hh"

geometry::Square::Square(double l)
{
    side = l;
}

geometry::Square::~Square()
{
    auto A = geometry::Area::square(side);
    auto P = geometry::Perimeter::square(side);
    std::cout << "The square has:"
              << "\n";
    std::cout << "A= " << A << "\n";
    std::cout << "P= " << P << "\n";
}
