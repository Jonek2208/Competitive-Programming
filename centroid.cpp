#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int N = 1e5+1;

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

#define DEBUG(s) s

int n, a, b, c;

vector<int> g[N];
vector<int> ctree[N];

void make_edge(int a, int b)
{
	g[a].PB(b);
	g[b].PB(a);
}

int rozm[N];
bitset<N> fin;

int cnt;

void DFS(int v, int u)
{
	rozm[v] = 1;
	for(auto w: g[v])
	{
		if(w != u && !fin[w]) 
		{
			DFS(w, v);
			rozm[v] += rozm[w];
		}
	}
}

int centroid(int v, int s)
{
	bool flag = true;
	int mx = -1;
	
	for(auto w: g[v])
	{
		if(!fin[w] && rozm[w] > s/2)
		{
			flag = false;
			mx = w;
			break;
		}
	}
	
	if(flag) 
	{
		fin[v] = true;
		return v;
	}
	int tmp = rozm[v] - rozm[mx];
	rozm[mx] = rozm[v];
	rozm[v] = tmp;
	return centroid(mx, s);
}

void centroid_decomp(int v, int u)
{
	cout<<v<<" "<<u<<"\n";
	DFS(v, -1);
	FOR(i, 1, n) cout<<rozm[i]<<" ";
	int x = centroid(v, rozm[v]);
	cout<<x<<" "<<u<<"\n";
	
	ctree[u].PB(x);
	ctree[x].PB(u);
	
	for(auto w: g[x])
	{
		if(!fin[w]) centroid_decomp(w, x);
	}
	
}

int main()
{
	//~ ios::sync_with_stdio(0);
	cin>>n;
	
	REP(i, n-1)
	{
		cin>>a>>b;
		make_edge(a, b);
	}
	
	centroid_decomp(1, 0);
	
	FOR(i, 0, n)
	{
		cout<<i<<" : ";
		for(auto j: ctree[i]) cout<<j<<" ";
		cout<<"\n";
	}
	
	return 0;
}

/*

15
1 2
2 3
2 4
2 5
5 6
6 7
5 8
8 9
9 10
10 11
10 12
9 13
13 14
13 15

*/
