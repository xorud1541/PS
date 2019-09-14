#include <iostream>
#define MOD		1000000000
#define MAX		100
using namespace std;

long long dp[MAX + 1][10 + 1];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1] % MOD;
			if (j + 1 < 10) dp[i][j] += dp[i - 1][j + 1] % MOD;
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans += dp[n][i];

	cout << ans << endl;
	return 0;
}