#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 2e6+1;
const LL MOD = 1e9+7;

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

int n, a, b;

char c;

int place[MAXN];
int rozm[MAXN];
bool cycle[MAXN];
LL possible = 0;

struct Vertex : vector<int>
{
	int odw, cc;
	Vertex(): odw(0), cc(0) {}
};

Vertex g[MAXN];

void edge(int a, int b)
{
	g[a].PB(b);
	g[b].PB(a);
}

void DFS(int v, int u, int nr)
{
	g[v].odw = 1;
	rozm[nr] += (v%2 ? -1 : 1);
	if(v % 2 == 0) place[u/2+1] = v/2;
	
	for(auto w: g[v])
	if(!g[w].odw) DFS(w, v, nr);
	else if(u != w) cycle[nr] = true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	FOR(i, 1, n)
	{
		cin>>c;
		if(c == 'T')
		{
			cin>>a;
			edge(2*i-1, 2*a);
		}
		else
		{
			cin>>a>>b;
			edge(2*i-1, 2*a);
			edge(2*i-1, 2*b);
		}
	}
	
	DEBUG(
	FOR(i, 1, 2*n)
	{
		cout<<i<<" : ";
		for(auto j: g[i]) cout<<j<<" ";
		cout<<"\n";
	}
	)
	
	FOR(i, 1, n);
	
	int flag = 2;
	
	int nr = 0;
	
	FOR(i, 1, n)
	{
		int j = 2*i-1;
		if(SIZE(g[j]) == 1)
		{
			DFS(j, -1, ++nr);
		}
	}
	
	FOR(i, 1, 2*n)
	{
		if(!g[i].odw)
		{
			DFS(i, -1, ++nr);
		}
	}
	
	FOR(i, 1, nr) 
	{
		if(rozm[i] != 0) flag = 0;
		if(cycle[i]) {possible++; flag = 1;}
	}
	
	//~ FOR(i, 1, nr) 
	//~ {
		//~ cout<<rozm[i]<<" "<<cycle[i]<<"\n";
	//~ }
	
	
	if(flag == 2)
	{
		cout<<"TAK\n";
		FOR(i, 1, n) cout<<place[i]<<"\n";
	}
	else
	{
		
		LL res = flag;
		FOR(i, 1, possible) {res*=2; res%=MOD;}
		cout<<"NIE\n"<<res<<"\n";
	}
	return 0;
}
