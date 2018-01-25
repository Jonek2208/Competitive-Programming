#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 100001;
const int SQR = 320;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, m, a, b, c;


struct {int a, b, c;} kan[MAXN];
int tab[MAXN];
LL sum[MAXN];
LL pref[SQR+1][MAXN];
bitset<MAXN> app;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	FOR(i, 1, n) cin>>tab[i];
	FOR(i, 1, m) 
	{
		cin>>kan[i].a>>kan[i].b>>kan[i].c;
		app[kan[i].c] = 1;
	}
	
	int sqr = ceil(sqrt(n));
	
	FOR(k, 1, sqr)
	{
		if(app[k])
		{
			FOR(i, 1, n)
			{
				pref[k][i] = tab[i] + (i > k ? pref[k][i-k] : 0);
			}
		}
	}
	
	FOR(k, 1, m)
	{
		if(kan[k].c >= sqr)
		FOR(i, 0, kan[k].b)
		{
			int pos = i * kan[k].c + kan[k].a;
			sum[k] += tab[pos];
		}
		else
		{
			sum[k] = pref[kan[k].c][kan[k].a + kan[k].c * kan[k].b] - pref[kan[k].c][kan[k].a] + tab[kan[k].a];
		}
	}
	
	FOR(i, 1, m) cout<<sum[i]<<"\n";
	
	return 0;
}


/*
5 2
1 2 3 4 5
1 2 2
2 1 2
*/





