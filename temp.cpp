#include<bits/stdc++.h>

using namespace std;

const int = INF -1000000001;
const int MAXN = 1000001;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

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

int n, m, a, b;
VI g[MAXN];
bool odw[MAXN];

void DFS(int v)
{
	odw[v] = true;
	
	FOREACH(it, g[v])
		if(!odw[*it])
		DFS(*it);
}

int main()
{
	//ios::sync_with_stdio(0);
	cin>>n>>m;
	
	REP(i, m)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	DFS(1);
	
	bool wynik = true;
	
	FOR(i, 1, n)
	if(!odw[i])
	wynik = false;
	
	cout << (wynik ? 
	
	return 0;
}
