#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
typedef struct _Point
{
	int x;
	int y;
} Point;

vector< Point > points;

int getDist(Point& a, Point& b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool compareX(Point& a, Point& b)
{
	if (a.x != b.x)
		return a.x < b.x;
}

bool compareY(Point& a, Point& b)
{
	if (a.y != b.y)
		return a.y < b.y;
}

int run(int low, int high)
{
	int cnt = high - low + 1;
	if (cnt == 2)
		return getDist(points[low], points[high]);
	if (cnt == 3)
	{
		int mid = low + 1;
		return min({
			getDist(points[low], points[high]),
			getDist(points[low], points[mid]),
			getDist(points[mid], points[high]) }
		);
	}

	int mid = (low + high) / 2;
	int middle = points[mid].x;
	int d = min(run(low, mid), run(mid + 1, high)); // 왼쪽 or 오른쪽

	vector< Point > mids; //중간 후보들
	for (int i = low; i <= high; i++)
	{
		int diff = middle - points[i].x;
		if (diff * diff < d)
			mids.push_back(points[i]);
	}

	sort(mids.begin(), mids.end(), compareY);

	for (int i = 0; i < mids.size(); i++)
	{
		for (int j = i + 1; j < mids.size() && (mids[j].y - mids[i].y) * (mids[j].y - mids[i].y) < d; j++)
		{
			d = min(d, getDist(mids[i], mids[j]));
		}
	}

	return d;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		Point p;
		p.x = x; p.y = y;
		points.push_back(p);
	}

	sort(points.begin(), points.end(), compareX);

	cout << run(0, points.size() - 1) << endl;

	return 0;
}