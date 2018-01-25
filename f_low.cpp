#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, v) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back

const int MAXN = 10000;

VI g[MAXN];
int preorder[MAXN], postorder[MAXN], low;
int n, m, a, b;
int cl = 0;

void DFS(int v)
{
	low[v] = preorder[v] = cl++;
	
	FOREACH(it, g[v])
	{

	}
	if(!odw[*it])
		DFS(*it, v);

	postorder[v] = cl++;
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

	DFS(1);

	FOR(i, 1, n)
	{
		cout<<odw[i]<<" "<<preorder[i]<<" "<<postorder[i]<<endl;
	}

	return 0;
}
