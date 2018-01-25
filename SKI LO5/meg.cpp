#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 250001;
const int M = 1 << 18;

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

int n, a, b, m;
char c;

struct Vertex : vector<int>
{
	int odw, d, rozm, h;
	Vertex() : odw(0), d(0), rozm(1), h(0){}
};

Vertex g[MAXN];

int cnt = 0;
void DFS(int v, int u)
{
	g[v].odw = u;
	g[v].d = cnt++;
	
	for(auto w: g[v]) 
	if(!g[w].odw)
	{
		g[w].h = g[v].h+1;
		DFS(w, v);
		g[v].rozm += g[w].rozm;
	}
}

int Tree[2*M];



void insert(int a, int b, int v)
{
	a+=M; b+=M;
	
	while(a <= b)
	{
		if(a%2 == 1) Tree[a++]+=v;
		if(b%2 == 0) Tree[b--]+=v;
		a/=2; b/=2;
	}
}

int query(int a)
{
	a+=M;
	int res = 0;
	while(a >= 1)
	{
		res+=Tree[a];
		a/=2;
	}
	return res;
}

void init()
{
	FOR(i, 1, n) 
	{
		insert(g[i].d, g[i].d, g[i].h);
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
	init();
	//~ FOR(i, 1, n) cout<<i<<" "<<g[i].d<<" "<<g[i].rozm<<" "<<g[i].h<<"\n";
	
	cin>>m;
	
	REP(x, m + n - 1)
	{
		cin>>c;
		if(c == 'A')
		{
			cin>>a>>b;
			if(g[a].d < g[b].d) swap(a, b);
			insert(g[a].d, g[a].d + g[a].rozm - 1, -1);
		}
		else
		{
			cin>>a;
			cout<<query(g[a].d)<<"\n";
		}
	}
	
	
	return 0;
}
/*
5
1 2
1 3
1 4
4 5
4
W 5
A 1 4
W 5
A 4 5
W 5
W 2
A 1 2
A 1 3
*/
