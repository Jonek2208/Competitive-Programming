#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 1e5+1;

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

#define DEBUG(s) 

int n, m, a, b;
VI g[MAXN];
VI gt[MAXN];
VI gscc[MAXN];
int scc[MAXN];
VI post;
int odw[MAXN];

void DFS(int v, int u)
{
	odw[v] = u;
	
	for(auto w: g[v])
	{
		if(!odw[w])
		{
			gt[w].PB(v);
			DFS(w, v);
		}
		else if(u != w)
		{
			gt[v].PB(w);
		}
	}
	
	post.PB(v);
}

void DFS2(int v, int c)
{
	scc[v] = c;
	odw[v] = -2;
	
	for(auto w: gt[v])
	{
		if(odw[w] != -2) DFS2(w, c);
	}
}

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
	
	DFS(1, -1);
	
	int cnt = 0;
	REV(i, SIZE(post))
	{
		if(odw[post[i]] != -2) DFS2(post[i], ++cnt);
	}
	
	FOR(i, 1, n) for(auto j: g[i]) if(scc[i] != scc[j]) 
	{
		gscc[scc[i]].PB(scc[j]);
	}
	
	FOR(i, 1, cnt)
	{
		sort(ALL(gscc[i]));
		auto last = unique(ALL(gscc[i]));
		gscc[i].erase(last, gscc[i].end());
	}
	
	int res = 0;
	FOR(i, 1, cnt) res+=(SIZE(gscc[i]) == 1);
	
	res = res/2 + res%2;
	
	DEBUG(
	FOR(i, 1, n) cout<<i<<" : "<<scc[i]<<"\n";
	
	FOR(i, 1, cnt)
	{
		cout<<i<<" : ";
		for(auto j: gscc[i]) cout<<j<<" ";
		cout<<"\n";
	}
	)
	
	cout<<res<<"\n";
		
	return 0;
}

/*

5 5
1 2
2 3
1 3
3 4
4 5

9 12
1 2
2 9
1 9
1 7
7 8
1 8
1 5
5 6
1 6
1 4
4 3
1 3


6 5
1 2
2 3
1 4
4 5
1 6

14 13
1 14
14 2 
14 4
2 3
3 6
3 7
4 5
5 8
5 9
5 10
5 11
5 12
5 13

6 7
1 2
2 3  
3 1
3 4
4 5
5 6
6 4

9 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
8 9



*/
