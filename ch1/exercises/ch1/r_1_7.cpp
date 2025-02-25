//R - 1.7 Write a short C++ function that takes an integer n and returns the sum of
//all the integers smaller than n.Defined in header <cuchar>
#include <cuchar>
#include <iostream>

static auto sum_to_n(int n) -> int
{
	auto result = 0;

	if (n < 0)
	{
		n *= -1;

		for (std::size_t i = 1; i < n; ++i)
		{
			result += i;
		}

		return result * (-1);
	}

	for (std::size_t i = 1; i < n; ++i)
	{
		result += i;
	}

	return result;
};

int main()
{
	std::cout << sum_to_n(5);
	std::cout << "\n";
	std::cout << sum_to_n(-5);
}