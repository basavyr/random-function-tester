#include "../src/geometry/area.hh"
#include "../src/geometry/perimeter.hh"
#include "../src/geometry/polygon.hh"

#include <future>
#include <ctime>
#include <utility>
#include <functional>
#include <any>
#include <vector>

inline void newline()
{
	std::cout << "\n";
}

int main()
{
	std::vector<double> poly = {1, 2, 3, 4, 5};
	for (auto &&x : poly)
		std::cout << x << " ";
	newline();
	auto polyg = std::make_unique<geometry::Polygon>(poly);
	for (auto &&x : poly)
		std::cout << x << " ";
	newline();
}