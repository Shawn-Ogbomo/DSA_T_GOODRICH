//R - 1.8 Write a short C++ function, isMultiple, that takes two positive long values,
//n and m, and returns true if and only if n is a multiple of m, that is, n = mi
//for some integer i.
#include <ios>
#include <iostream>

static auto is_multiple(long n, long m) -> bool
{
	return !(n % m);
}

static auto skip_input() -> void
{
	std::cin.clear();
	for (char c{}; std::cin >> c;)
	{
		if (std::isdigit(c))
		{
			std::cin.unget();
			return;
		}
	}
}

int main()
{
	std::cout << "This program will check if your first value is a multiple of the second value.\n\n"
		<< "Press ctrl+z to exit\n\n"
		<< "Enter two values : ";

	while (true) try
	{
		std::cin.exceptions(std::istream::failbit);

		for (auto val = 0, multiple = 0; std::cin >> val >> multiple; )
		{
			std::cout << val << " is ";

			if (!is_multiple(val, multiple))
			{
				std::cout << "not ";
			}

			std::cout << "a multiple of " << multiple << "\n";
		}
	}
	catch (const std::ios_base::failure& fail)
	{
		if (std::cin.eof())
		{
			std::cerr << "Exiting...\n";
			return 1;
		}

		std::cerr << fail.what() << '\n';
		skip_input();
	}
}