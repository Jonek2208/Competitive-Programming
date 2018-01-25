#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 41;
const int MOD = 1000000007;

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
string s1, s2;
map<string, int> mapa;
VI g[MAXN];

int p[MAXN], r[MAXN];


int Find(int x)
{
	if(p[x] != x)
	p[x] = Find(p[x]);
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

SI cc;
map<LL, LL> mask;
int deg[MAXN];
int wlk[MAXN];


int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n)
	{
		cin>>s1;
		mapa[s1] = i;
		p[i] = i;
	}
	
	cin>>m;
	REP(i, m)
	{
		cin>>s1>>s2;
		a = mapa[s1];
		b = mapa[s2];
		g[a].PB(b);
		Union(a, b);
	}
	
	FOR(i, 1, n) 
	{
		p[i] = Find(i);
		wlk[p[i]]++;
		cc.insert(p[i]);
	}
	
	//~ FOREACH(it, cc) cout<<*it<<" ";
	//~ cout<<endl;
	//~ FOR(i, 1, n) cout<<i<<":"<<p[i]<<" ";
	
	//zliczanie outdeg
	FOR(i, 1, n)
	{
		deg[i] = g[i].size();
	}
	
	LL res = 1;
	//dla kazdej spojnej skladowej
	FOREACH(it, cc)
	{
		LL setmask;
		
		FOR(i, 1, n)
		{
			if(p[i] == *it) setmask |= (1LL<<i);
		}
		
		cout<<setmask<<endl;
	}
	
	return 0;
}

/*
5
a b c d e 
3
a b
b c
a c
* 
6 a b c d e f
6
a d d f a e e f a c c f







*/
