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

	std::sort(happyCircles.begin(), happyCircles.end());
	
	REQUIRE(std::is_sorted(happyCircles.begin(),
		happyCircles.end()));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}