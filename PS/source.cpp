#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
set<pair<int, int>> set_;
int m, n;

bool PushBox(char dir, int x, int y, vector<vector<char>>& map)
{
	int nx, ny;
	if (dir == 'U')
	{
		nx = x + dx[0];
		ny = y = dy[0];
	}
	else if (dir == 'L')
	{
		nx = x + dx[1];
		ny = y + dy[1];
	}
	else if (dir == 'R')
	{
		nx = x + dx[2];
		ny = y + dy[2];
	}
	else
	{
		nx = x + dx[3];
		ny = y + dy[3];
	}

	if (nx < 0 || nx >= m || ny < 0 || ny >= n) return false;

	if (map[nx][ny] == '.') return true;
	else
		return false;
}

pair<int, int> Move(int dir, int x, int y, vector<vector<char>>& map)
{
	int nx, ny;
	if (dir == 'U')
	{
		nx = x + dx[0];
		ny = y + dy[0];
	}
	else if (dir == 'L')
	{
		nx = x + dx[1];
		ny = y + dy[1];
	}
	else if (dir == 'R')
	{
		nx = x + dx[2];
		ny = y + dy[2];
	}
	else
	{
		nx = x + dx[3];
		ny = y + dy[3];
	}
	
	if (nx < 0 || nx >= m || ny < 0 || ny >= n) return make_pair(x, y);

	char next = map[nx][ny];
	if (next == '#') //벽
	{
		return make_pair(x, y);
	}
	else if (next == 'b')
	{
		if (PushBox(dir, nx, ny, map))
		{
			if (set_.count(make_pair(nx, ny)) != 0)
			{
				map[nx][ny] = 'B';
			}
			else
			{
				map[nx][ny] = 'b';
			}
			return make_pair(nx, ny);
		}
		else
			return make_pair(x, y);
	}
	else if (next == 'B')
	{
		if (PushBox(dir, nx, ny, map))
		{
			if (set_.count(make_pair(nx, ny)) != 0)
			{
				map[nx][ny] = 'B';
			}
			else
			{
				map[nx][ny] = 'b';
			}
			return make_pair(nx, ny);
		}
		else
			return make_pair(x, y);
	}
	else if (next == '+')
	{
		return make_pair(nx, ny);
	}
	else if (next == '.')
	{
		return make_pair(nx, ny);
	}
}

int main()
{
	while (1)
	{
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		vector< vector<char> > map(m, vector<char>(n, 0));
		int startX = 0;
		int startY = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '+')
				{
					set_.insert(make_pair(i, j));
				}
				else if (map[i][j] == 'B')
				{
					set_.insert(make_pair(i, j));
				}
				else if (map[i][j] == 'W')
				{
					set_.insert(make_pair(i, j));
					startX = i; startY = j;
				}
				else if (map[i][j] == 'w')
				{
					startX = i; startY = j;
				}
				else
					continue;
			}
		}

		string dirs;
		cin >> dirs;

		for (int i = 0; i < dirs.size(); i++)
		{
			char dir = dirs[i];
			pair<int, int> pos = Move(dir, startX, startY, map);

			if (pos.first == startX && pos.second == startY) continue; //같은 위치인 경우

			if (set_.count(pos) != 0) // + 위에 있을 경우
			{
				if (map[startX][startY] == 'W')
				{
					map[startX][startY] = '+';
					map[pos.first][pos.second] = 'W';
				}
				else
				{
					map[startX][startY] = '.';
					map[pos.first][pos.second] = 'W';
				}
			}
			else
			{
				if (map[startX][startY] == 'W')
				{
					map[startX][startY] = '+';
					map[pos.first][pos.second] = 'w';
				}
				else
				{
					map[startX][startY] = '.';
					map[pos.first][pos.second] = 'w';
				}
			}

			startX = pos.first;
			startY = pos.second;
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << map[i][j];
			}
			printf("\n");
		}

		dirs.clear();
		set_.clear();
		map.clear();
	}
	return 0;
}