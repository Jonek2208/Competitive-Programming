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
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, m, a, b, c, s;
int dist[MAXN], odw[MAXN];

vector<PII> g[MAXN];

struct cmp
{
	bool operator()(const int &a, const int &b) const
	{
		return (dist[a] == dist[b] ? a < b: dist[a] < dist[b]);
	}
};

set<int, cmp> heap;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	
	REP(i, m)
	{
		cin>>a>>b>>c;
		g[a].PB(MP(b, c));
		g[b].PB(MP(a, c));
	}
	
	FOR(i, 1, n)
	{
		dist[i] = INF;
	}
	
	cin>>s;
	odw[s] = -1;
	dist[s] = 0;
	bool change = false;
	
	FOR(i, 1, n-1)
	{
		change = false;
		FOR(v, 1, n)
		{
			for(auto it: g[v])
			{
				int w  = it.ST, l = it.ND;
				if(dist[v] + l < dist[w])
				{
					dist[w] = dist[v] + l;
					odw[w] = v;
					change = true;
				}
			}
		}
		if(!change) 
		{
			cout<<i<<endl;
			break;
		}
	}
	FOR(i, 1, n)
	cout<<i<<" : "<<dist[i]<<" "<<odw[i]<<"\n";
	
	
	
	return 0;
}

/*
6 9
1 6 10
1 3 15
1 4 35
2 6 15
2 3 5
2 5 20
4 5 2
3 4 10
3 5 15




*/


