/*Biedronka i mrówki XII OI*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 5001;
const int MAXK = 1001;
const int MAXL = 501;

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

int n, a, b, k, l;
VI g[MAXN];
int mr[MAXK], prz[MAXK], bd[MAXL];
int ojc[MAXN], odw[MAXN];
VI kol;

void BFS(int s)
{
	ojc[s] = -1;
	kol.PB(s);
	REP(i, SIZE(kol))
	{
		int v = kol[i];
		
		for(int u: g[v])
		{
			if(u != ojc[v]) 
			{
				ojc[u] = v;
				kol.PB(u);
			}
		}
	}
}

void DFS(int v, int f)
{
	odw[v] = f;
	//~ cout<<v<<endl;
	for(int w: g[v])
	{
		if(w != ojc[v] && !odw[w]) DFS(w, f);
	}
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
	
	cin>>k;
	FOR(i, 1, k) cin>>mr[i];
	cin>>l;
	FOR(i, 1, l) cin>>bd[i];
	
	FOR(x, 1, l)
	{
		//czyszczenie
		kol.clear();
		FOR(i, 1, n) odw[i] = ojc[i] = 0;
		
		BFS(bd[x]);
		
		//~ FOR(i, 1, n)
		//~ cout<<i<<":"<<ojc[i]<<"\n";
		
		while(!odw[bd[x]])
		{
			FOR(i, 1, k)
			{
				DFS(mr[i], i);
			}
			
			//~ FOR(i, 1, n)
			//~ cout<<i<<":"<<odw[i]<<"\n";
			
			FOR(i, 1, k)
			{
				int v = mr[i];
				if(v != bd[x] && !odw[ojc[v]])
				{
					mr[i] = ojc[v];
					odw[ojc[v]] = i;
				}
			}
		}
		
		prz[odw[bd[x]]]++;
	}
	
	FOR(i, 1, k)
	{
		cout<<mr[i]<<" "<<prz[i]<<"\n";
	}
	return 0;
}

/*
4
1 2
1 3
2 4
2
1
2
2
2
4


1 0
4 2


*/



