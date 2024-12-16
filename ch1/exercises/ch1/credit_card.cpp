#include <string>

#include "credit_card.hpp"

CreditCard::CreditCard(const std::string& no, const std::string& nm, int lim, double bal)
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

	balance -= payment;
}