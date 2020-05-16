#include "shapes.hh"

std::random_device rd;
static std::mt19937 twister{rd()};

static constexpr int min_size = 10;
static constexpr int max_size = 150;

geometry::Shapes::Shapes()
{
    Shape_Geometry();
}

geometry::Shapes::~Shapes()
{
}

template <typename T>
T generateRandomNumber()
{
    std::uniform_real_distribution<double> T_dist(min_size, max_size);
    auto rnum = static_cast<T>(T_dist(twister));
    return rnum;
}

template <typename T>
void generateArray(std::vector<T> &v)
{
    const size_t arr_size = generateRandomNumber<size_t>();
    for (auto id = 0; id < arr_size; ++id)
    {
        auto r_num = generateRandomNumber<T>();
        v.emplace_back(r_num);
    }
}

template <typename T>
void printArray(std::vector<T> &v)
{
    for (auto &&n : v)
        std::cout << n << " ";
    std::cout << "\n";
}

int RandomInt(int left, int right)
{
    std::uniform_int_distribution<int> int_dist(left, right);
    auto rand_int = int_dist(twister);
    return static_cast<int>(rand_int);
}

double RandomReal(double left, double right)
{
    std::uniform_real_distribution<double> r_dist(left, right);
    auto rand_real = r_dist(twister);
    return static_cast<double>(rand_real);
}

geometry::Shapes::Shape geometry::Shapes::generateRandomShape()
{
    Shape max = MAX_SHAPE;
    int right = static_cast<int>(max);
    std::uniform_int_distribution<int> dist(0, right - 1);
    int rand_shape = dist(twister);
    Shape result_shape = static_cast<geometry::Shapes::Shape>(rand_shape);
    return result_shape;
}

void geometry::Shapes::Shape_Geometry()
{
    //create a shape
    auto shape = generateRandomShape();
    shape = geometry::Shapes::Shape::POLYGON;
    geometry::Shapes::shape_info info;
    Do_Geometry(shape, info);
}

void geometry::Shapes::Do_Geometry(geometry::Shapes::Shape shape, geometry::Shapes::shape_info &info)
{
    switch (shape)
    {
    case Shapes::Shape::RECTANGLE:
    {
        auto length = RandomInt(min_size, max_size);
        auto width = RandomInt(min_size, max_size);
        auto area = geometry::Area::rectangle(length, width);
        auto perimeter = geometry::Perimeter::rectangle(length, width);
        info.area = area;
        info.perimeter = perimeter;
        info.sides.emplace_back(length);
        info.sides.emplace_back(width);
        info.what_shape = Shape::RECTANGLE;
        break;
    }

    case Shapes::Shape::SQUARE:
    {
        auto side = RandomInt(min_size, max_size);
        auto area = geometry::Area::square(side);
        auto perimeter = geometry::Perimeter::square(side);
        info.area = area;
        info.perimeter = perimeter;
        info.sides.emplace_back(side);
        info.what_shape = Shape::SQUARE;
        break;
    }

    case Shapes::Shape::TRIANGLE:
    {

        auto a = RandomInt(min_size, max_size);
        auto b = RandomInt(min_size, max_size);
        auto c = RandomInt(min_size, max_size);
        auto area = geometry::Area::triangle(a, b, c);
        auto perimeter = geometry::Perimeter::triangle(a, b, c);
        info.area = area;
        info.perimeter = perimeter;
        info.sides.emplace_back(a);
        info.sides.emplace_back(b);
        info.sides.emplace_back(c);
        info.what_shape = Shape::TRIANGLE;
        break;
    }

    case Shapes::Shape::POLYGON:
    {
        std::vector<int> sides;
        const int size = RandomInt(min_size, max_size);
        generateArray<int>(sides);
        printArray<int>(sides);
        auto area = geometry::Area::polygon(sides);
        auto perimeter = geometry::Perimeter::polygon(sides);
        info.area = area;
        info.perimeter = perimeter;
        // info.sides.emplace_back(length);
        // info.sides.emplace_back(width);
        info.what_shape = Shape::POLYGON;
        break;
    }
    }
}