//Write a C++ class Vector2, that stores the(x, y) coordinates of a two
//dimensional vector, where x and y are of type double.Show how to
//override various C++ operators in order to implement the addition of two
//vectors(producing a vector result), the multiplication of a scalar times
//a vector(producing a vector result), and the dot product of two vectors
//(producing a double result).
#include <iostream>

class Vector2
{
public:
	Vector2() = default;

	Vector2(double v1, double v2)
		:x{ v1 },
		y{ v2 } {
	}

	static friend auto operator+(const Vector2& lhs, const Vector2& rhs) -> Vector2
	{
		return Vector2{ lhs.x + rhs.x, lhs.y + rhs.y };
	}

	static friend auto operator*(const Vector2& lhs, double scalar) -> Vector2
	{
		return Vector2{ lhs.x * scalar, lhs.y * scalar };
	}

	static friend auto operator << (std::ostream& os, const Vector2& v) -> std::ostream&
	{
		return os << v.x << " " << v.y;
	}

	static friend auto dot_product(const Vector2& lhs, const Vector2& rhs) -> double
	{
		return (lhs.x * rhs.x) + (lhs.y * rhs.y);
	}

private:
	double x{};
	double y{};
};

int main()
{
	auto v1 = Vector2{ 2,3 };
	auto v2 = Vector2{ 6,7 };

	std::cout << "Operator + : " << v1 + v2 << "\n";
	std::cout << "Operator (scalar) *: " << v1 * 3 << "\n";
	std::cout << "Operator (scalar) *: " << v2 * 3 << "\n";
	std::cout << "Dot product *: " << dot_product(v1, v2) << "\n";
}