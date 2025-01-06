//Write an efficient C++ function that takes any integer value i and returns
//2 ^ i, as a long value.Your function should not multiply 2 by itself i times;
//there are much faster ways of computing 2 ^ i
#include <iostream>

static auto compute_2_raised_to_i(int i) -> long
{
	auto result = 1;

	for (size_t internal_i = 0; internal_i < i / 2; ++internal_i)
	{
		result *= 2;
	}

	return i % 2 == 1 ? result * result * 2 : result * result;
}

auto main() -> int
{
	for (int i = 0; i <= 30; ++i)
	{
		std::cout << compute_2_raised_to_i(i) << "\n";
	}
}