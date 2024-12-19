//Write a C++ function that takes an array containing the set of all integers
//in the range 1 to 52 and shuffles it into random order.Use the built - in function//rand, which returns a pseudo - random integer each time it is called.
//Your function should output each possible order with equal probability.
#include <array>
#include <random>
#include <numeric>
#include <iostream>

static auto shuffle(std::array<int, 52>& v) -> void
{
	static std::mt19937 rd;
	static std::uniform_int_distribution dist(0, 51);

	const auto sz = v.size();

	for (size_t i = 0; i < sz; ++i)
	{
		auto pos_random = dist(rd);

		std::swap(v[i], v[pos_random]);
	}
}

static auto print_array(const std::array<int, 52>& v) -> void
{
	for (const auto& target : v)
	{
		std::cout << target << "\n";
	}
}

int main()
{
	auto vals = std::array<int, 52>{};

	std::iota(vals.begin(), vals.end(), 1);

	std::cout << "Before shuffle\n\n";

	print_array(vals);

	shuffle(vals);

	std::cout << "\nAfter shuffle\n\n";

	print_array(vals);
}