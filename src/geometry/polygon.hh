#ifndef POLYGON_HH
#define POLYGON_HH

#include "area.hh"
#include "perimeter.hh"

namespace geometry
{
    class Polygon
    {
    private:
        std::vector<int> sides;

    public:
        Polygon(std::vector<int> &sides);
        ~Polygon();
    };
} // namespace geometry

#endif // POLYGON_HH
