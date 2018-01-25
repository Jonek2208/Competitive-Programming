/*Pokrycie cyklowe*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 3e4+1;

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

#define DEBUG(s) s

int q, n, m, a, b;
vector<VI> g;
vector<VI> gt;
VI scc;
VI post;
VI odw;
VI rozm;

void DFS(int v)
{
	odw[v] = 1;
	
	for(auto w: g[v])
	{
		if(odw[w] != 1) DFS(w);
	}
	
	post.PB(v);
}

void DFS2(int v, int c)
{
	scc[v] = c;
	++rozm[c];
	odw[v] = 2;
	
	for(auto w: gt[v])
	{
		if(odw[w] != 2) DFS2(w, c);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>q;
	while(q--)
	{
		cin>>n>>m;
		g.clear(); g.resize(n+1);
		gt.clear(); gt.resize(n+1);
		scc.clear(); scc.resize(n+1, 0);
		odw.clear(); odw.resize(n+1, 0);
		rozm.clear(); rozm.resize(n+1, 0);
		post.clear();

		REP(i, m)
		{
			cin>>a>>b;
			g[a].PB(b);
			gt[b].PB(a);
		}
		
		FOR(i, 1, n)
		{
			if(odw[i] != 1)
			{
				DFS(i);
			}
		}
		
		int cnt = 0;
		for(auto i: post)
		{
			if(odw[i] != 2) DFS2(i, ++cnt);
		}
		
		bool flag = true;
		
		FOR(i, 1, cnt)
		{
			if(rozm[i] == 1) 
			{
				flag = false;
				break;
			}
		}
		
		if(flag) cout<<"TAK\n";
		else cout<<"NIE\n";
		
	}
	return 0;
}


/*
2
6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 3
5 9
1 2
2 3
3 4
4 1
1 3
3 5
5 1
2 4
4 2
*/
