/*Zwiedzanie Bajtogrodu*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int MAXN = 1000001;

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

int n, m, a, b;

VI cykl;

struct Vertex : VI
{
	int odw, last;
	Vertex(): last(0) {}
};

Vertex g[MAXN];
Vertex d[MAXN];

int tmr;

void DFSc(int v, int u)
{
	g[v].last = ++tmr;
	
	for(auto w: g[v])
	{
		if(!g[w].last)
		{
			d[v].PB(w);
			DFSc(w, v);
		}
		else if(u != w)
		{
			if(g[w].last < g[v].last) d[w].PB(v+MAXN);
		}
	}
}

int DFSt(int v, int u)
{	
	int syny = 0;
	if(v < MAXN)
	for(auto w: d[v])
	{
		if(w != u)
		{
			++syny;
			int res = DFSt(w, v);
			
			if(res)
			{
				--syny;
				cykl.PB(d[w].last);
				cykl.PB(w);
				cykl.PB(v);
			}
			else if(syny > 0 && syny%2==0) 
			{
				cykl.PB(d[v].last);
				cykl.PB(v);
				cykl.PB(w);
			}
			else
			{
				d[v].last = w;
			}
		}
	}
	
	return syny%2;
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
	
	/*nieparzysta ilosc krawedzi*/
	if(m % 2 == 1)
	{
		cout<<"NIE\n";
		return 0;
	}
	
	DFSc(1, -1);
	
	FOR(i, 1, n) g[i].clear();
	
	DEBUG(
	FOR(i, 1, n)
	{
		cout<<i<<" : ";
		for(auto j: d[i]) cout<<j<<" ";
		cout<<endl;
	}
	
	)
	

	cout<<"TAK\n";
	DFSt(1, -1);
	for(int i = 2; i < SIZE(cykl); i+=3) cout<<cykl[i-2]%MAXN<<" "<<cykl[i-1]%MAXN<<" "<<cykl[i]%MAXN<<"\n";
	return 0;
	
	return 0;
}

/*

8 12
1 2
2 3
3 4
4 1
1 3
2 4
3 5
3 6
5 6
6 7
6 8
7 8


5 5
1 2
2 3
3 4
4 5
1 3

7 8
1 2
2 3
3 4
1 4
3 7
3 5
5 6
7 6

euler

12 16
1 2
1 3
2 6
3 6
4 6
4 5
5 6
6 7
7 8
6 8
6 9
9 10
10 6
6 11
11 12
12 6

drzewo

13 12
10 4
4 5
4 9
5 6
5 8
5 7
10 3
3 2
3 11
3 12
12 1
12 13

cykl maly
6 10
1 2
2 4
3 4
1 3
1 4
4 5
5 6
6 7
4 7
4 6


*/
    
