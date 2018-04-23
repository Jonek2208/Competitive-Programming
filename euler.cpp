#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 1e6+1;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) s

int n, m, a, b;

bool odw[MAXN];
vector<PII> g[MAXN];
VI cykl;

void DFS(int v)
{
	while(!g[v].empty())
	{
		auto w = g[v].back();
		g[v].PP();
		if(!odw[w.ND]) 
		{
			odw[w.ND] = true;
			DFS(w.ST);
		}
	}
	cykl.PB(v);
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	
	FOR(i, 1, m)
	{
		cin>>a>>b;
		g[a].PB(MP(b, i));
		g[b].PB(MP(a, i));
	}
	
	DEBUG(
	FOR(i, 1, n)
	{
		for(auto j: g[i]) cout<<"("<<j.ST<<", "<<j.ND<<") ";
		cout<<endl;
	}
	)
	
	DFS(1);
	REV(i, SIZE(cykl)) cout<<cykl[i]<<" ";
	
	return 0;
}

/*

7 9
1 2
2 3
1 3
2 4
4 5
2 5
7 6
7 3
3 6


*/
