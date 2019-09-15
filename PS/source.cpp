#include <iostream>
#include <algorithm>

#define MAX	1000000

using namespace std;

int dp[MAX + 1];
int n;

int go(int n)
{
	if (n == 1)
		return 0;

	int& ret = dp[n];
	if (ret != 0) return ret;

	if (n % 3 == 0 && n - 1 > 0) 
	{
		ret = min(1 + go(n - 1), 1 + go(n / 3));
	}
	else if (n % 2 == 0 && n - 1 > 0)
	{
		ret = min(1 + go(n - 1), 1 + go(n / 2));
	}
	else
	{
		ret = 1 + go(n - 1);
	}

	return ret;
}

int main()
{
	cin >> n;

	cout << go(n) << endl;

	return 0;
}