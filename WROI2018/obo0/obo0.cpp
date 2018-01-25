#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef vector<int> VI;

const int INF = 1000000007;
const int MAXN = 501;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define SIZE(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

#define DEBUG(s) 

int m, n, t;
LL res;
int val[MAXN][MAXN];
int state[MAXN][MAXN];
VI osr;
int dif[MAXN*MAXN];

/*konstrukcja grafu*/
inline int nr(int i, int j)
{
	return n*(i-1) + j;
}

inline bool inside(int i, int j)
{
	return (1 <= i && i <= m) && (1 <= j && j <= n);
}

const int dirc = 2;
int dirx[dirc] = {0, 1}, diry[dirc] = {1, 0};


struct Edge
{
	int a, b, c;
	
	Edge() {}
	Edge(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
	
	bool operator <(const Edge &e1) const
	{
		return c < e1.c;
	}
};

vector<Edge> edges;

/*Find Union*/
int p[MAXN*MAXN], r[MAXN*MAXN], rozm[MAXN*MAXN], mx[MAXN*MAXN];

VI listy[MAXN*MAXN];

void Init()
{
	FOR(i, 1, m*n) p[i] = i;
	FOR(i, 1, m*n) rozm[i] = 1;
}

int Find(int x)
{
	if(p[x] != x) p[x] = Find(p[x]);
	return p[x];
}

int Union(int x, int y, int c)
{
	x = Find(x); y = Find(y);
	if(x == y) return 0;
	
	mx[x] = mx[y] = c;
	
	int v = 0; /*nowy ojciec*/
	
	if(r[x] > r[y])
	{
		p[y] = x;
		rozm[x] += rozm[y];
		v = x;
		for(auto i: listy[y]) listy[x].PB(i);
	}
	else
	{
		p[x] = y;
		rozm[y] += rozm[x];
		v = y;
		for(auto i: listy[x]) listy[y].PB(i);
	}
	if(r[x] == r[y]) 
	{
		++r[y];
	}
	
	return v;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>m>>n>>t;
	FOR(i, 1, m) FOR(j, 1, n) cin>>val[i][j];
	FOR(i, 1, m) FOR(j, 1, n) cin>>state[i][j];
	
	if(t == 1)
	{
		cout<<0<<"\n";
		return 0;
	}
	
	/*stworzenie wektorow z osrodkami*/
	FOR(i, 1, m) FOR(j, 1, n) if(state[i][j]) 
	{
		int v = nr(i, j);
		osr.PB(v);
		listy[v].PB(v);
	}
	
	/*!!! robic petle najpierw po m a potem po n !!!*/
	/*stworzenie krawedzi*/
	FOR(i, 1, m)
	FOR(j, 1, n)
	REP(k, dirc)
	{
		int i1 = i + dirx[k], j1 = j + diry[k];
		if(inside(i1, j1))
		{
			edges.PB(Edge(nr(i, j), nr(i1, j1), abs(val[i][j] - val[i1][j1])));
		}
	}
			
	/*sort krawedzi*/
	sort(ALL(edges));
	/*init FU*/
	Init();
	
	DEBUG
	(
	cout<<"\n";
	FOR(i, 1, m) { FOR(j, 1, n) cout<<nr(i, j)<<" "; cout<<"\n"; }
	cout<<endl;
	
	for(auto os: osr) cout<<os<<" ";
	
	cout<<"\n\n";
	for(auto e: edges) cout<<"(("<<e.a<<", "<<e.b<<"), "<<e.c<<")\n";
	cout<<endl;
	)
	
	/*brutu brutu*/
	for(auto e: edges)
	{
		int v = Union(e.a, e.b, e.c);
		
		if(v && rozm[v] >= t)
		{
			while(!listy[v].empty())
			{
				int os = listy[v].back();
				dif[os] = mx[v];
				listy[v].PP();
			}
		}
		
		//~ DEBUG(
		//~ FOR(i, 1, m*n) cout<<p[i]<<" "; cout<<endl;
		//~ FOR(i, 1, m*n) cout<<r[i]<<" "; cout<<endl;
		//~ FOR(i, 1, m*n) cout<<rozm[i]<<" "; cout<<endl;
		//~ FOR(i, 1, m*n) cout<<mx[i]<<" "; cout<<endl<<endl;
		
		//~ FOR(i, 1, m*n)
		//~ {
			//~ cout<<i<<" : ";
			//~ for(auto j: listy[i]) cout<<j<<" "; cout<<endl;
		//~ }
		//~ )
	}	
	
	
	//~ for(auto os: osr) cout<<dif[os]<<" "; cout<<"\n";
	for(auto os: osr) res+=(LL)dif[os];
	
	cout<<res<<"\n";
	
	
	return 0;
}




/*

3 5 10
20 21 18 99 5
19 22 20 16 17
18 17 40 60 80
1 0 0 0 0
0 0 0 0 0
0 0 0 0 1

3 5 10
20 21 18 99 5
19 22 20 16 17
18 17 40 60 80
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1


3 5 1
20 20 20 20 20
20 20 20 20 20
20 20 20 20 20
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1


4 5 9
10 8 10 3 5 
10 4 4 2 7 
4 4 9 6 9 
9 6 2 1 7 
1 1 1 0 0 
0 1 1 0 0 
1 1 1 0 1 
1 0 1 0 1 

4 5 1
10 8 10 3 5 
10 4 4 2 7 
4 4 9 6 9 
9 6 2 1 7 
1 1 1 0 0 
0 1 1 0 0 
1 1 1 0 1 
1 0 1 0 1 


















*/
