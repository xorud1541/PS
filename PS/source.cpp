#include <iostream>

using namespace std;

int main()
{
	long long a, b, v;
	cin >> a >> b >> v;
	long long day = 0;

	if ((v - b) % (a - b) == 0)
		day = (v - b) / (a - b);
	else
		day = (v - b) / (a - b) + 1;

	cout << day << endl;
	
	return 0;
}