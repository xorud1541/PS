#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAX		100
using namespace std;
int n;

std::map<pair<int, int>, int> islands; 
vector< vector<int> > maps(MAX + 1, vector<int>(MAX + 1, 0));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void region(int x, int y, vector< vector<bool> >& visited, int num)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	islands.insert(make_pair(make_pair(x, y), num));

	while(!q.empty())
	{
		pair<int, int> node = q.front();
		q.pop();

		for(int k=0; k<4; k++)
		{
			int nx = node.first + dx[k];
			int ny = node.second + dy[k];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if(!visited[nx][ny] && maps[nx][ny] == 1)
			{
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				islands.insert(make_pair(make_pair(nx, ny), num));
			}
		}
	}
}

int getDis(int x, int y, int num)
{
	int ret = 0; 

	vector< vector<bool> > visited(n, vector<bool>(n, false));
	vector< vector<int> > ans(n, vector<int>(n, 0));
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	visited[x][y] = true;
	bool find = false;

	while(!q.empty())
	{
		pair<int, int> node = q.front();
		q.pop();

		for(int k=0; k<4; k++)
		{
			int nx = node.first + dx[k];
			int ny = node.second + dy[k];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if(maps[nx][ny] == 1 && visited[nx][ny] == false && islands[make_pair(nx, ny)] != num)
			{
				visited[nx][ny] = true;
				ans[nx][ny] = ans[node.first][node.second] + 1;
				ret = ans[node.first][node.second];
				find  = true;
				break;
			}

			if(maps[nx][ny] == 0 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				ans[nx][ny] = ans[node.first][node.second] + 1;
				q.push(make_pair(nx, ny));
			}
		}

		if(find) break;
	}
	return ret;
}

int main()
{
	cin >> n;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> maps[i][j];
		}
	}

	vector< vector<bool> > visited(n, vector<bool>(n, false));
	int num = 1;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(maps[i][j] == 1 && visited[i][j] == false) 
			{
				region(i, j, visited, num); 
				num++;
			}
		}
	}

	int ans = 100 * 100;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(maps[i][j] == 1)
			{
				int num = islands[make_pair(i, j)];
				int ret = getDis(i, j, num);
				if(ret == 0) continue;

				if(ret < ans)
					ans = ret;
			}
		}
	}

	cout << ans << endl;
	return 0;
}