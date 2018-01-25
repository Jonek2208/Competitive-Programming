/*Jonatan Hrynko*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 1001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second


int g[MAXN][MAXN];
int flow[MAXN][MAXN];
int n, m, a, b, c;

bool FAP(int s)
{
	VI kol, odw(n+1, 0), path;
	odw[s] = -1;
	kol.PB(s);
	path.PB(s);
	int mn = INF;
	
	REP(i, SIZE(kol))
	{
		int v = kol[i];
		FOR(j, 1, n)
		{
			if(!odw[j] && g[v][j] > flow[v][j])
			{
				path.PB(j);
				mn = min(mn, g[v][j] - flow[v][j]);
				kol.PB(j);
				odw[j] = v;
			}
		}
	}
	
	if(odw[n])
	{
		int v = n;
		while(v != 1)
		{
			flow[odw[v]][v] += mn;
			flow[v][odw[v]] -= mn;
			v = odw[v];
		}
	}
	
	return odw[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	REP(i, m)
	{
		cin>>a>>b>>c;
		g[a][b] = c;
	}
	
	FOR(i, 1, n)
	FOR(j, 1, n)
	{
		if(g[i][j] && !g[j][i])
		{
			g[j][i] = -g[i][j];
		}
	}
	
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	while(FAP(1));
	
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			cout<<flow[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}

/*
4 6
1 2 11
2 4 1
1 3 1
3 4 20
3 2 1
2 3 10

*/
