//Write a short program that takes as input three integers, a, b, and c, and
//determines if they can be used in a correct arithmetic formula(in the given
//order), like “a + b = c, ” “a = b−c, ” or “a∗b = c.”
#include <iostream>
using namespace std::literals;

static auto input_valid(int v1, int v2, int v3) -> bool
{
	return v1 + v2 == v3
		|| v1 == v2 - v3
		|| v1 * v2 == v3;
}

static auto greeting() -> void
{
	std::cout << "Please enter 3 values.\nThis program will determine if they can be used in a correct arithmetic formula\n"
		<< "(in the given order), like a+b or a = b-c or a*b = c\npress ctrl+z to exit\n\n";
}

auto main() -> int
{
	try
	{
		greeting();

		auto val1 = 0;
		auto val2 = 0;
		auto val3 = 0;

		std::cin.exceptions(std::istream::failbit);

		while (true)
		{
			std::cin >> val1 >> val2 >> val3;

			if (input_valid(val1, val2, val3))
			{
				std::cout << std::boolalpha << true << "\n\n";
				continue;
			}

			std::cout << std::boolalpha << false << "\n\n";
		}
	}

	catch (const std::ios_base::failure& fail)
	{
		std::cerr << fail.what() << "\n";
	}
}