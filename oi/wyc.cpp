/*Wycieczki XXII OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 41;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FOR(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) s

int n, m, k, a, b, c;

int g[MAXN][MAXN][3];

int dp[MAXN][1e6+1];

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	
	REP(i, m)
	{
		cin>>a>>b>>c;
		g[a][b][c-1]++;
	}
	LL sum = 0;
	LL len = 1;
	while(sum < k)
	{
		
	}

	return 0;
}

