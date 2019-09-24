#include <iostream>
#include <vector>
#include <queue>
#define MAX  50

using namespace std;
int n;
vector<int> nodes[MAX + 1];
bool visited[MAX + 1];
int main()
{
	cin >> n;
	int parent;
	for (int i = 0; i < n; i++)
	{
		int node;
		cin >> node;
		if (node == -1)
		{
			parent = i;
			continue;
		}

		nodes[node].push_back(i);
		nodes[i].push_back(node);
	}

	int drop;
	cin >> drop;

	queue<int> q;
	q.push(parent);
	visited[parent] = true;

	if (parent == drop)
		cout << 0 << endl;
	else
	{
		int ans = 0;
		while (!q.empty())
		{
			int next = q.front();
			q.pop();

			bool isleaf = true;
			for (int i = 0; i < nodes[next].size(); i++)
			{
				int x = nodes[next][i];
				if (!visited[x])
				{
					if (x == drop) continue;

					visited[x] = true;
					q.push(x);
					isleaf = false;
				}
			}

			if (isleaf)
				ans++;
		}

		cout << ans << endl;
	}
	return 0;
}