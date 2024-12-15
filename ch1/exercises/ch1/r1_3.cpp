//R - 1.3 Give a C++ definition of a
//called
//that consists of two members.
//The first is an integer called first, and the second is a double called
//second.
#include <iostream>

struct Pair
{
public:
	int first{};
	double second{};
};

int main()
{
	auto pair = Pair{ 1,1.1 };
	std::cout << pair.first << " " << pair.second << "\n";
}