#include <iostream>
#include <string>

using namespace std;

int cntPattern(string& s)
{
	int ans = 1;
	string pattern;
	pattern.push_back(s[0]);

	int size = s.size();

	int index = 1;
	while(index < size)
	{
		string cmp = s.substr(index, pattern.size());
		if(cmp == pattern) // 패턴이랑 같은 경우
		{
			index = index + pattern.size();
			ans++;
		}
		else // 아닌 경우
		{
			ans = 1;
			index = index + pattern.size();
			pattern.clear();
			pattern = s.substr(0, index); // 패턴 갱신 

		}
	}

	return ans;
}

int main()
{
	string s;
	while(1)
	{
		cin >> s;
		if(s == ".") break;
		else
		{
			cout << cntPattern(s) << endl;
		}
	}
	return 0;
}