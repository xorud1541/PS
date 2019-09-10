#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define MAX		101
using namespace std;
int n;

vector< vector<int> > vecMap(MAX, vector<int>(MAX, 0));
vector< pair<int, int> > islands[100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(pair<int, int> start, vector< vector<bool> >& visited)
{
	int ret = 0;
	bool find = false;
	queue<pair<int, int>> q;
	vector< vector<int> > dis(n, vector<int>(n, 0)); 
	q.push(start);

	while (!q.empty())
	{
		pair<int, int> node = q.front();
		q.pop();
		for(int k=0; k<4; k++)
		{
			int nx = node.first + dx[k];
			int ny = node.second + dy[k];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if(!visited[nx][ny])
			{
				if(vecMap[nx][ny] == 1)
				{
					ret = dis[node.first][node.second] + 1;
					find = true;
					break;
				}
				else
				{
					dis[nx][ny] = dis[node.first][node.second] + 1;
					visited[nx][ny] = true;
				}
			}	
		}

		if(find) break;
	}

	return ret;
}

int getDistance(int index)
{
	int ret = 100 * 100;
	vector< vector<bool> > previsited(n, vector<bool>(n, false));

	for(int i=0; i<islands[index].size(); i++)
	{
		pair<int, int> node = islands[index][i];
		previsited[node.first][node.second] = true;
	}

	for(int i=0; i<islands[index].size(); i++)
	{
		vector< vector<bool> > visited(previsited);
		int dist = bfs(islands[index][i], visited);
		if(dist == 0) continue;

		if(ret > dist)
			ret = dist;
	}
	return ret;
}

void search(int x, int y, int numbering)
{
	vector< vector<bool> > visited(n, vector<bool>(n, false));

	queue< pair<int, int> > q;
	q.push(make_pair(x, y));
	islands[numbering].push_back(make_pair(x,y));
	visited[x][y] = true;

	while(!q.empty())
	{
		pair<int, int> node = q.front();
		q.pop();

		for(int k=0; k<4; k++)
		{
			int nx = node.first + dx[k];
			int ny = node.second + dy[k];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if(vecMap[nx][ny] == 0) continue;

			if(vecMap[nx][ny] == 1 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				islands[numbering].push_back(make_pair(nx, ny));
			}
			
		}
	}
}

int main()
{
	cin >> n;

	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			cin >> vecMap[i][j];
		}
	}

	int numbering = 1;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; n++)
		{
			if(vecMap[i][j] && islands[numbering].size() == 0)
			{
				search(i,j, numbering);
				numbering++;
			}
		}
	}

    int ans = 100 * 100; 
	for(int i=1; i<=numbering; i++)
	{
		int ret = getDistance(i);
		if(ret < ans)
			ans = ret;
	}

	cout << ans << endl;
	return 0;
}