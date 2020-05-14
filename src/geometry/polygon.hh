#ifndef POLYGON_HH
#define POLYGON_HH

#include "area.hh"
#include "perimeter.hh"

namespace geometry
{
    class Polygon
    {
    private:
        std::vector<double> sides;

    public:
        Polygon(std::vector<double> &sides);
        ~Polygon();
    };
} // namespace geometry

#endif // POLYGON_HH
