#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;

bool tab[MAXN];
bool wyn = true;
int n, a;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin>>a;
		
		if(a <= n && tab[a] == 0)
		{
			tab[a] = true;
		}
		else
		{
			wyn = false;
			break;
		}
	}
	
	cout << (wyn ? "TAK" : "NIE") << endl;
	return 0;
}
