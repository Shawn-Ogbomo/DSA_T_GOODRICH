//Write a short C++ program that takes two arguments of type STL vec
//tor<double>, a and b, and returns the element - by - element product of a
//and b.That is, it returns a vector c of the same length such that c[i] =
//a[i] b[i].
#include <vector>
#include <numeric>
#include <iostream>

int main()
{
	auto vals_1 = std::vector<double>(10);
	auto vals_2 = std::vector<double>(10);

	std::iota(vals_1.begin(), vals_1.end(), 7);
	std::iota(vals_2.begin(), vals_2.end(), 10);

	auto vals_3 = std::vector<double>(10);

	auto sz = vals_1.size();

	for (std::size_t i = 0; i < sz; ++i)
	{
		vals_3[i] = (vals_1[i] * vals_2[i]);
	}

	for (const auto& target : vals_3)
	{
		std::cout << target << " ";
	}
}