//Write a short C++ function that takes a positive
//value x and returns
//the number of times we can divide x by 2 before we get a number less
//than 2.
#include <iostream>

static auto count_divisiable_by_2(double x) -> int
{
	auto count = 0;

	while (x >= 2)
	{
		x /= 2;
		++count;
	}

	return count;
}

int main()
{
	double vals[10] = { 66.4,12.3,85.3,88.4,12.4,77.7,71.9,44.4,87.2,11.1 };

	for (size_t i = 0; i < 10; ++i)
	{
		std::cout << vals[i] << " is divisible by 2: "
			<< count_divisiable_by_2(vals[i]) << " times \n";
	}
}