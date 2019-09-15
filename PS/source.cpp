#include <iostream>
#define MAX		11
using namespace std;

int T;
int dp[MAX];

int go(int n)
{
	if (n == 0)
		return 1;
	else if (n < 0)
		return 0;

	int& ret = dp[n];
	if (ret != 0) return ret;

	return ret = go(n - 1) + go(n - 2) + go(n - 3);
}

int main()
{
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;

		cout << go(n) << endl;
	}
	return 0;
}