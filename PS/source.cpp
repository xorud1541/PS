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

	
	return 0;
}