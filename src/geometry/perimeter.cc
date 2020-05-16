#include "perimeter.hh"

//calculates the perimeter of a square with user-defined sides
double geometry::Perimeter::square(double side)
{
    auto P = 4.0 * side;
    return static_cast<double>(P);
}

//calculates the perimeter of a triangle with user-defined sides
double geometry::Perimeter::triangle(double a, double b, double c)
{
    auto P = static_cast<double>(a + b + c);
    return P;
}

//calculates the perimeter of a rectangle with user-defined sides
double geometry::Perimeter::rectangle(double length, double width)
{
    auto P = 2.0 * length + 2.0 * width;
    return static_cast<double>(P);
}

//calculates the perimeter of a polygon with user-defined N-sides
double geometry::Perimeter::polygon(std::vector<int> &sides)
{
    size_t Nsides = sides.size();
    double P = 0.0;
    bool geom_checker = true;
    for (int l = 0; l < Nsides && geom_checker; ++l)
    {
        // auto &&elem = sides.at(l);
        if (!sides.at(l))
        {
            geom_checker = false;
            std::cout << "The polygon is not a valid geometric figure!";
            std::cout << "\n";
        }
        P += static_cast<int>(sides.at(l));
    }
    if (!geom_checker)
        return 0;
    return P;
}

//class constructor (makes a polygon with user-defined sides and automatically stores the resulting perimeter in the private variable, for later output)
geometry::Perimeter::Perimeter(std::vector<int> &sides)
{
    perimeter = polygon(sides);
}

//class destructor (shows the private perimeeter result)
geometry::Perimeter::~Perimeter()
{
    showResult(perimeter);
}

//shows the perimeter of the figure
void geometry::Perimeter::showResult(double &result)
{
    std::cout << "P= ";
    std::cout << result;
    std::cout << "\n";
}