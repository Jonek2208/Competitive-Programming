#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 500001;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second


struct Vertex : vector<int>
{
	int rmc, ajkc;
	Vertex() : rmc(0), ajkc(0) {}
};

Vertex g[MAXN];

int n, m, a, b;

void DFS(int v, int u)
{
	for(auto w: g[v])
		if(w != u) 
		{
			DFS(w, v);
			g[v].rmc += g[w].rmc + 1;
		}
}

void DFS2(int v, int u)
{
	g[v].ajkc = g[v].rmc;
	
	for(auto w: g[v])
		if(w != u) 
		{
			int val = g[v].rmc - g[w].rmc - 1;
			g[w].rmc += val;
			DFS(w, v);
		}
}



int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	REP(i, n-1)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	DFS(1, -1);
	DFS2(1, -1);
	FOR(i, 1, n)
	cout<<g[i].ajkc<<"\n";
	return 0;
}



