//Write a short C++ program that takes all the lines input to standard input
//and writes them to standard output in reverse order.That is, each line is
//output in the correct order, but the ordering of the lines is reversed.

#include <string>
#include <vector>
#include <iostream>

int main()
{
	std::cout << "Input a few lines, press ctrl+z to stop.\n Lines will be displayed in reverse order.\n\n";

	auto vals = std::vector <std::string>{};

	for (std::string s; std::cin >> s;)
	{
		vals.push_back(s);
	}

	if (!std::cin)
	{
		const auto sz = vals.size();

		for (int i = sz - 1; i > -1; --i)
		{
			std::cout << vals[i] << "\n";
		}
	}
}