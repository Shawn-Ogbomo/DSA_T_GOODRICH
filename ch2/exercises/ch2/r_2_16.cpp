//R - 2.16 Write a short C++ function that removes all the punctuation from a string s
//storing a sentence.For example, this operation would transform the string
#include <string>
#include <iostream>
using namespace std::literals;

static auto clear_punct(std::string& s) -> bool
{
	static auto punct_chars = R"(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)"sv;
	static auto sz = punct_chars.size();
	auto sz_s = s.size();

	for (size_t i = 0; i < sz_s; ++i)
	{
		for (size_t j = 0; j < sz; j++)
		{
			if (s[i] == punct_chars[j])
			{
				s[i] = '\0';
			}
		}
	}

	return false;
}

auto main() -> int
{
	try
	{
		std::cout << "Please enter a sentence(s). This program will remove all punctuation characters from the string...\n"
			<< "Press ctrl+z to exit...\n";

		std::cin.exceptions(std::istream::failbit);

		for (auto s = "?"s; std::cin >> s;)
		{
			clear_punct(s);
			std::cout << s << "\n\n";
		}
	}

	catch (const std::ios_base::failure& fail)
	{
		std::cerr << fail.what() << "\n";
		return 1;
	}
}