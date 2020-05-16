#ifndef AREA_HH
#define AREA_HH

#include "perimeter.hh"
#include <cmath>

namespace geometry
{
    class Area
    {
    private:
        double surface_area;

    public:
        Area();
        ~Area();

        //calculates the area of a square with user-defined sides
        static double square(double side);

        //calculates the area of a triangle with user-defined sides
        static double triangle(double a, double b, double c);

        //calculates the area of a rectangle with user-defined sides
        static double rectangle(double length, double width);

        //calculates the area of a polygon with user-defined N-sides
        static double polygon(std::vector<int> &sides);

        //shows the area of the figure
        static void showResult(double &area);
    };

} // namespace geometry

#endif // AREA_HH
