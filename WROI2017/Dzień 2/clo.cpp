#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 100001;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, m, a, b;
VI g[MAXN];
int d[MAXN], f[MAXN];
int odw[MAXN];
int sci[MAXN], nxt[MAXN];
int rmc;

int cnt = 1;

void DFS(int v, int u)
{
	//~ cout<<v<<endl;
	d[v] = cnt++;
	odw[v] = u;
	FOREACH(it, g[v])
	{
		if(!odw[*it]) DFS(*it, v);
		else if(*it != u && !rmc) 
		{
			rmc = *it;
			sci[rmc] = v;
			nxt[odw[rmc]] = rmc;	
		}
	}
	
	f[v] = cnt++;
	
	if(d[v] > d[rmc])
	{
		sci[v] = u;
	}
	else if(d[v] < d[rmc])
	{
		sci[v] = nxt[v];
		nxt[odw[v]] = v;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	REP(i, m)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	bool flag = true;
	
	FOR(i, 1, n)
	{
		
		if(!odw[i]) 
		{
			rmc = 0;
			DFS(i, i);
			if(rmc == 0)
			{
				flag = false;
				break;
			}
		}
	}
	
	if(flag)
	{
		cout<<"TAK"<<endl;
		FOR(i, 1, n) cout<<sci[i]<<"\n";
	}
	else
	cout<<"NIE"<<endl;
	
	return 0;
}
