#include <bits/stdc++.h>
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
#define MP make_pair
#define MAXN 1000
#define INF 1000000001
LL dp[MAXN][MAXN];
int tab[MAXN][MAXN];

inline void fastscan(int *a)
{
    register char c=0;
        while (c<33) c=getchar_unlocked();
	    *a=0;
	        while (c>33)
		    {
		            *a=*a*10+c-'0';
			            c=getchar_unlocked();
				    }
}

int main()
{ 
	int z, n, m;
	scanf("%d", &z);
	while(z--)
	{
	scanf("%d%d", &n, &m);
	REP(i, n)
	REP(j, m)
	fastscan(&tab[i][j]);

	//dp
	dp[0][0] = tab[0][0];

	FOR(x, 1, m-1) dp[0][x] = dp[0][x-1] + tab[0][x];
	FOR(x, 1, n-1) dp[x][0] = dp[x-1][0] + tab[x][0];

	FOR(i, 1, n-1)
	FOR(j, 1, m-1)
	{
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + (LL)tab[i][j];
	}
	
	printf("%lld\n", dp[n-1][m-1]);

	}
       return 0;
}

