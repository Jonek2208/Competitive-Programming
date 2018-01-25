/*************************************************************************
 *                                                                       *
 *                    XXV Olimpiada Informatyczna                        *
 *                                                                       *
 *   Zadanie:              Powodz                                        *
 *   Autor:                Jonatan Hrynko                                *
 *                                                                       *
 *************************************************************************/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MX = 500001;
const LL MOD = 1000000007;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, m, H, a;
int mn;
LL res;

inline int nr(int i, int j)
{
	return n*(i-1) + j;
}

struct Edge
{
	int h, x, y;
	Edge() {}
	Edge(int _h, int _x, int _y) : h(_h), x(_x), y(_y) {}
	
	bool operator<(const Edge &a) const
	{
		return h < a.h;
	}
};

vector<Edge> tab;
LL komb[MX];
int last[MX];

//Find-Union
int p[MX], r[MX];

int Find(int x)
{
	if(x != p[x]) 
	p[x] = Find(p[x]);
	return p[x];
}

void Union(Edge E)
{
	int x = Find(E.x);
	int y = Find(E.y);
	if(x == y) return;
	
	komb[x] += (E.h - last[x]) % MOD;
	komb[y] += (E.h - last[y]) % MOD;
	last[x] = last[y] = E.h;
	
	if(r[x] > r[y])
	{
		p[y] = x;
		komb[x] = (komb[x] * komb[y]) % MOD;
		komb[y] = -1;
	}
	else
	{
		p[x] = y;
		komb[y] = (komb[x] * komb[y]) % MOD;
		komb[x] = -1;
	}
	if(r[x] == r[y]) r[y]++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>m>>n>>H;
	mn = m*n;
	
	FOR(i, 1, m)
	{
		FOR(j, 1, n-1)
		{
			cin>>a;
			tab.PB(Edge(a, nr(i, j), nr(i, j+1)));
		}
	}
	
	FOR(i, 1, m-1)
	{
		FOR(j, 1, n)
		{
			cin>>a;
			tab.PB(Edge(a, nr(i, j), nr(i+1, j)));
		}
	}
	
	sort(ALL(tab));

	//przygotowanie tablic
	FOR(i, 1, mn)
	{
		last[i] = -1;
		p[i] = i;
	}
	
	//przetworzenie krawędzi
	FOREACH(it, tab)
	{
		Union(*it);
	}
	
	FOR(i, 1, mn)
	{
		//dodanie kolejnych kombinacji (do zalania do poziomu H)
		if(komb[i] != -1)
		{
			komb[i] = (komb[i] + (H - last[i]) ) % MOD;
			res = (res + komb[i]) % MOD;
		}
	}
	
	cout<<res<<"\n";
	return 0;
}
