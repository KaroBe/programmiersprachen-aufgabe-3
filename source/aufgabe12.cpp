#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "circle.hpp"
#include <vector>

TEST_CASE("biggerFour_testing_lambda_stuff", "[copy_if_std]")
{
	std::vector<Circle> v{
		Circle{5.0f}, Circle{3.0f}, Circle {8.0f},
		Circle{1.0f}, Circle{6.0f}
	};

	std::vector<Circle> biggerFour(v.size());
	auto it = std::copy_if(v.begin(), v.end(), biggerFour.begin(),
			[](Circle const& c) -> bool{
				return c == 4.0f;
			});
	biggerFour.resize(std::distance(biggerFour.begin(), it));

	REQUIRE(std::all_of(biggerFour.begin(), biggerFour.end(),
		[](Circle const& c) -> bool{
				return c > 3.0f;
		}));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}
