/*Blokada XV OI*/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 100001;

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

#define DEBUG(s) 

struct Vertex : vector<int>
{
	int d, low, odw, tree;
	LL res;
	bool artp;
	Vertex() : d(0), low(0), odw(0), tree(0), res(0), artp(0){}
};

Vertex g[MAXN];
int n, m, a, b;

int tmr = 1;

void DFS(int v, int u)
{
	VI skl;
	g[v].tree = 1;
	g[v].odw = u;
	g[v].low = g[v].d = tmr++;
	for(auto w: g[v])
	{
		if(!g[w].odw)
		{
			DFS(w, v);
			g[v].low = min(g[v].low, g[w].low);
			g[v].tree += g[w].tree;
			
			if(g[w].low >= g[v].d) 
			{
				g[v].artp = true;
				skl.PB(g[w].tree);
			}
		}
		else if(w != u)
		{
			g[v].low = min(g[v].low, g[w].d);
		}
	}
	
	g[v].res = (LL)n*(LL)(n-1);
	int rest = n-1;
	if(g[v].artp)
	{
		for(int j: skl) 
		{
			g[v].res -= LL(j)*LL(j-1);
			rest-=j;
		}
	}
	
	g[v].res -= (LL)rest*(LL)(rest-1);
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
	DFS(1, -1);
	DEBUG(
	cout<<"ojce:\n";
	FOR(i, 1, n) cout<<g[i].odw<<" ";
	cout<<"\nlow:\n";
	FOR(i, 1, n) cout<<g[i].low<<" ";
	cout<<"\nrozmiar poddrzewa:\n";
	FOR(i, 1, n) cout<<g[i].tree<<" ";
	cout<<"\nczy jest punktem artykulacji:\n";
	FOR(i, 1, n) cout<<g[i].artp<<" ";
	cout<<"\nwynik:\n";
	)
	FOR(i, 1, n) cout<<g[i].res<<"\n";
	
	
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
