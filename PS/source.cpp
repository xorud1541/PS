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
		if(cmp == pattern) // �����̶� ���� ���
		{
			index = index + pattern.size();
			ans++;
		}
		else // �ƴ� ���
		{
			ans = 1;
			index = index + pattern.size();
			pattern.clear();
			pattern = s.substr(0, index); // ���� ���� 

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