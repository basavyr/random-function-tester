#ifndef SQUARE_HH
#define SQUARE_HH

#include "perimeter.hh"
#include "area.hh"

namespace geometry
{
    class Square
    {
    private:
        double side;

    public:
        Square(double);
        ~Square();
    };
} //namespace geometry

#endif // SQUARE_HH
