#include <iostream>
#include <vector>
#define MAX		4000000+1
using namespace std;
int n;
vector<int> primes;
vector<int> sumes;
int main()
{
	cin >> n;
	vector<bool> check(MAX, true);
	for (int i = 2; i*i <= n; i++)
	{
		if (!check[i]) continue;
		for (int j = i * i; j <= n; j += i)
		{
			check[j] = false;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (check[i]) primes.push_back(i);
	}

	int sum = 0;
	for (int i = 0; i < primes.size(); i++)
	{
		sum += primes[i];
		sumes.push_back(sum);
	}

	int low = -1;
	int high = 0;
	int ans = 0;

	while(high < primes.size())
	{
		int ret;
		if(low == -1)
		{
			ret = sumes[high];
		}
		else
		{
			ret = sumes[high] - sumes[low];
		}

		if(ret > n)
		{
			low++;
		}
		else if(ret < n)
		{
			high++;
		}
		else
		{//ret == n
			ans++;
			low++;
		}
	}

	cout << ans << endl;
	return 0;
}