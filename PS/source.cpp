#include <iostream>
#include <cstdio>
#define MAX		1000000

int arr[MAX + 1];

int n, m;
using namespace std;

int getParent(int a)
{
	int parent = arr[a];
	if (a == parent)
		return parent;
	else
	{
		return arr[a] = getParent(arr[a]);
	}	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
	}

	while (m--)
	{
		int a, b;
		int flag;
		cin >> flag >> a >> b;

		if (flag == 0) // 합집합
		{
			int x = getParent(a);
			int y = getParent(b);
			if (x != y) //부모가 다르면 합치자
			{
				arr[x] = y;
			}
		}
		else // 포함?
		{
			int x = getParent(a);
			int y = getParent(b);
			if (x != y)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}