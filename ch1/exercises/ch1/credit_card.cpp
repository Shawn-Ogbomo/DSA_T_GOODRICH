#include <string>

#include "credit_card.hpp"

CreditCard::CreditCard(std::string_view no, std::string_view nm, int lim, double bal)
	:number{ no },
	name{ nm },
	limit{ lim },
	balance{ bal } {
}

bool CreditCard::chargeIt(double price)
{
	if (price < 0 || price + balance > double(limit))
	{
		return false;
	}

	balance += price;

	return true;
}

void CreditCard::makePayment(double payment)
{
	if (payment < 0)
	{
		return;
	}

	balance -= payment + (payment * (5.45 / 100));
}