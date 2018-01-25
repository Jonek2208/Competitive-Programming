#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 101;

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

int n, m;
int tab[MAXN][MAXN];
int p[MAXN*MAXN], r[MAXN*MAXN];

int Find(int x)
{
	if(p[x] != x)
	p[x] = Find(p[x]);
	return p[x];
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	
	if(x == y) return;	
	if(r[x] > r[y]) p[y] = x;
	else p[x] = y;
	if(r[x] == r[y]) r[y]++;
}

inline int nr(int x, int y)
{
	return (x-1)*n+y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n)
	FOR(j, 1, n)
		cin>>tab[i][j];
		
	FOR(i, 1, n*n) p[i] = i;
		
	FOR(i, 1, n)
	FOR(j, 1, n)
	{
		if(tab[i][j] == 0)
		{
			if(tab[min(n, i+1)][j] == 0)
			Union(nr(i, j), nr(min(n, i+1), j));
			if(tab[i][min(n, j+1)] == 0)
			Union(nr(i, j), nr(i, min(n, j+1)));
			if(tab[max(1, i-1)][j] == 0)
			Union(nr(i, j), nr(max(1, i-1), j));
			if(tab[i][max(1, j-1)] == 0)
			Union(nr(i, j), nr(i, max(1, j-1)));
		}
	}
	
	FOR(i, 1, n)
	FOR(j, 1, n)
	{
		if(tab[i][j] == 0 && (Find(1) != Find(nr(i, j)) )) tab[i][j] = 1;
	}
	
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			cout<<tab[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

