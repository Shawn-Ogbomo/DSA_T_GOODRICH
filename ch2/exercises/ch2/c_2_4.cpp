// Design a class Line that implements a line, which is represented by the
// formula y = ax + b.Your class should store a and b as double member
// variables.Write a member function intersect(ℓ) that returns the x coordinate
// at which this line intersects line ℓ.If the two lines are parallel, then your
// function should throw an exception Parallel.Write a C++ program that
// creates a number of Line objects and tests each pair for intersection.Your
// program should print an appropriate error message for parallel lines.
#include <sstream>
#include <iostream>
#include <exception>

class Parallel : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
};

class Same : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
};

class Line
{
public:
	Line() = default;

	Line(double v1, double v2)
		:a{ v1 },
		b{ v2 } {
	}

	static friend auto operator >> (std::istream& is, Line& l) -> std::istream&
	{
		if (std::istream::sentry{ is })
		{
			std::cin >> l.a >> l.b;
		}

		return is;
	}

	static friend auto operator << (std::ostream& os, const Line& l) -> std::ostream&
	{
		return os << "{" << l.a << "," << l.b << "}";
	}

	static friend auto operator == (const Line& lhs, const Line& rhs) -> bool
	{
		return std::tie(lhs.a, lhs.b) == std::tie(rhs.a, rhs.b);
	}

	static auto intersect(const Line& lhs, const Line& rhs) -> double
	{
		if (lhs == rhs)
		{
			throw Same{ "Both points are the same...\n" };
		}

		if (lhs.a == rhs.a && lhs.b != rhs.b)
		{
			std::ostringstream oss;

			oss << "\nLines: " << lhs << " " << rhs << " Are parallel...\n\n";

			throw Parallel{ oss.str() };
		}

		return ((lhs.b * -1) + rhs.b) / (rhs.a < 0 ? lhs.a + rhs.a : lhs.a - rhs.a);
	}

private:
	double a{};
	double b{};
};

static auto clean_up_mess(std::istream& is = std::cin) -> void
{
	is.clear();

	for (char c{}; std::cin >> c; )
	{
		if (isdigit(c))
		{
			is.unget();
			return;
		}
	}
}

auto main() -> int
{
	std::cin.exceptions(std::istream::failbit);

	while (true)try
	{
		for (Line l1, l2; std::cin >> l1 >> l2;)
		{
			std::cout << "\nPoint of intersection: " << Line::intersect(l1, l2) << "\n";
		}
	}

	catch (const Parallel& e)
	{
		std::cerr << e.what() << "\n";
	}

	catch (const Same& e)
	{
		std::cerr << e.what() << "\n";
	}

	catch (const std::ios_base::failure& fail)
	{
		std::cerr << fail.what() << "\n\n";

		if (std::cin.eof())
		{
			return 1;
		}

		clean_up_mess();
	}
}