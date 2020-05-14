#include "area.hh"

//constructor
geometry::Area::Area()
{
}

//destructor
geometry::Area::~Area()
{
    showResult(surface_area);
}

double geometry::Area::rectangle(double length, double width)
{
    auto result = static_cast<double>(length * width);
    return result;
}

double geometry::Area::square(double side)
{
    auto result = static_cast<double>(side * side);
    return result;
}

double geometry::Area::triangle(double a, double b, double c)
{
    //calculate semi-perimeter of the triangle
    auto p = static_cast<double>(Perimeter::triangle(a, b, c) / 2.0);

    auto area = sqrt(p * (p - a) * (p - b) * (p - c));
    return static_cast<double>(area);
}

void geometry::Area::showResult(double &area)
{
    auto errMsg = "Area calculation failed. Status: ";
    auto okMsg = "Area calculation finished with status: ";
    bool ok = 1;
    if (area)
    {
        std::cout << "The area of the figure is: " << area;
        std::cout << "\n";
        std::cout << okMsg << ok;
        std::cout << "\n";
    }
    else
    {
        ok = 0;
        std::cout << errMsg << ok;
        std::cout << "\n";
    }
}