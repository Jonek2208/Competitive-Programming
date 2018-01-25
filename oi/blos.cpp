/*Blokada XV OI*/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
const int MAXN = 1e5+1;

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

#define DEBUG(s) s

struct Vertex : vector<int>
{
	int odw;
	LL res;
	Vertex() : odw(0), res(0){}
};

Vertex g[MAXN];
LL rozm[MAXN];

int n, m, a, b;

void DFS(int v, int u, int c)
{
	g[v].odw = u;
	rozm[c]++;
	for(auto w: g[v])
	{
		if(g[w].odw!=u)
		{
			DFS(w, u, c);
		}
	}
}

int main()
{
	cin>>n>>m;
	REP(i, m)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	int nr = 0;
	
	FOR(x, 1, n)
	{
		FOR(i, 1, nr) rozm[i] = 0;
		nr = 0;
		g[x].odw = x;
		FOR(i, 1, n)
		{
			if(g[i].odw != x) DFS(i, x, ++nr);
		}
		
		LL res = n*(n-1); 
		FOR(i, 1, nr)
		{
			res-=(LL)(rozm[i]-1)*(LL)rozm[i];
		}
		
		cout<<res<<"\n";
	}
		
	return 0;
}
/*
5 5
1 2
2 3
1 3
3 4
4 5

////
8
8
16
14
8

10 11
1 3
2 4
2 3
3 10
4 6
5 6
6 10
9 10
7 9
7 8
7 10

//////
18
18
34
18
18
34
34
18
18
54

*/
