//The birthday paradox says that the probability that two people in a room
//will have the same birthday is more than half as long as the number of
//people in the room(n), is more than 23. This property is not really a
//paradox, but many people find it surprising.Design a C++ program that can
//test this paradox by a series of experiments on randomly generated birth
//days, which test this paradox for n = 5, 10, 15, 20, ..., 100. You should run
//at least 10 experiments for each value of n and it should output, for each
//n, the number of experiments for that n, such that two people in that test
//have the same birthday
#include <ios>
#include <random>
#include <vector>
#include <iostream>

enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class Day
{
	sun = 1, mon, tue, wed, thu, fri, sat
};

static auto leap_year(int yy) -> bool
{
	return (yy % 4 == 0) && (yy % 100 == 0) && (yy % 400 == 0)
		|| (yy % 4 == 0) && (yy % 100 != 0);
}

static auto days_in_month(Month m, int yy) -> int
{
	switch (m)
	{
	case Month::jan:
	case Month::mar:
	case Month::may:
	case Month::jul:
	case Month::aug:
	case Month::oct:
	case Month::dec:
	{
		return 31;
	}

	case Month::apr:
	case Month::jun:
	case Month::sep:
	case Month::nov:
	{
		return 30;
	}

	case Month::feb:
	{
		return leap_year(yy) ? 29 : 28;
	}
	default:
		throw std::invalid_argument{ "Invalid month..." };
	}
}

class Birthday
{
	static constexpr auto year_limit = 2025;
public:
	Birthday() = default;

	Birthday(int mm, int dd, int yy)
		:m{ mm },
		d{ dd },
		y{ yy }
	{
		if (m < static_cast<int>(Month::jan) || m > static_cast<int>(Month::dec))
		{
			throw std::invalid_argument{ "Invalid month..." };
		}

		if (d < 1 || d > days_in_month(static_cast<Month>(mm), yy))
		{
			throw std::invalid_argument{ "Invalid day..." };
		}

		if (y > year_limit)
		{
			throw std::invalid_argument{ "Invalid year..." };
		}
	}

	static friend auto operator == (const Birthday& lhs, const Birthday& rhs) -> bool
	{
		return std::tie(lhs.m, lhs.d, lhs.y) == std::tie(rhs.m, rhs.d, rhs.y);
	}

	static friend auto operator << (std::ostream& os, const Birthday& b)->std::ostream&
	{
		return os << b.m << "/" << b.d << "/" << b.y;
	}

private:
	int m{};
	int d{};
	int y{};
};

static auto birthday_paradox(const std::vector<Birthday>& b) -> void
{
	auto sz = b.size();

	for (size_t i = 0; i < sz; ++i)
	{
		for (size_t j = i + 1; j < sz; ++j)
		{
			if (b[i] == b[j])
			{
				std::cout << std::boolalpha << true << " " << b[i] << " == " << b[j] << "\n\n";
				return;
			}
		}
	}
}

static auto random_val(int min, int max) -> int
{
	static std::random_device rd;
	static std::mt19937 gen{ rd() };
	return std::uniform_int_distribution(min, max)(gen);
}

static auto generate_birthday() -> Birthday
{
	auto mon = static_cast<Month>(random_val(1, 12));
	auto year = random_val(1582, 2025);
	auto day = days_in_month(mon, year);

	return Birthday{ static_cast<int>(mon),random_val(1,day),year };
}

auto main() -> int
{
	try
	{
		std::vector<Birthday> birthdays;

		for (size_t i = 5, max_birthdays = 100; i <= max_birthdays; i += 5)
		{
			std::cout << "n = " << i << "\n\n";

			for (size_t j = 0, max_expiraments = 10; j < max_expiraments; ++j)
			{
				std::cout << "Experiment: " << j + 1 << "\n\n";

				for (size_t k = 0; k < i; ++k)
				{
					birthdays.emplace_back(generate_birthday());
				}

				birthday_paradox(birthdays);
				birthdays.clear();
			}

			std::cout << "\n";
		}
	}

	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what() << "\n";
		return 1;
	}
}