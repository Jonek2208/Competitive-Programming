#include <bits/stdc++.h>
using namespace std;

int a, b;

int pot(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n % 2 == 0)
	{
		return pot(a, n / 2) * pot(a, n / 2);
	}
	if (n % 2 == 1)
	{
		return pot(a, n - 1) * a;
	}
}

int main()
{
	cin >> a >> b;
	a = b % a;

	cout << a << " " << b << "\n";

	return 0;
}
