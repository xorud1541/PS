#include <iostream>
#include <algorithm>

#define MAX		100000

int dp[MAX + 1];
int n;

using namespace std;

int main()
{
	cin >> n;

	for (int i = 1; i*i <= n; i++)
		dp[i * i] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (dp[i] == 0) dp[i] = i;
		for (int k = 1; k*k < i; k++)
		{
			dp[i] = min(dp[i], dp[i - k * k] + 1);
		}
	}

	cout << dp[n] << endl;
	return 0;
}