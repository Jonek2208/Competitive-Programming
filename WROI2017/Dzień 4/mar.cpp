#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const LL MOD = 1000000007;
const int MAXN = 101;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, m, k, a, b;
LL g[MAXN][MAXN];
LL res[2][MAXN][MAXN];
LL wyn;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	
	REP(i, m)
	{
		cin>>a>>b;
		g[a][b] = 1LL;
		res[0][a][b] = res[1][a][b] = 1LL;
	}
	
	wyn = g[1][n];
	FOR(x, 2, k)
	{
		FOR(i, 1, n)
		FOR(j, 1, n)
		{
			res[x%2][i][j] = 0LL;
			FOR(k, 1, n)
			{
				res[x%2][i][j] += res[(x+1)%2][i][k] * g[k][j];
				res[x%2][i][j] %= MOD;
			}
		}
		
		wyn += res[x%2][1][n];
		wyn %= MOD;
		//~ cout<<res[x%2][1][n]<<" ";
		//~ cout<<wyn<<"\n";
	}
	
	
	cout<<wyn<<"\n";
	return 0;
}

/*
5 7 2
1 5
1 3
3 5
1 4
4 5
2 3
3 4

6 9 1000
1 3
3 6
6 2
2 4
3 5
5 3
4 6
5 6
5 4

6 8 100
1 2
2 3
3 1
2 4
4 5
5 6
4 6
6 4

*/
