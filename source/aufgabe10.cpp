#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

template <typename T>

std::vector<T> filter (std::vector<T> const& v;
	TYPE ???? praedikat)
{
	return v.erase(std::remove_if(v.begin(), v.end(),
		praedikat), v.end());
}

bool is_even (int n)
{
	return n % 2 == 0;
}

TEST_CASE("filter alle vielfache von drei", "[erase]")
{
	std::vector<int> v{1,2,3,4,5,6};
	std::vector<int> alleven = filter(v,is_even);

	REQUIRE(std::all_of(v.begin(), v.end(),
		is_even));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}