#include <iostream>

struct Pair
{
public:
	static friend auto operator << (std::ostream& os, const Pair& p)->std::ostream&
	{
		auto& [internal_min, internal_max] = p;
		return os << internal_min << " " << internal_max;
	}

	int min{};
	int max{};
};

static auto min_max(const int* vals, int sz) -> Pair
{
	auto min = vals[0];
	auto max = vals[0];

	for (auto i = 1; i < sz; ++i)
	{
		if (min > vals[i])
		{
			min = vals[i];
		}

		if (max < vals[i])
		{
			max = vals[i];
		}
	}

	return Pair{ min,max };
}

int main()
{
	int vals[] = { -5, -10, -4, -2, -1,'\0' };

	std::cout << min_max(vals, 5);
}