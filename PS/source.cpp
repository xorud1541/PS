#include <iostream>
#include <algorithm>
#include <vector>
#define MAX		500

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int map[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1];

int n;

using namespace std;

int go(int i, int j)
{
	int& ret = dp[i][j];
	if (ret != 0) return ret;

	ret = 1;


	for (int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if (x < 0 || x >= n || y < 0 || y >= n) continue;

		if (map[x][y] <= map[i][j]) continue;

		dp[i][j] = max(dp[i][j], go(x, y) + 1);
	}

	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int ret = go(i, j);
			if (ret > ans)
				ans = ret;
		}
	}

	cout << ans << endl;

	return 0;
}