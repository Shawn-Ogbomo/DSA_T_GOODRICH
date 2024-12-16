//Write a C++ class, AllKinds, that has three member variables of type int,
//long, and float, respectively.Each class must include a constructor function
//that initializes each variable to a nonzero value, and each class should
//include functions for setting the value of each type, getting the value of
//each type, and computing and returning the sum of each possible combination of types.
#include <iostream>

class AllKinds
{
public:
	AllKinds() = default;
	AllKinds(int n1, long n2, float n3)
		:v1{ n1 },
		v2{ n2 },
		v3{ n3 } {
	}

	int value1()const { return v1; };
	long value2()const { return v2; };
	float value3()const { return v3; };

	void set_value1(int n) { v1 = n; };
	void set_value2(long n) { v2 = n; };
	void set_value3(float n) { v3 = n; };

	double sum() const { return static_cast<double>(v1 + v2) + v3; };
private:
	int v1{};
	long v2{};
	float v3{};
};

int main()
{
	auto a = AllKinds{ 7,77,77.7 };

	std::cout << a.value1() << " " << a.value2() << " " << a.value3() << "\n";
	std::cout << a.sum() << "\n";

	a.set_value1(4);
	a.set_value2(44);
	a.set_value3(44.4);

	std::cout << a.value1() << " " << a.value2() << " " << a.value3() << "\n";
	std::cout << a.sum() << "\n";
}