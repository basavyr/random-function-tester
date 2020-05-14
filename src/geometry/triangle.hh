#ifndef TRIANGLE_HH
#define TRIANGLE_HH

#include "area.hh"
#include "perimeter.hh"

namespace geometry
{

    class Triangle
    {
    private:
        double a;
        double b;
        double c;

    public:
        Triangle(double, double, double);
        ~Triangle();
    };

} //namespace geometry

#endif // TRIANGLE_HH
