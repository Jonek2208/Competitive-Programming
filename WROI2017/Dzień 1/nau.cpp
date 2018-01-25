#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 250001;
const int M = 1 << 18;

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

VI g[MAXN];
int n, q, a, b;
string s;
int cnt = 1;
int odw[MAXN];
int sons[MAXN];

int DFS(int v)
{
	odw[v] = cnt++;
	
	FOREACH(it, g[v])
	{
		if(!odw[*it])
		{
			sons[v]+=DFS(*it)+1;
		}
	}
	
	return sons[v];
}

//drzewo
LL tree[2*M];

void insert(int a, int v)
{
	a+=M;
	while(a >= 1)
	{
		tree[a] += (LL)(v);
		a/=2;
	}
}

LL query(int a, int b)
{
	LL res = 0;
	a+=M; b+=M;
	while(a<=b)
	{
		if(a % 2 == 1) res+=tree[a++]; 
		if(b % 2 == 0) res+=tree[b--];
		a/=2; b/=2;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	
	REP(i, n-1)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	//~ FOR(i, 1, n)
	//~ {
		//~ cout<<i<<" : ";
		//~ FOREACH(it, g[i])
		//~ {
			//~ cout<<*it<<" ";
		//~ }
		//~ cout<<"\n";
	//~ }
	
	DFS(1);
	
	//~ cout<<"Syny:\n";
	//~ FOR(i, 1, n)
	//~ cout<<sons[i]<<" ";
	
	REP(i, q)
	{
		cin>>s;
		
		if(s == "Add")
		{
			cin>>a>>b;
			insert(odw[a], b);
		}
		else if(s == "Count")
		{
			cin>>a;
			cout<<query(odw[a], odw[a] + sons[a])<<"\n";
		}
	}
	
	
	return 0;
}


