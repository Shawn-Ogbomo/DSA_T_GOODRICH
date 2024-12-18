//Write a C++ function that takes an STL vector of int values and prints all
//the odd values in the vector.

#include <vector>
#include <numeric>
#include <iostream>

static auto display_vals(const std::vector<int>& v)
{
	if (v.empty())
	{
		return;
	}

	for (const auto& target : v)
	{
		if (target % 2 == 1) {
			std::cout << target << " ";
		}
	}
}

int main()
{
	auto vals = std::vector<int>(16);

	std::iota(vals.begin(), vals.end(), 0);

	display_vals(vals);
}