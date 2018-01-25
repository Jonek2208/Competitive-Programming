/*Biura XIII OI*/
#include<bits/stdc++.h>
using namespace std;

const int INF = -1000000001;
const int MAXN = 1000001;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, m, a, b, c;

int p[MAXN], r[MAXN], zlicz[MAXN];

void Init()
{
	FOR(i, 1, n)
		p[i] = i;
}

int Find(int x)
{
	if(p[x] != x) p[x] = Find(p[x]);
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

void Print()
{
	FOR(i, 1, n)
	cout<<Find(i)<<" ";
	cout<<"\n";
}

VI g[MAXN];

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
	
	Init();
	
	FOR(i, 1, n)
	sort(ALL(g[i]));
	
	FOR(i, 1, n)
	{
		int cnt = 1;
		FOREACH(it, g[i])
		{
			while(cnt != *it)
			{
				if(cnt != i)
				{
					cout<<*it<<" ";
					Union(i, *it);
				}
				cnt++;
			}
		}
		cout<<endl;
	}
	
	Print();
	
	return 0;
}
