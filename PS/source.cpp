#include <iostream>
#include <vector>
#include <queue>
#define MAX		100

using namespace std;

bool visited[MAX + 1];
int main()
{
	int num, ssang;
	cin >> num >> ssang;

	vector<int> a[MAX + 1];
	for (int i = 0; i < ssang; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;
	int ans = 1;

	while (!q.empty())
	{
		int ret = q.front();
		q.pop();

		for (int i = 0; i < a[ret].size(); i++)
		{
			int next = a[ret][i];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}