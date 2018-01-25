#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 5e5+7;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) s

int n;
LL tab[MAXN];

priority_queue< pair<int, int> > kopiec;

struct Ver
{
	int l, p;
};

Ver pom[MAXN];
int sorted[MAXN];

LL res = 0;

bool cmp(int a, int b)
{
	return tab[a] < tab[b];
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n) cin>>tab[i];

	FOR(i, 1, n) sorted[i-1] = i;
	
	FOR(i, 1, n)
	{
		pom[i].l = i-1;
		pom[i].p = i+1;
	}
	
	sort(sorted, sorted+n, cmp);
	
	LL minsum = 0;
	REP(i, n-2)
	{
		int v = sorted[i];
		if(pom[v].p == n+1 || pom[v].l == 0)
		{
			res += (LL)(tab[v] - minsum) * (LL)(n-i-2);
			minsum = tab[v];
		}
		else
		{
			res += min(tab[pom[v].p], tab[pom[v].l]) - minsum;
		}
		
		pom[pom[v].l].p = pom[v].p;
		pom[pom[v].p].l = pom[v].l;
	}
	
	cout<<res;
	
	return 0;
}

/*
5
2 2 1 2 2

1 2 3 4 5 6 7

2 2 2 2

0 0 0
 
*/
