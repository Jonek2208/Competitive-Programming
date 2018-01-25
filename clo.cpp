#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 100001;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

struct Vertex : vector<int>
{
	int odw, odw2, cc, dir;
	Vertex() : odw(0), odw2(0), cc(0), dir(0){}
};

Vertex g[MAXN];
int root[MAXN], ajkc[MAXN];

void DFS(int v, int u, int c)
{
	g[v].odw = u;
	g[v].cc = c;
	
	for(int w: g[v])
	{
		if(!g[w].odw) DFS(w, v, c);
		else if(u != w)
		{
			root[c] = v;
			ajkc[c] = w;
		}
	}
}

void DFS2(int v, int u)
{
	g[v].odw2 = u;
	for(int w: g[v])
	if(!g[w].odw2) DFS2(w, v);
	
	if(u == -1) g[v].dir = ajkc[g[v].cc];
	else g[v].dir = u;
}

int n, m, a, b;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	REP(i, m)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	int cnt = 0;
	
	FOR(i, 1, n)
	{
		if(!g[i].odw)
		{
			DFS(i, -1, ++cnt);
			if(!ajkc[cnt])
			{
				cout<<"NIE\n";
				return 0;
			}
		}
	}
	
	FOR(i, 1, cnt)
	{
			DFS2(root[i], -1);
	}
	
	cout<<"TAK\n";
	FOR(i, 1, n) cout<<g[i].dir<<"\n";
	
	return 0;
}
