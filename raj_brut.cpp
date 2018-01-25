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
#define MAXN 500001
#define INF 1000000001

VI g[MAXN];
int n, m, a, b;
int indeg[MAXN];
int sorted[MAXN];
int dp[MAXN];
stack<int> worek;
int x = INF, y, kk;

void toposort()
{
	//obliczanie indeg
	FOR(i, 1, n)
	FOREACH(it, g[i])
	indeg[*it]++;
	
	FOR(i, 1, n)
	if(!indeg[i])
	worek.push(i);
	
	int u, mb = 0;
	
	while(!worek.empty())
	{
		sorted[mb++] = u = worek.top();
		worek.pop();
		FOREACH(it, g[u])
		{
			indeg[*it]--;
			if(!indeg[*it]) worek.push(*it);
		}
	}
	
}

int solve(int v)
{
	int res = 0, u;
	REP(i, n)
	{
		u = sorted[i];
		if(u != v)
		{
			res = max(res, dp[u]);
			FOREACH(it, g[u])
				dp[*it] = max(dp[*it], dp[u]+1);
		}
	}
	
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	
	REP(i, m)
	{
		scanf("%d%d", &a, &b);
		g[a].PB(b);
	}
	
	toposort();
	//REP(i, n)
	//cout<<sorted[i]<<" ";
	//cout<<endl;
	FOR(i, 1, n)
	{
		kk = solve(i);
		//cout<<kk<<" ";
		if(kk < x)
		{
			x = kk;
			y = i;
		}
		FOR(i, 1, n)
		dp[i] = 0;
	}
	
	printf("%d %d", y, x);
	
	
	return 0;
}

