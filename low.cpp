#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000001;
const int MAXN = 10000;

typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

VI g[MAXN];
int n, m, a, b;
int d[MAXN], low[MAXN];
vector<PII> mosty;
int cnt = 1;

void DFS(int v, int u = -1)
{
	d[v] = low[v] = cnt++;
	
	FOREACH(it, g[v])
	{
		if(d[*it] == 0)
		{
			DFS(*it, v);
			if(low[*it] > d[v])
			{
				mosty.PB(MP(min(v, *it), max(v, *it)));
			}
			else
			low[v] = min(low[v], low[*it]);
		}
		else if(u != *it)
		low[v] = min(low[v], d[*it]);
	}
}

void Bridges()
{
	REP(i, n)
	if(d[i] == 0)
	DFS(i);
}

int main()
{
	cin>>n>>m;
	REP(i, m)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	Bridges();
	
	FOREACH(it, mosty)
	cout<<it->ST<<" "<<it->ND<<endl;
	
	return 0;
}

