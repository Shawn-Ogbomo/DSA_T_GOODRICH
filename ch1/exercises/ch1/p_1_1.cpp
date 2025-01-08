//A common punishment for school children is to write out the same
//sentence multiple times. Write a C++ stand - alone program that will write
//out the following sentence one hundred times : “I will always use object
//oriented design.” Your program should number each of the sentences and
//it should“ accidentally ” make eight different random - looking typos
//at various points in the listing, so that it looks like a human typed it all by hand
#include <array>
#include <string>
#include <random>
#include <iostream>
#include <algorithm>

static auto random_val(int min, int max) -> int
{
	static std::random_device rd;
	static std::mt19937 gen{ rd() };
	return std::uniform_int_distribution(min, max)(gen);
}

static auto original() -> std::string
{
	return std::string{ "I will always use object oriented design." };
}

auto main() -> int
{
	auto vals = std::array<int, 8>{};

	for (auto& val : vals)
	{
		auto internal_v = random_val(0, 99);

		auto found = std::find(vals.begin(), vals.end(), internal_v);

		while (found != std::end(vals))
		{
			internal_v = random_val(0, 99);

			found = std::find(vals.begin(), vals.end(), internal_v);
		}

		val = internal_v;
	}

	std::sort(vals.begin(), vals.end());

	std::string  sentence = { original() };

	for (size_t i = 0, sz_sentence = sentence.size() - 1; i < 100; ++i)
	{
		if (auto found = std::find(vals.begin(), vals.end(), i); found != std::end(vals))
		{
			sentence[random_val(0, static_cast<int>(sz_sentence))] = static_cast<char>(random_val(97, 122));
		}

		std::cout << i + 1 << ". " << sentence << "\n";
		sentence = original();
	}
}