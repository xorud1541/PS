#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

map<int, int> dp;

int mapToNumber(vector< vector<int> >& map)
{
	string s;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			char c = map[i][j];
			s += c + '0';
		}
	}

	return atoi(s.c_str());
}

pair<int, int> findZero(vector< vector<int> >& map)
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(map[i][j] == 0)
				return make_pair(i, j);
		}
	}
}

void search(vector< vector<int> > map, int start)
{
	int ret = 0;
	bool find = false;
	queue< vector< vector<int> > > q;
	q.push(map);

	while(!q.empty())
	{
		vector< vector< int > > puzzle = q.front();
		q.pop();
		pair<int, int> zero = findZero(puzzle);

		int num = dp[mapToNumber(puzzle)];

		for(int k=0; k<4; k++)
		{
			int nx = zero.first + dx[k];
			int ny = zero.second + dy[k];

			if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

			vector< vector<int> > copyPuzzle(3, vector<int>(3, 0));

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					copyPuzzle[i][j] = puzzle[i][j];
				}
			}

			int temp = copyPuzzle[nx][ny];
			copyPuzzle[nx][ny] = copyPuzzle[zero.first][zero.second];
			copyPuzzle[zero.first][zero.second] = temp;

			int ret = mapToNumber(copyPuzzle);
			if (dp.count(ret) != 0) continue;

			if (ret != 123456780)
			{
				q.push(copyPuzzle);
				dp.insert(make_pair(ret, num + 1));
			}
			else
			{
				dp.insert(make_pair(ret, num + 1));
				find = true;
				break;
			}
		}

		if (find) break;
	}
}
int main()
{
	vector< vector<int> > map(3, vector<int>(3, 0));

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin >> map[i][j];
		}
	}

	int start = mapToNumber(map);
	dp.insert(make_pair(mapToNumber(map), 0));
	search(map, start);

	if (dp.count(123456780) == 0)
		cout << -1 << endl;
	else
		cout << dp[123456780] << endl;
	return 0;
}