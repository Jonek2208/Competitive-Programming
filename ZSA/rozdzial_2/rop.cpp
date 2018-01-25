#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300001;

int n, m, a, licz, wyn = -1;
bool tab[MAXN];

int main()
{
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		cin>>a;
		if(tab[a] == 0)
		{
			licz++;
			tab[a] = 1;
		}
		
		if(licz == n)
		{
			wyn = i+1;
			break;
		}
	}
	
	cout<<wyn<<endl;
	
	return 0;
}
