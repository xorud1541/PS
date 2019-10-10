#include <iostream>
#include <algorithm>

#define MAX		100000
using namespace std;

int n;
int dp[MAX + 1];

int main()
{
	cin >> n;
	for(int i=0; i<MAX; i++)
		dp[i] = MAX;

	for(int i=1; i*i<n; i++)
		dp[i*i] = 1;

	for(int i=1; i <= n; i++)
	{
		for(int k=1; k*k<i; k++)
		{
			dp[i] = min(dp[i], dp[i - k*k] + 1);
		}
	}

	cout << dp[n] << endl;
	return 0;
}