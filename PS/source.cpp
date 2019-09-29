#include <cstdio>
#include <iostream>
#include <queue>
#define MOD 1000000007

using namespace std;
int T;
int main()
{
	scanf_s("%d", &T);

	while (T--)
	{
		int n;
		scanf_s("%d", &n);

		priority_queue<long long> q;
		long long num, temp;

		while (n--)
		{
			scanf_s("%lld", &num);
			q.push(-num);
		}

		int ans = 1;
		while (q.size() > 1)
		{
			temp = q.top(); q.pop();
			temp *= q.top(); q.pop();

			ans = temp % MOD * ans % MOD;

			q.push(-temp);
		}

		printf("%d\n", ans);
	}
	return 0;
}