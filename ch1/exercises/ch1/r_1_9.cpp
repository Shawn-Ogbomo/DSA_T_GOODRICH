//R - 1.9 Write a C++ function printArray(A, m, n) that prints an m × n two-dimensional
//array A of integers, declared to be “int** A, ” to the standard
//output.Each of the m rows should appear on a separate line.
#include <iostream>

static auto print_array(int** A, int m, int n) -> void
{
	if (!A)
	{
		return;
	}

	for (size_t i = 0; i < m; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			std::cout << A[i][j] << " ";
		}

		std::cout << "\n";
	}
}

int main()
{
	auto** vals = new int* [3]
		{
			new int[3] {1, 2, 3},
				new int[3] {4, 5, 6},
				new int[3] {7, 8, 9}
		};

	print_array(vals, 3, 3);

	for (size_t i = 0; i < 3; ++i)
	{
		delete[] vals[i];
	}

	delete[] vals;
}