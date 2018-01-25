#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

const int MAXN = 500*1000+1;

#define FOR(i, b, e) for(int i = b; i<=e; i++)
#define FORD(i, b, e) for(int i = b; i>=e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i!=(c).end(); i++)
#define PB push_back

int n, a, b, m, z;
VI g[MAXN];
int odw[MAXN], son[MAXN];
int del[MAXN];

void DFS(int v, int u)
{
	odw[v] = u;
	
	for(int w: g[v])
	if(w != u) 
	{
		DFS(w, v);
		son[v]++;
	}
}

int main()
{
	ios::sync_with_stdio(0); 
	cin>>n;
	
	REP(i, n-1)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	DFS(1, 0);
	del[0] = 1;
	//debug
	//~ FOR(i, 1, n)
	//~ {
		//~ cout<<i<<" : "<<odw[i]<<" "<<son[i]<<"\n";
	//~ }
	
	int licznik = 1;
	
	cin>>m;
	while(m--)
	{
		cin>>z;
		if(z>0)
		{
			son[odw[z]]--;
			del[z] = 1;

			licznik += son[z] - del[odw[z]];		
			
		}
		else
		{
			son[odw[-z]]++;
			del[-z] = 0;
			
			licznik -= son[-z] - del[odw[-z]];
		}

		cout<<licznik<<"\n";
		
	}	
	
	
	return 0;
}

/*
6
1 2
1 3
1 4
2 5
2 6
8
1
4
2
-4
3
-2
-1
-3

*/
