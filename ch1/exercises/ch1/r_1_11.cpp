//R - 1.11 Write a C++ class, Flower, that has three member variables of type string,
//int, and float, which respectively represent the name of the flower, its
//number of pedals, and price.Your class must include a constructor method
//that initializes each variable to an appropriate value, and your class should
//include functions for setting the value of each type, and getting the value
//of each type.
#include <string>
#include <iostream>
#include <string_view>

class Flower
{
public:
	Flower() = default;
	Flower(std::string_view n, int p, double pr)
		:name{ n },
		pedals{ p },
		price{ pr }
	{
		std::string pattern{ "123456789."
			"`~!@#$%^&*()_-=+[{]}" };

		std::string pattern2{ R"(;:',<.>/?|\")" };

		if (pedals < 0
			|| price < 0
			|| name.find_first_of(pattern) != std::string::npos
			|| name.find_first_of(pattern2) != std::string::npos)
		{
			throw std::invalid_argument{ "Bad Flower object...\n" };
		}
	}

	auto num_pedals() const -> int
	{
		return pedals;
	}

	auto type() const -> std::string_view
	{
		return name;
	}

	auto cost() const -> double
	{
		return price;
	}

private:
	std::string name;
	int pedals{};
	double price{};
};

int main()
{
	try
	{
		auto f = Flower{ "Rose",4,4.99 };
		auto f2 = Flower{ "Rose\"",4,4.99 };
		auto f3 = Flower{ "\"Rose",4,4.99 };
		auto f4 = Flower{ "Rose",-3,-4 };
		auto f5 = Flower{ "Rose%",3,4 };
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what();
		return 1;
	}
}