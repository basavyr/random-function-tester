#ifndef PERIMETER_HH
#define PERIMETER_HH

#include <iostream>
#include <vector>

namespace geometry
{
    class Perimeter
    {
    private:
        double perimeter;

    public:
        //calculates the perimeter of a rectangle with user-defined sides
        static double rectangle(double length, double width);
        //calculates the perimeter of a square with user-defined sides
        static double square(double side);
        //calculates the perimeter of a triangle with user-defined sides
        static double triangle(double a, double b, double c);
        //calculates the perimeter of a polygon with user-defined N-sides
        static double polygon(std::vector<int> &sides);

    public:
        static void showResult(double &result);
        Perimeter(std::vector<int> &sides);
        ~Perimeter();
    };
} //namespace geometry

#endif // PERIMETER_HH
