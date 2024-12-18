//Write a short C++ function, isTwoPower, that takes an
//int and returns true if and only if i is a power of 2. Do not use multiplication or division, however.

//iteration and compound assignment operator
#include <iostream>

static auto two_power(std::size_t n) -> bool
{
	if (n == 1)
	{
		return true;
	}

	for (size_t i = 2; i <= n; i += i)
	{
		if (i == n)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	for (size_t i = 0; i <= 100; ++i)
	{
		std::cout << i << " is ";

		if (!two_power(i))
		{
			std::cout << "not ";
		}

		std::cout << "a power of 2.\n\n";
	}
}