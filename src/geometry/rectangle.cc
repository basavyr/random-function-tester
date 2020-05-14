#include "rectangle.hh"

geometry::Rectangle::Rectangle(double l1, double l2)
{
    length = l1;
    width = l2;
}

geometry::Rectangle::~Rectangle()
{
    //area of the figure
    const double A = geometry::Area::rectangle(length, width);
    //perimeter of the figure
    const double P = geometry::Perimeter::rectangle(length, width);
    std::cout << "The rectangle: ";
    std::cout << "A= " << A;
    std::cout << "\n";
    std::cout << "P= " << P;
    std::cout << "\n";
}