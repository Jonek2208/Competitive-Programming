/*HLD*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1000000007;
const int MAXN = 1000001;
const int Ml = 1 << 21;
const int M = 1 << 20;

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

int n, q, a, b;

struct Vertex : VI
{
	int rozm, ajkc, odw, nr, d, naj;
	Vertex(): rozm(0), ajkc(0), odw(0), nr(0), d(0), naj(1) {}
};

Vertex g[MAXN];

VI e;
int f[MAXN];

void DFSr(int v, int u)
{
	g[v].rozm = 1;
	f[v] = SIZE(e);
	e.PB(v);
	g[v].odw = u;
	for(auto w: g[v])
	if(w != u)
	{	
		DFSr(w, v);
		g[v].rozm += g[w].rozm;
		if(g[w].rozm > g[g[v].ajkc].rozm) g[v].ajkc = w;
	}
	if(u != -1) e.PB(u);
}

int cnt;

void DFSd(int v, int u)
{
	g[v].nr = ++cnt;
	if(g[v].ajkc)
	{
		g[g[v].ajkc].d = g[v].d + 1;
		g[g[v].ajkc].naj = g[v].naj;
		DFSd(g[v].ajkc, v);
	}
	for(auto w: g[v])
	{
		if(u != w && w != g[v].ajkc)
		{
			g[w].d = g[v].d + 1;
			g[w].naj = w;
			DFSd(w, v);
		}
	}
}

/*LCA*/
int Tree[2*Ml];

void init()
{
	g[0].d = INF;
	REP(i, SIZE(e)) Tree[i+Ml] = e[i];
	FORD(i, Ml-1, 1)
	if(g[Tree[2*i]].d < g[Tree[2*i+1]].d)
	{
		Tree[i] = Tree[2*i];
	}
	else Tree[i] = Tree[2*i+1];
}

int LCA(int a, int b)
{
	a = f[a]; b = f[b];
	if(a > b) swap(a, b);
	a+=Ml; b+=Ml;
	
	int res = 0;
	
	while(a <= b)
	{
		if(a%2 == 1)
		{
			if(g[Tree[a]].d < g[res].d) res = Tree[a];
			++a;
		}
		if(b%2 == 0)
		{
			if(g[Tree[b]].d < g[res].d)
			{
				res = Tree[b];
			}
			--b;
		}
		a/=2; b/=2;
	}
	return res;
}

/*HLD*/
LL HLD[2*M];

void insert(int a, LL v)
{
	a = g[a].nr;
	a+=M;
	HLD[a] += v;
	a/=2;
	
	while(a >= 1)
	{
		HLD[a] = max(HLD[2*a], HLD[2*a+1]);
		//~ HLD[a] += v;
		a/=2;
	}
}

LL hldquery(int a, int b)
{
	
	a = g[a].nr; b = g[b].nr;
	DEBUG(cout<<"d "<<a<<" "<<b<<endl;)
	a+=M; b+=M;
	LL res = 0;
	while(a <= b)
	{
		if(a%2 == 1)
		{
			res = max(res, HLD[a]);
			++a;
		}
		if(b%2 == 0)
		{
			res = max(res, HLD[b]);
			--b;
		}
		a/=2; b/=2;
	}
	return res;
}

LL hldres(int v, int pv)
{
	LL res = hldquery(v, v);
	DEBUG(cout<<pv<<" "<<v<<"\n";)
	while(v != -1 && g[v].d >= g[pv].d)
	{
		
		DEBUG(cout<<pv<<" "<<v<<"\n";)
		if(g[pv].d >= g[g[v].naj].d)
		{
			res = max(res, hldquery(pv, v));
			return res;
		}
		res = max(res, hldquery(g[v].naj, v));
		v = g[v].naj;
		v = g[v].odw;
		
	}
	
	return res;
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
	
	DFSr(1, -1);
	DFSd(1, -1);
	init();
	
	//~ DEBUG(FOR(i, 1, 2*Ml-1) cout<<Tree[i]<<" "; cout<<endl;)
	//~ DEBUG(for(auto i: e) cout<<i<<" ";)
	
	DEBUG(FOR(i, 1, n) cout<<g[i].rozm<<" "; cout<<endl;)
	DEBUG(FOR(i, 1, n) cout<<g[i].ajkc<<" "; cout<<endl;)
	DEBUG(FOR(i, 1, n) cout<<g[i].nr<<" "; cout<<endl;)
	DEBUG(FOR(i, 1, n) cout<<g[i].naj<<" "; cout<<endl;)
	DEBUG(FOR(i, 1, 2*M-1) cout<<HLD[i]<<" "; cout<<endl;)
		
	char znak;
	cin>>q;
	while(q--)
	{
		cin>>znak;
		cin>>a>>b;
		if(znak == 'I')
		{
			insert(a, b);
			DEBUG(FOR(i, 1, 2*M-1) cout<<HLD[i]<<" "; cout<<endl;)
		}
		else
		{
			int p = LCA(a, b);
			DEBUG(cout<<"p "<<p<<endl;)
			
			cout<<max(hldres(a, p), hldres(b, p))<<"\n";
			
		}
	}
	
	
	return 0;
}

/*

4
1 2
2 3
2 4
6
I 1 1
G 1 1
G 3 4
I 2 3
G 1 1
G 3 4

11
1 2
1 4
1 3
5 2
6 2
7 3
7 9
8 6
10 8
11 8
100
I 1 1
I 2 2
I 3 3
I 4 4
I 5 5
I 6 6
I 7 7
I 8 8

6
1 2
1 3
2 4
3 5
1 6




*/




