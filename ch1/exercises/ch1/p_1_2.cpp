//Write a C++ program that, when given a starting day (Sunday through
//Saturday) as a string, and a four - digit year, prints a calendar for that year.
//Each month should contain the name of the month, centered over the dates
//for that month and a line containing the names of the days of the week,
//running from Sunday to Saturday.Each week should be printed on a
//separate line.Be careful to check for a leap year.
#include <ios>
#include <iomanip>
#include <iostream>
using namespace std::literals;

enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class Day
{
	sun = 1, mon, tue, wed, thu, fri, sat
};

static auto operator++(Day& d)->Day&
{
	if (d == Day::sat)
	{
		return d = Day::sun;
	}

	return d = static_cast<Day>(static_cast<int>(d) + 1);
}

static auto string_to_day(std::string& s) -> Day
{
	s[0] = static_cast<char>(std::toupper(s[0]));

	if (s == "Sunday")
	{
		return Day::sun;
	}

	if (s == "Monday")
	{
		return Day::mon;
	}

	if (s == "Tuesday")
	{
		return Day::tue;
	}

	if (s == "Wednesday")
	{
		return Day::wed;
	}

	if (s == "Thursday")
	{
		return Day::thu;
	}

	if (s == "Friday")
	{
		return Day::fri;
	}

	if (s == "Saturday")
	{
		return Day::sat;
	}

	throw std::invalid_argument{ "Invalid day..." };
}

static auto day_10(std::size_t pos, std::ostream& os = std::cout) -> bool
{
	if (pos + 1 == 10)
	{
		os << std::setw(5) << pos + 1;
		return true;
	}

	return false;
}

static auto week_day(Day d, std::size_t pos, std::ostream& os = std::cout) -> bool
{
	if (d != Day::sat && d != Day::sun)
	{
		if (day_10(pos))
		{
			return true;
		}

		os << std::setw(4) << pos + 1;
		return true;
	}

	return false;
}

static auto weekend(Day d, std::size_t pos, std::ostream& os = std::cout) -> bool
{
	if (d == Day::sat)
	{
		if (day_10(pos))
		{
			std::cout << "\n";
			return true;
		}

		os << std::setw(4) << pos + 1 << "\n";
		return true;
	}

	if (d == Day::sun)
	{
		os << pos + 1;
		return true;
	}

	return false;
}

static auto first_row(Day d, std::size_t pos, std::ostream& os = std::cout) -> bool
{
	if (!pos)
	{
		switch (d)
		{
		case Day::sun:
			os << std::setw(0) << pos + 1;
			return true;
		case Day::mon:
			os << std::setw(5) << pos + 1;
			return true;
		case Day::tue:
			os << std::setw(9) << pos + 1;
			return true;
		case Day::wed:
			os << std::setw(13) << pos + 1;
			return true;
		case Day::thu:
			os << std::setw(17) << pos + 1;
			return true;
		case Day::fri:
			os << std::setw(21) << pos + 1;
			return true;
		case Day::sat:
			os << std::setw(25) << pos + 1 << "\n";
			return true;
		default:
			throw std::invalid_argument{ "Invalid day..." };
		}
	}

	return false;
}

static auto display_day(std::size_t pos, Day d) -> void
{
	if (first_row(d, pos))
	{
		return;
	}

	week_day(d, pos);
	weekend(d, pos);
}

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

static auto month_to_string(const Month& m) -> std::string_view
{
	switch (m)
	{
	case Month::jan:
		return "January";
	case Month::feb:
		return "February";
	case Month::mar:
		return "March";
	case Month::apr:
		return "April";
	case Month::may:
		return "May";
	case Month::jun:
		return "June";
	case Month::jul:
		return "July";
	case Month::aug:
		return "August";
	case Month::sep:
		return "September";
	case Month::oct:
		return "October";
	case Month::nov:
		return "November";
	case Month::dec:
		return "December";
	default:
		throw std::invalid_argument{ "Invalid month..." };
	}
}

static auto header(Month m) -> void
{
	auto s = month_to_string(m);

	std::cout << std::setw(12 + s.size()) << s << "\n"
		<< std::setw(27) << std::setfill('-') << "\n" << std::setfill(' ')
		<< "Su" << std::setw(4) << "Mo" << std::setw(4) << "Tu" << std::setw(4) << "We" << std::setw(4)
		<< "Th" << std::setw(4) << "Fr" << std::setw(4) << "Sa" << "\n";
}

static auto display_calendar(std::string& starting_day, int yy) -> void
{
	auto s_d = string_to_day(starting_day);

	for (size_t i = 0, curr_month = static_cast<std::size_t>(Month::jan), months_year = 12; i < months_year; ++i, ++curr_month)
	{
		header(static_cast<Month>(curr_month));

		auto days_m = days_in_month(static_cast<Month>(curr_month), yy);

		for (size_t j = 0; j < days_m; ++j)
		{
			display_day(j, s_d);
			++s_d;
		}
		std::cout << "\n\n";
	}
}

static auto greeting() -> void
{
	std::cout << "Enter a starting day Sun-Sat and a year .\n"
		<< "This program will generate a calendar for the year based on the starting day. \nPress ctrl+z to exit...\n\n";
}

auto main() -> int
{
	greeting();

	std::cin.exceptions(std::istream::failbit);

	while (true) try
	{
		auto s = ""s;
		auto year = 0;

		std::cin >> s >> year;
		display_calendar(s, year);
	}

	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what() << "\n\n";
		return 1;
	}

	catch (const std::ios_base::failure& fail)
	{
		std::cerr << fail.what() << '\n';
		return 2;
	}
}