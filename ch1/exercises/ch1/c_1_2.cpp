//Write a short C++ function that takes an array of int
//values and determines if there is a pair of numbers in the array whose product is even.
#include <ios>
#include <iostream>

static auto product_even(const int* p, int sz)
{
	if (!p)
	{
		return false;
	}

	for (size_t i = 0; i < sz; ++i)
	{
		for (size_t j = i + 1; j < sz; ++j)
		{
			if ((p[i] * p[j]) % 2 == 0)
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	int vals[10] = { 3,4,5,8,121,77,77,5,2,67 };

	auto sz = 0;
	auto index = 0;

	while (vals[index] != '\0')
	{
		++sz;
		++index;
	}

	std::cout << std::boolalpha << product_even(vals, sz);
}