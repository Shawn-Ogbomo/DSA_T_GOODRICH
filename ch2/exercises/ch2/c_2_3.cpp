//Most modern C++ compilers have optimizers that can detect simple cases
//when it is logically impossible for certain statements in a program to ever
//be executed.In such cases, the compiler warns the programmer about the
//useless code.Write a short C++ function that contains code for which it
//is provably impossible for that code to ever be executed, but your favorite
//C++ compiler does not detect this fact.
#include <iostream>

static auto bad_function(int n) -> void
{
	if (!(n <= 7 || n >= 7))
	{
		std::cout << "Invalid bounds...";
		return;
	}

	std::cout << "Valid bounds...\n";
}

auto main() -> int
{
	try
	{
		std::cout << "Enter a non-integral value or ctrl+z to exit...\n\n";

		std::cin.exceptions(std::istream::failbit);

		for (auto v = 0; std::cin >> v;)
		{
			bad_function(v);
		}
	}

	catch (const std::ios_base::failure& fail)
	{
		std::cerr << fail.what() << "\n";
	}
}