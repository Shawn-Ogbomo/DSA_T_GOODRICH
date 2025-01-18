//R - 2.15 Write a short C++ function that counts the number of vowels in a given
//character string.
#include <string_view>
#include <iostream>
using namespace std::literals;

static auto num_vowels(std::string_view s) -> int
{
	auto sz = s.size();
	auto count = 0;

	for (size_t i = 0; i < sz; ++i)
	{
		switch (s[i])
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
		{
			++count;
			[[fallthrough]];
		}
		default:
			break;
		}
	}

	return count;
}
auto main() -> int
{
	std::cout << num_vowels("Shawn"s) << " "
		<< num_vowels("qweafafaiofhaoinfvaubvaoiwjrqoehirioebtqnj"s) << "\n";
}