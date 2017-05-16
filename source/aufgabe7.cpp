#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

#include "circle.hpp"

TEST_CASE("sorted_container", "[circle_container]")
{
	//Vektor füllen
	std::vector<Circle> happyCircles (10);

	for (auto& c : happyCircles)
	{
		c.setRadius(std::rand() % 20 + 1);
	}
	
	//REQUIRE(std::all_of(v.begin(), v.end(),is_sorted()));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}