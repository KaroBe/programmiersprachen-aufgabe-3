#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

bool is_multiple_of_3(int i)
{
	return i % 3 == 0;
}

bool aint_multiple_of_3(int i)
{
	return i % 3 != 0;
}

TEST_CASE("filter alle vielfache von drei", "[erase]")
{
	//Vektor füllen
	std::vector<unsigned int> v (100);
	int counter = 0;
	for (auto& x : v)
	{
		x = counter;
		++counter;
	}
	
	v.erase(std::remove_if(v.begin(), v.end(),
		aint_multiple_of_3), v.end());

	//Test mit all of aus <algorithm>
	REQUIRE(std::all_of(v.begin(), v.end(),
		is_multiple_of_3));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}