#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 1000001;

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


struct Graph
{
	struct Vertex : vector<int>
	{
		int d, f, s, scc;
		Vertex() : d(0), f(0), s(0) {}
	};
	
	vector<Vertex> g;
	
	void EdgeD(int a, int b)
	{
		g[a].PB(b);
	}
}

int n, m, a, b;
Vertex g[MAXN];
int tmr = 1;

void DFS(int v, int u)
{
	g[v].s = u;
	g[v].d = tmr++;
	for(auto w: g[v])
	{
		if(!g[w].s) DFS(w, v);
	}
	g[v].f = tmr++;
}

int main()
{
	return 0;
}
