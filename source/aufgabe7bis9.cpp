#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream> // std::cout
#include <iterator> // std::ostream_iterator<>

#include "circle.hpp"


TEST_CASE("sorted_container", "[circle_container]")
{
	//Vektor füllen
	std::vector<Circle> happyCircles (10);

	for (auto& c : happyCircles)
	{
		c.setRadius(std::rand() % 20 + 1);
	}

	//3.7 sortieren mit überladenen Vergleichsoperatoren

	std::vector<Circle> c1(happyCircles.size());
	std::copy(happyCircles.begin(), happyCircles.end(), c1.begin());
	std::sort(c1.begin(), c1.end());

	REQUIRE(std::is_sorted(c1.begin(), c1.end()));

	//3.8 sortieren nach Vergleichsfunktion implementiert mit Lambda

	std::vector<Circle> c2(happyCircles.size());
	std::copy(happyCircles.begin(), happyCircles.end(), c2.begin());
	std::sort(c2.begin(), c2.end(),
		[](Circle const& lhs, Circle const& rhs) -> bool{
			return (lhs <= rhs);
		});

	REQUIRE(std::is_sorted(c2.begin(), c2.end()));
}

TEST_CASE("transform_container", "[int_containers]")
{
	std::vector <int> v1 {1,2,3,4,5,6,7,8,9};
	std::vector <int> v2 {9,8,7,6,5,4,3,2,1};
	std::vector <int> v3 (v1.size());

	std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),
		[](int v1_el, int v2_el) -> int {
			return v1_el + v2_el;
		});

	REQUIRE(std::all_of(v3.begin(), v3.end(),
		[](int x) -> bool{
			return x == 10;
		}));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}
