/*Dostawca pizzy XXIV OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 1e5+1;
const int M = 1<<17;

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

#define DEBUG(s) 

int n, k, a, b, c;

vector<PII> g[MAXN];
int ojc[MAXN], rozm[MAXN], preorder[MAXN], edge[MAXN];
bool odw[MAXN];
LL cost[MAXN];
LL res;

int cnt;

void DFS(int v, int u)
{
	preorder[v] = ++cnt;
	ojc[preorder[v]] = (v == 1 ? -1 : preorder[u]);
	rozm[preorder[v]] = 1;
	
	for(auto w: g[v]) if(w.ST != u)
	{
		edge[cnt+1] = w.ND;
		cost[cnt+1] = cost[preorder[v]] + edge[cnt+1];
		DFS(w.ST, v);
		rozm[preorder[v]] += rozm[preorder[w.ST]];
	}
}

struct Node
{
	int nr;
	LL wait, mx;
};

Node Tree[2*M];

void init()
{
	FOR(i, 1, n)
	{
		Tree[i+M].mx = cost[i];
		Tree[i+M].nr = i;
		Tree[i+M].wait = 0;
	}
	
	FORD(i, M-1, 0)
	{
		int tmp = (Tree[2*i].mx > Tree[2*i+1].mx ? 2*i : 2*i+1);
		Tree[i].mx = Tree[tmp].mx;
		Tree[i].nr = Tree[tmp].nr;
	}
}

void insert(int a, int b, int v, int x, int y, int u)
{
	if(u < M)
	{
		Tree[u].mx += Tree[u].wait;
		Tree[2*u].wait += Tree[u].wait;
		Tree[2*u+1].wait += Tree[u].wait;
		Tree[u].wait = 0;
	}
	
	if(b < x || y < a) return;
	if(a <= x && y <= b)
	{
		Tree[u].wait += v;
		return;
	}
	
	int d = (x+y)/2;
	
	insert(a, b, v, x, d, 2*u);
	insert(a, b, v, d+1, y, 2*u+1);
	int tmp = (Tree[2*u].mx + Tree[2*u].wait > Tree[2*u+1].mx + Tree[2*u+1].wait ? 2*u : 2*u+1);
	Tree[u].mx = Tree[tmp].mx + Tree[tmp].wait;
	Tree[u].wait = 0;
	Tree[u].nr = Tree[tmp].nr;
}

void insert(int a, int b, int v)
{
	insert(a, b, v, 0, M-1, 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	REP(i, n-1)
	{
		cin>>a>>b>>c;
		g[a].PB(MP(b,c));
		g[b].PB(MP(a,c));
	}
	

	odw[1] = true;
	DFS(1, -1);
	init();
	
	FOR(i, 1, n) res+=2*edge[i];
	
	REP(kk, k)
	{
		int v = Tree[1].nr;
		if(Tree[1].mx+Tree[1].wait <= 0) break;
		
		res-=Tree[1].mx+Tree[1].wait;
		while(!odw[v])
		{
			insert(v, v+rozm[v]-1, -(2*edge[v]));
			odw[v] = true;
			v = ojc[v];
		}
		
	}
	
	cout<<res<<"\n";
	return 0;
}

/*

7 3
1 2 5
2 3 11
2 4 2
5 2 6
1 6 1 
7 1 1 


7 5
1 2 5
2 3 11
2 4 2
5 2 6
1 6 1 
7 1 1 

7 5
1 5 5
5 3 11
5 4 2
2 5 6
1 6 1 
7 1 1 

*/
