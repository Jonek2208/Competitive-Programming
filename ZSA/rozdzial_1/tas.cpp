#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
const int INF = 1000000009;

int tab[MAXN];
int suma[MAXN];
int n, res = INF;

int main()
{	
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>tab[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		suma[i] = suma[i-1] + tab[i-1];
	}
	
	for(int i = 1; i < n; i++)
	{
		res = min(abs(2*suma[i] - suma[n]), res);
	}
	
	cout<<res<<endl;
	
	return 0;
}
