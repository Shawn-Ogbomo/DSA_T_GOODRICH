//R - 1.8 Write a short C++ function, isMultiple, that takes two positive long values,
//n and m, and returns true if and only if n is a multiple of m, that is, n = mi
//for some integer i.
#include <ios>
#include <iostream>

static auto is_multiple(long n, long m) -> bool
{
	return !(n % m);
}

int main()
{
	for (auto& val : { 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90, 96,97,98,99,100,101,102 })
	{
		std::cout << val << " is ";

		if (!is_multiple(val, 6))
		{
			std::cout << "not ";
		}

		std::cout << "a multiple of " << 6 << "\n";
	}
}