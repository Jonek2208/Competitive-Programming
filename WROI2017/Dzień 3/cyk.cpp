#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 40001;
const int MAXM = 51;
const LL MOD = 1000000007;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, m, z, a, b;

vector<VI> g;
VI cykl;
VI odw;
VI h;

void DFS(int v, int u)
{
	odw[v] = u;
	cykl.PB(v);
	FOREACH(it, g[v])
	{
		if(!odw[*it]) 
		{
			DFS(*it, v);
		}
		else if(*it != u && *it == cykl[0])
		{
			
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>z;
	
	while(z--)
	{
		cin>>n>>m;
		g.clear();
		g.resize(n+1);
		odw.clear();
		odw.resize(n+1, 0);
		h.clear();
		h.resize(n+1, 0);
		cykl.clear();
		
		REP(i, m)
		{
			cin>>a>>b;
			g[a].PB(b);
			g[b].PB(a);
		}
		
		//~ int cnt = 1;
		
		FOR(i, 1, n)
		{
			if(!odw[i])
			{
				if(DFS(i, -1)) break;
			}
		}
		
		if(cykl.size()>0)
		{
			cout<<"TAK ";
			FOREACH(it, cykl) cout<<*it<<" ";
			cout<<"\n";
		}
		else cout<<"NIE\n";
	
			//~ FOR(i, 1, n)
			//~ {
				//~ cout<<i<<":"<<odw[i]<<" "<<cc[i]<<"\n";
			//~ }
	
			
		
	}
	
	return 0;
}

/*
1
12 15
1 2
2 3
2 4
4 5
1 5
1 9
5 6
6 9
6 7
6 8
8 10
9 10
9 11
10 12
11 12





*/
