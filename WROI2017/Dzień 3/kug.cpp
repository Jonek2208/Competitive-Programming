#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
const int MAXN = 2001;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back

int n;
LL tab[MAXN][MAXN];

struct Price
{
	Price(){}
	Price(LL _c, int _x, int _y) : c(_c), x(_x), y(_y) {}
	LL c;
	int x, y;
	
	bool operator<(const Price &a) const
	{
		return c < a.c;
	}
};

int p[MAXN], r[MAXN];

int Find(int x)
{
	if(p[x]!=x) p[x] = Find(p[x]);
	return p[x];
}

void Union(int x, int y)
{
	x = Find(x); y = Find(y);
	if(x == y) return;
	if(r[x] > r[y]) p[y] = x;
	else p[x] = y;
	if(r[x] == r[y]) r[y]++;
}

vector<Price> kk;
LL res;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	FOR(i, 1, n)
	FOR(j, i, n)
	{
		cin>>tab[i][j];
		kk.PB(Price(tab[i][j], i, j+1));
	}
	
	sort(ALL(kk));
	FOR(i, 1, n) p[i]=i;
	
	FOREACH(it, kk)
	{
		if(Find(it->x) != Find(it->y))
		{
			Union(it->x, it->y);
			res+=it->c;
		} 
	}
	
	cout<<res<<"\n";
	
	return 0;
}
