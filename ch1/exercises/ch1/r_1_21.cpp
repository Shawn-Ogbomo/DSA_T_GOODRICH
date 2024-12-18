//Write a short C++ function that takes an integer n and returns the sum of
//all the odd integers smaller than n.
#include <iostream>

static auto odd_sum(std::size_t n) -> int
{
	auto result = 0;

	for (size_t i = 0; i < n; ++i)
	{
		if (i % 2 == 1)
		{
			result += i;
		}
	}

	return result;
}

int main()
{
	for (size_t i = 0; i <= 50; ++i)
	{
		std::cout << odd_sum(i) << " \n";
	}
}