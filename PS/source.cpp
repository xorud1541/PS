#include <iostream>
#include <algorithm>
#define MAX		300

using namespace std;

/*
dp[x][0..2]

- 0 : x��° ����� ��ĭ���� ù��°�� �ö��� ��
- 1 : x��° ����� ��ĭ���� �ι�°�� �ö��� ��
- 2 : x��° ����� ��ĭ���� �ö��� ��
*/
int dp[MAX + 1][3];
int score[MAX + 1];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> score[i];
	}

	dp[1][1] = score[1];

	for(int i=2; i<=n; i++)
	{
		if(i == 2)
		{
			dp[2][1] = score[2] + score[1];
			dp[2][2] = score[2];
		}
		else
		{
			dp[i][1] = score[i] + dp[i-1][2];
			dp[i][2] = score[i] + max(dp[i-2][1], dp[i-2][2]);
		}
	}

	cout << max(dp[n][1], dp[n][2]) << endl;

	return 0;
}