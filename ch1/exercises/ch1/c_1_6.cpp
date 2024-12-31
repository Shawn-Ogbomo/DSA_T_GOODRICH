//Write a short C++ program that outputs all possible strings formed by
//using each of the characters ’a’, ’b’, ’c’, ’d’, ’e’, and ’f’ exactly
//once.
#include <iostream>
#include <algorithm>

static auto sub_case(std::string& s, std::size_t curr, std::size_t pos) -> bool
{
	if ((pos + 1) % 4 > 0)
	{
		char c = s[curr] + 1;

		while (c == s[0] || c == s[1])
		{
			++c;
		}

		std::swap(s[curr], *std::find(s.begin(), s.end(), c));
		std::sort(s.begin() + 3, s.end());
		return true;
	}

	return false;
}

static auto new_case(std::string& s, std::size_t pos, std::size_t sz) -> void
{
	if (sub_case(s, 2, pos)) {
		return;
	}

	char c = s[1];

	for (std::size_t index = 1; index < sz; ++index)
	{
		if (c == s[index])
		{
			++c;

			if (c == s[0])
			{
				++c;
			}

			break;
		}
	}

	if (auto last_new_case = 'f'; c <= last_new_case)
	{
		std::swap(s[1], *std::find(s.begin(), s.end(), *std::find(s.begin(), s.end(), c)));
		std::sort(s.begin() + 2, s.end());
	}
}

static auto display_all_combinations(char c, std::string s) -> void
{
	s.erase(std::find(s.begin(), s.end(), c));
	s.insert(0, 1, c);

	auto sz = s.size();

	for (std::size_t i = 0; i < (sz - 2) * 5; ++i)
	{
		for (std::size_t j = 0, pos_x = 3, pos_y = 4; j < sz; ++j)
		{
			std::cout << c;

			for (std::size_t k = 1; k < sz; ++k)
			{
				std::cout << s[k];
			}

			if (pos_x == sz - 1)
			{
				pos_x = 3;
				pos_y = 4;
			}

			if (j < sz - 1)
			{
				std::swap(s[pos_x], s[pos_y]);
				++pos_x;
				++pos_y;
			}

			std::cout << "\n";
		}

		new_case(s, i, sz);
		std::cout << "\n";
	}
}

auto main() -> int
{
	std::string vals{ "abcdef" };

	for (const auto& target : vals)
	{
		display_all_combinations(target, vals);
		std::cout << "\n\n";
	}
}