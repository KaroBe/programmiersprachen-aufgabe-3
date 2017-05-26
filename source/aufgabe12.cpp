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
				return c > 4.0f;
			});
	biggerFour.resize(std::distance(biggerFour.begin(), it));

	REQUIRE(std::all_of(biggerFour.begin(), biggerFour.end(),
		[](Circle const& c) -> bool{
				return c > 3.0f;
		}));
}

/*

Functor:
-> Klassen, deren Objekte Funktionen repräsentieren
-> haben den Funktionsoperator operator()()
*/

template <typename T>
class functor{
public:
	//Variable saves value the element shall be compared to
	T compareVal_;
	
	//Constructor of functor takes said value and saves it to compareVal
	
	functor(T x) : compareVal_{x} {}

	//when calling the operator()() function, ONLY THE CIRCLE is passed as
	//an parameter, therefore it can be compared to the value the functor object
	//was initialised with
	
	bool operator() (Circle const& c) const
	{
		return c > compareVal_;
	}
};

TEST_CASE("biggerFour_testing_functor_stuff", "[copy_if_std]")
{
	std::vector<Circle> v{
		Circle{5.0f}, Circle{3.0f}, Circle {8.0f},
		Circle{1.0f}, Circle{6.0f}
	};

	std::vector<Circle> biggerFour(v.size());
	auto it = std::copy_if(v.begin(), v.end(), biggerFour.begin(),
			functor<float>{4.0f});
	biggerFour.resize(std::distance(biggerFour.begin(), it));

	REQUIRE(std::all_of(biggerFour.begin(), biggerFour.end(),
		functor<float>{3.0f}));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}
