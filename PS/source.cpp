#include <iostream>
#include <algorithm>
#define MAX		300

using namespace std;

int dp[MAX + 1];
int score[MAX + 1];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> score[i];
	}

	dp[1] = score[1];

	for (int i = 2; i <= n; i++)
	{
		if (i == 2)
		{
			dp[2] = score[2] + score[1];
		}
		else if (i == 3)
		{
			dp[3] = max(score[1] + score[3], score[2] + score[3]);
		}
		else
		{
			dp[i] = score[i] + max(dp[i - 3] + score[n - 1], dp[i - 2] + score[n - 1]);
		}
	}

	cout << dp[n] << endl;

	return 0;
}