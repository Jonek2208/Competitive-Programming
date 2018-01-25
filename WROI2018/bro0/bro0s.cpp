/*Choinka Wzglednie Pierwsza*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1000000007;
const int MAXN = 1000001;
const int Ml = 1 << 21;
const int M = 1 << 20;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FOR(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) 

int n, q, a, b;

struct Vertex : VI
{
	int odw;
	Vertex(): odw(0){}
};

Vertex g[MAXN];
int val[MAXN];

void DFS(int v, int u)
{
	odw[v] = u;
	for(auto w: g[v])
	{
		if(!g[v].odw) DFS(w, v);
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
	
	
	
	char znak;
	cin>>q;
	while(q--)
	{
		cin>>znak;
		cin>>a>>b;
		if(znak == 'I')
		{
			val[a] += b;
		}
		else
		{
			FOR(i, 1, n) g[i].odw = 0;
			DFS(a, -1);
			LL res = val[a];
			
			while(b != a)
			{
				res = max(res, b);
			}
			cout<<min(hldres(a, p), hldres(b, p))<<"\n";
			
		}
	}
	
	


	return 0;
}

/*

4
1 2
2 3
2 4
6
I 1 1
G 1 1
G 3 4
I 2 3
G 1 1
G 3 4

11
1 2
1 4
1 3
5 2
6 2
7 3
7 9
8 6
10 8
11 8
100
I 1 1
I 2 2
I 3 3
I 4 4
I 5 5
I 6 6
I 7 7
I 8 8

6
1 2
1 3
2 4
3 5
1 6




*/




