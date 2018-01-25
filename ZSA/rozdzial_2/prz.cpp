#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;

#define FOR(i, b, e) for(int i = b; i <= e; i++)

int n, m, a, mn, mx;
int tab[MAXN];

int main()
{
	cin>>n>>m;
	FOR(i, 1, m)
	{
		cin>>a;
		if(a == n+1)
		{
			mn = mx;
		}
		else
		{
			tab[a] = max(tab[a], mn) + 1;
			mx = max(mx, tab[a]);
		}
	}
	
	FOR(i, 1, n)
	{
		tab[i] = max(tab[i], mn);
		cout<<tab[i]<<" ";
	}
	
	return 0;
}
