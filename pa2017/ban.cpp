#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 100001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

LL n, q;
LL a, b, c, d;
LL current = 1;

struct Edge
{
	LL e, w, rev;
	Edge(){}
	Edge(LL _e, LL _w, LL _rev) : e(_e), w(_w), rev(_rev) {}
};

vector<Edge> g[MAXN];
LL earn[MAXN], sum[MAXN];

void DFS(LL v, LL u)
{
	for(auto it: g[v])
	{
		if(it.e != u)
		{
			sum[it.e] = sum[v] - it.w;
			DFS(it.e, v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	
	FOR(i, 1, n) cin>>earn[i];
	
	REP(i, n-1)
	{
		cin>>a>>b>>c;
		g[a].PB(Edge(b, c, SIZE(g[b])));
		g[b].PB(Edge(a, c, SIZE(g[a])-1));
	}
	
	REP(x, q)
	{
		cin>>d;
		if(d == 1)
		{
			cin>>a>>b;
			earn[a] = b;
		}
		else
		{
			cin>>a>>b>>c;
			FOREACH(it, g[a])
			if(it->e == b)
			{
				it->w = c;
				break;
			}
			
			FOREACH(it, g[b])
			if(it->e == a)
			{
				it->w = c;
				break;
			}
		}
		
		//~ FOR(i, 1, n)
		//~ {
			//~ cout<<i<<" : ";
			//~ for(auto it: g[i])
			//~ {
				//~ cout<<"("<<it.e<<", "<<it.w<<") ";
			//~ }	
			//~ cout<<"\n";
		//~ }
		
		sum[current] = 0;
		DFS(current, -1);
		LL mx = -INF, ajkc;
		
		FOR(i, 1, n)
		{
			//~ cout<<earn[i] + sum[i]<<" ";
			if(i != current && earn[i] + sum[i] > mx)
			{
				mx = earn[i] + sum[i];
				ajkc = i;
			}
		}
		
		
		
		current = ajkc;
		cout<<current<<" ";
	}
	return 0;
}

/*
4 4
10 20 30 50
1 2 5
2 3 7
2 4 57
1 3 28
1 1 25
2 3 2 1
2 2 4 13

*/
