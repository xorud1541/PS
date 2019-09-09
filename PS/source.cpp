#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

map<int, bool> dp;

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

bool valid(vector< vector<int> >& map)
{
	int arr[3][3] =
	{
		{ 1, 2, 3},
		{ 4, 5, 6},
		{ 7, 8, 0}
	};

	bool ret = true;

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(map[i][j] != arr[i][j])
			{
				ret = false;
				break;
			}
		}
	}

	return ret;
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

int search(vector< vector<int> > map, int start)
{
	int ret = 0;
	bool find = false;
	queue< vector< vector<int> > > q;
	q.push(map);

	while(!q.empty())
	{
		vector< vector< int > > temp = q.front();
		q.pop();
		pair<int, int> zero = findZero(temp);

		for(int k=0; k<4; k++)
		{
			int nx = zero.first + dx[k];
			int ny = zero.second + dy[k];

			if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

			int t = temp[nx][ny];
			temp[nx][ny] = temp[zero.first][zero.second];
			temp[zero.first][zero.second] = t;

			if(dp.count(mapToNumber(temp)) != 0) continue;

			if(!valid(temp))
			{
				q.push(temp);
			}
			else
			{
				find = true;
				break;
			}
		}

		ret++;
		if(find) break;
	}

	return ret; 
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
	dp.insert(make_pair(mapToNumber(map), true));
	int min = search(map, start);

	cout << min << endl;
	return 0;
}