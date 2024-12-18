//Write a C++ function that takes an STL vector of int values and determines
//if all the numbers are different from each other(that is, they are distinct).
#include<ios>
#include<vector>
#include<numeric>
#include<iostream>
#include<algorithm>

static auto contains_duplicates(const std::vector<int>& v) -> bool
{
	if (v.empty())
	{
		return false;
	}

	return std::any_of(v.begin(), v.end(), [&v](auto val)
		{
			return  std::count(v.begin(), v.end(), val) > 1;
		});
}

int main()
{
	auto vals = std::vector<int>(10);

	std::iota(vals.begin(), vals.end(), 0);

	std::cout << std::boolalpha << contains_duplicates(vals);
}