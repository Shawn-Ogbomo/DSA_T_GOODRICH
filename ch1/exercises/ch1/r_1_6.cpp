int main()
{
	double* dp[10]{};

	for (size_t i = 0; i < 10; i++)
	{
		dp[i] = new double{ 0.0 };
	}

	for (size_t i = 0; i < 10; i++)
	{
		delete dp[i];
	}
}