#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define MAXN 1001

int tab[MAXN][MAXN];

int n, q, x, y, k;
char z;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	
	REP(i, q)
	{
		cin>>x>>y>>z;
		
		if(z == 'U')
		{
			for(k = 0; k < y; k++)
			{
				if(tab[x][y-k])
				break;
				tab[x][y-k] = 1;		
			} 
		}
		else
		{
			for(k = 0; k < x; k++)
			{
				if(tab[x-k][y])
				break;
				tab[x-k][y] = 1;
			}
		}
		
		cout<<k<<endl;
		
	}
	return 0;
}

