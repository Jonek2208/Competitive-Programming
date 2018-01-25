#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

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
#define MAXN 500

int n, k;
int tab[MAXN];
bool DP[MAXN][MAXN][MAXN];

SI kwoty;

int suma1 = 0, suma2 = 0;

int main()
{
	ios::sync_with_stdio(0);
	
	cin>>n>>k;
	
	FOR(i, 1, n)
		cin>>tab[i];
		
	
	
	DP[0][0][0] = true;
	
	FOR(i, 1, n)
	FOR(x, 0, k)
	FOR(y, 0, k)
	{
		DP[i][x][y] = DP[i-1][x][y];
		if(y >= tab[i]) DP[i][x][y] |= DP[i-1][x][y - tab[i]];
		if(x >= tab[i]) DP[i][x][y] |= DP[i-1][x - tab[i]][y];
	}
	
	FOR(i, 0, k)
	{
		FOR(j, 0, k)
		cout<<DP[n][i][j]<<" ";
		cout<<endl;
	}
	
	//FOR(i, 0, 
	
	//wynik
	
	cout<<kwoty.size()<<endl;
	
	FOREACH(it, kwoty)
	{
		cout<<*it<<" ";
	}
	
	cout<<endl;
	
	
	
	return 0;
}
