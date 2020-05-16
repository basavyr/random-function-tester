#ifndef SHAPES_HH
#define SHAPES_HH

#include "area.hh"
#include "perimeter.hh"
#include "polygon.hh"
#include "square.hh"
#include "triangle.hh"
#include "rectangle.hh"

#include <iostream>
#include <random>

#include <array>
namespace geometry
{
    class Shapes
    {
    private:
        double pick_shape;

    public:
        enum Shape
        {
            RECTANGLE,
            SQUARE,
            TRIANGLE,
            POLYGON,
            MAX_SHAPE
        };

        struct shape_info
        {
            double area;
            double perimeter;
            // std::array<double, 2> sides;
            std::vector<double> sides;
            Shape what_shape;
            shape_info()
            {
            }
        };

    public:
        Shapes();
        ~Shapes();

    public:
        static Shape generateRandomShape();
        static void Shape_Geometry();
        static void Do_Geometry(Shape, shape_info &);
    };
} // namespace geometry

#endif // SHAPES_HH
