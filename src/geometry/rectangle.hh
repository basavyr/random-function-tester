#ifndef RECTANGLE_HH
#define RECTANGLE_HH

#include "area.hh"
#include "perimeter.hh"

namespace geometry
{
    class Rectangle
    {
    private:
        double length, width;

    public:
        Rectangle(double, double);
        ~Rectangle();
    };
} // namespace geometry

#endif //RECTANGLE_HH
