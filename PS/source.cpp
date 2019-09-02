#include <iostream>
#include <vector>
#include <queue>
int n;
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int fill(int height, vector< vector<int> > map /*copy*/ )
{
	int count = 0;
	//fill
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(map[i][j] <= height)
				map[i][j] = 0;
		}
	}

	queue<pair<int, int>> q;
	//count
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(map[i][j] != 0)
			{
				//region check
				q.push(make_pair(i, j));
				while(!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;

					q.pop();

					for(int k=0; k<4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

						if(map[nx][ny] == 0) continue;

						map[nx][ny] = 0;
						q.push(make_pair(nx, ny));
					}
				}

				count++;
			}
		}
	}
	return count;
}

int main()
{
	cin >> n;
	vector< vector<int> > map(n, vector<int>(n, 0));
	int min = 0;
	int max = 101;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> map[i][j];
			if(map[i][j] < min)
				min = map[i][j];
			if(map[i][j] > max)
				max = map[i][j];
		}
	}

	int ret = 0;
	for(int h = min; h <= max; h++)
	{
		int region = fill(h, map);
		if(ret < region)
			ret = region;
	}

	cout << ret << endl;

	return 0;
}