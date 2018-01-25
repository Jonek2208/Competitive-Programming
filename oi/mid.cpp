/*Midas XXIV OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 1000001;

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

int n, z, x, y;

int g[MAXN][2];
int cost[MAXN];
int odw[MAXN][2];

VI zera;
struct Vertex
{
	int v, a, b;
	Vertex(){}
	Vertex(int _v, int _a, int _b) : v(_v), a(_a), b(_b) {}
	bool operator <(const Vertex v1) const
	{
		return (a == v1.a ? b>v1.b : a > v1.a);
	}
};

priority_queue <Vertex> kol;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n)
	{
		cin>>g[i][0]>>g[i][1];
	}
	
	//zera
	int v = 1;
	
	while(v != 0) 
	{
		zera.PB(v);
		v = g[v][0];
	}
	
	//~ for(int i: zera) cout<<i<<" ";
	//~ cout<<"\n";
	
	int cnt = 1;
	for(int i: zera) 
	{
		cost[i] = cnt;
		if(g[i][1] != 0) kol.push(Vertex(g[i][1], cnt, 1));
	}
	
	int nr, val;
	while(!kol.empty())
	{
		v = kol.top().v;
		val = kol.top().a;
		nr = kol.top().b;
		kol.pop();
		
		if(!odw[val][nr]) cnt++;
		
		odw[val][nr] = cost[v] = cnt;
		
		REP(i, 2)
		{
			if(g[v][i] != 0) kol.push(Vertex(g[v][i], cnt, i));
		}
	}
	
	//~ FOR(i, 1, n) cout<<cost[i]<<" ";
	
	cin>>z;
	REP(i, z)
	{
		cin>>x>>y;
		cout<<(cost[x] >= cost[y] ? "TAK\n" : "NIE\n");
	}
	
	
	return 0;
}
