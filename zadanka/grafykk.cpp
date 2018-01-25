#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000001;
const int MAXN = 100000;

typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

vector<int> g[MAXN];
int n, m, a, b;

int preorder[MAXN], postorder[MAXN], inorder[MAXN];
int odw[MAXN];
int licznik = 0;

void DFS(int v, int w)
{
	odw[v] = w;
	preorder[v] = licznik++;
	for(int i = 0; i < g[v].size(); i++)
	if(!odw[g[v][i]])
		DFS(g[v][i], v);
		
	postorder[v] = licznik++;
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
	
	FOR(i, 1, n)
	{
		cout<<i<<" : ";
		REP(j, g[i].size())
		cout<<g[i][j]<<" ";
		
		cout<<endl;
	}
	
	DFS(1, -1);
	
	FOR(i, 1, n)
	{
		cout<<i<<" preorder: "<<preorder[i]<<" postorder: "<<postorder[i]<<" ojciec: "<<odw[i]<<endl;
	}
	return 0;
}
