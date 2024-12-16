//code segment 1.3 dsa_t_goodrich
#ifndef CREDIT_CARD_HPP
#define CREDIT_CARD_HPP
#include <string>
#include <iostream>

class CreditCard
{
public:
	CreditCard(const std::string& no, const std::string& nm, int lim, double bal = 0);
	friend std::ostream& operator<<(std::ostream& out, const CreditCard& c)
	{
		out << "Number = " << c.number << "\n"
			<< "Name = " << c.name << "\n"
			<< "Balance = " << c.balance << "\n"
			<< "Limit = " << c.limit << "\n";
		return out;
	}

	std::string getNumber() const
	{
		return number;
	}

	std::string getName() const
	{
		return name;
	}

	double getBalance() const
	{
		return balance;
	}

	int getLimit() const
	{
		return limit;
	}

	bool chargeIt(double price);

	void makePayment(double payment);
private:
	std::string number;
	std::string name;
	int limit{};
	double balance{};
};
#endif // CREDIT_CARD_HPP