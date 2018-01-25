#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 10000001;

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
	int f, s, scc;
	Vertex() : f(0), s(0), scc(0) {}
};

int n, m, a, b;
Vertex g[MAXN], gt[MAXN], gscc[MAXN];
int post[MAXN];
int tmr = 1;

void DFS(int v)
{
	g[v].s = 1;
	for(auto w: g[v]) 
		if(!g[w].s) DFS(w);
	post[tmr++] = v;
}

void DFS2(int v, int nr)
{	
	//~ cout<<"("<<v<<", "<<nr<<")\n";
	gt[v].s = nr;
	gscc[gt[v].scc].s = nr;
	gscc[gt[v].scc].scc = 1;
	
	gt[v].scc = 1;
	for(auto w: gt[v])
		if(gt[w].s == 0) DFS2(w, nr);
		else if(nr > gscc[gt[w].scc].s) gscc[gscc[gt[v].scc].scc].PB(gscc[gt[w].scc].s = nr);
	
	gt[v].scc = nr;
	gscc[gt[v].scc].scc = nr;
}

int main()
{
	cin>>n>>m;
	REP(i, m)
	{
		cin>>a>>b;
		g[a].PB(b);
	}
	
	FOR(i, 1, n) for(int j: g[i]) gt[j].PB(i);
	
	//~ FOR(i, 1, n)
	//~ {
		//~ cout<<i<<" : ";
		//~ for(int j: g[i]) cout<<j<<" ";
		//~ cout<<endl;
	//~ }
	
	//~ cout<<endl;
	
	//~ FOR(i, 1, n)
	//~ {
		//~ cout<<i<<" : ";
		//~ for(int j: gt[i]) cout<<j<<" ";
		//~ cout<<endl;
	//~ }
	
	FOR(i, 1, n)
	{
		if(!g[i].s) DFS(i);
	}
	
	tmr = 0;
	FORD(i, n, 1)
	{
		int v = post[i];
		if(!gt[v].scc) DFS2(v, ++tmr);
	}
	
	//~ cout<<endl;
	FOR(i, 1, tmr)
	{
		cout<<i<<" : ";
		for(auto j: gscc[i]) cout<<j<<" ";
		cout<<endl;
	}
	
	//~ FOR(i, 1, n)
	//~ cout<<gt[i].scc<<"\n";
	
	
	return 0;
}

/*
TEST:

9 16
1 3
3 1
3 2
2 1
8 9
9 4
4 8
7 6
6 5
5 7
8 6
4 5
2 5
3 5
3 7
2 9
*/
