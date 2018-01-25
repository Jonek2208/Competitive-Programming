+#include<bits/stdc++.h>
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

struct Vertex : vector<int>
{
	int odw;
	Vertex(): odw(0) {}
};

int n, m, a, b;

Vertex g[MAXN];
int wys[MAXN];

VI bs;


void DFS(int v, int h)
{
	g[v].odw = h;
	for(auto w: g[v])
	if(g[w].odw != h && wys[w] <= h) DFS(w, h);
}



int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	
	FOR(i, 1, n) cin>>wys[i];
	
	REP(i, m)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	FOR(i, 1, n) bs.PB(wys[i]);
	
	sort(ALL(bs));
	
	//~ for(int it: bs) cout<<it<<" ";
	//~ cout<<"\n";
	
	int res = INF;
	
	int poc = 0, kon = n-1, sr, h;
	
	while(poc <= kon)
	{
		sr = (poc + kon)/2;
		h = bs[sr];
		DFS(1, h);
		//~ FOR(i, 1, n) cout<<g[i].odw<<" ";
		//~ cout<<"\n";
		if(g[n].odw == h)
		{
			res = h;
			kon = sr-1;
		}
		else
		{
			poc = sr+1;
		}
	}
	
	cout<<res<<"\n";
	
	
	return 0;
}

/*
9 11
3
10
9
6
8
3
2
4
1
1 2
1 3
7 1
4 1
4 6
5 3
6 7
7 8
8 9
6 9
5 9


*/

