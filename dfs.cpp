#include<bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define PB push_back

const int MAXN = 500001; //rozmiar grafu + 1

vector<int> g[MAXN];
int d[MAXN], f[MAXN], odw[MAXN], cc[MAXN], low[MAXN];
int n, m, a, b;
int cnt = 1;

void DFS(int v, int u, int c)
{
	odw[v] = u;
	cc[v] = c;
	d[v] = cnt++;
	low[v] = d[v];
	
	for(int w: g[v])
	{
		if(!odw[w])
		{
			DFS(w, v, c);
			low[v] = min(low[v], low[w]);
		}
		else if(w!=u)
		{
			low[v] = min(low[v], d[w]);
		}
		
	}
	
	f[v] = cnt++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i = 0; i < m; i++)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	int ajkc = 0;
	
	FOR(i, 1, n)
	{
		if(!odw[i])
		{
			ajkc++;
			DFS(i, -1, ajkc);
		}
	}
	
	FOR(i, 1, n)
	{
		cout<<i<<" : "<<" d:"<<d[i]<<" f:"<<f[i]<<" ojc:"<<odw[i]<<" c:"<<cc[i]<<"\n";
	}
	
	cout<<"AJKC="<<ajkc<<"\n";
	
	return 0;
}

/*
8 9
1 2
2 4
4 1
3 4
1 3
3 5
5 6
3 8
8 7
 
12 13
1 2
2 4
4 1
3 4
1 3
3 5
5 6
3 8
8 7
9 11
10 11
10 12
11 12

 
*/

