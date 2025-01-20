//Write a short C++ program that creates a Pair class that can store two
//objects declared as generic types.Demonstrate this program by creating
//and printing Pair objects that contain five different kinds of pairs,such as
//<int, string> and <float, long>
#include <iostream>
using namespace std::literals;

template <typename T1, typename T2>
class Pair
{
public:
	Pair(const T1& t1, const T2& t2)
		:v1{ t1 },
		v2{ t2 }
	{
	}

	static friend auto operator << (std::ostream& os, const Pair<T1, T2>& p) -> std::ostream&
	{
		return os << p.v1 << " " << p.v2 << "\n";
	}

private:
	T1 v1{};
	T2 v2{};
};

auto main() -> int
{
	auto p1 = Pair{ 7,"Shawn"sv };
	auto p2 = Pair{ 'S',77.7 };
	auto p3 = Pair{ "Shawn7"s,'*' };
	auto p4 = Pair{ true,"True"sv };
	auto p5 = Pair{ static_cast<float>(7.7), static_cast<long>(9) };

	std::cout << p1 << p2 << p3 << p4 << p5;
}