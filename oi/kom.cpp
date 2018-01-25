/*Komiwojażer Bajtazar IX OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 30001;
const int MAXM = 50001;
const int M = (1<<17);

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

int n, m, a, b;

VI g[MAXN];
int mia[MAXM];

int e[2*MAXN], f[MAXN], h[MAXN];
int tree[2*M];

int cnt = 0;
int wys = 0;

void DFS(int v, int u)
{
	f[v] = cnt;
	e[cnt++] = v;
	h[v] = wys++;
	
	for(int w: g[v])
	{
		if(w!=u) DFS(w, v);
	}
	
	e[cnt++] = u;
	wys--;
}

void init()
{
	h[0] = INF;
	REP(i, 2*n-1) tree[i+M] = e[i];
	
	FORD(i, M-1, 1)
	{
		if(h[tree[2*i]] < h[tree[2*i+1]]) tree[i] = tree[2*i];
		else tree[i] = tree[2*i+1];
	}
}

int query(int a, int b)
{
	a+=M; b+=M;
	
	int res = INF;
	while(a<=b)
	{
		if(a%2 == 1) res = min(res, h[tree[a++]]);
		if(b%2 == 0) res = min(res, h[tree[b--]]);
		a/=2; b/=2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	REP(i, n-1)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	DFS(1, -1);
	init();
	
	cin>>m;
	REP(i, m) cin>>mia[i];
	int dl = 0;
	REP(i, m-1)
	{
		dl+=h[mia[i]] + h[mia[i+1]] - 2*query(min(f[mia[i]], f[mia[i+1]]), max(f[mia[i]], f[mia[i+1]]));
	}
	
	cout<<dl<<"\n";
	
	return 0;
}
