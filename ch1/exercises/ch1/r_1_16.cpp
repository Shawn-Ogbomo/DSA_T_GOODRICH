//Modify the declaration of the first for loop in the Test class in Code Fragment
//1.4 so that its charges will eventually cause exactly one of the three
//credit cards to go over its credit limit.Which credit card is it ?
//
//answer: CreditCard("6011 4902 3294 2994", "John Bowman", 5000) exceeded its limit

#include <vector>
#include "credit_card.hpp"

static void testCard() {
	std::vector<CreditCard*> wallet{ 10 };

	wallet[0] = new CreditCard("5391 0375 9387 5309", "John Bowman", 2500);
	wallet[1] = new CreditCard("3485 0399 3395 1954", "John Bowman", 3500);
	wallet[2] = new CreditCard("6011 4902 3294 2994", "John Bowman", 5000);

	for (int j = 1; j <= 60; ++j)
	{
		if (!wallet[0]->chargeIt(static_cast<double>(j)))
		{
			std::cout << *wallet[0] << "limit exceeded...\n";
			return;
		}

		if (!wallet[1]->chargeIt(2 * j))
		{
			std::cout << *wallet[1] << "limit exceeded...\n";
			return;
		}

		if (!wallet[2]->chargeIt(static_cast<double>(3 * j)))
		{
			std::cout << *wallet[2] << "limit exceeded...\n";
			return;
		}
	}

	std::cout << "Card payments:\n";

	for (int i = 0; i < 3; ++i)
	{
		std::cout << *wallet[i];

		while (wallet[i]->getBalance() > 100.0)
		{
			wallet[i]->makePayment(100.0);
			std::cout << "New balance = " << wallet[i]->getBalance() << "\n";
		}

		std::cout << "\n";
		delete wallet[i];
	}
}
int main()
{
	testCard();
}