#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500001;

int tab[MAXN];
int n, a;

int main()
{	
	cin>>n;
	for(int i = 0; i < n-1; i++)
	{
		cin>>a;
		tab[a] = 1;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(tab[i] == 0)
		{
			cout<<i<<endl;
		}
	}
	
	return 0;
}
