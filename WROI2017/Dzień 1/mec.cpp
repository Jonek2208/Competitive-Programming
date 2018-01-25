#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 40001;
const int MAXM = 51;
const LL MOD = 1000000007;

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

set<int> g[MAXN];
int n, m;
int tab[MAXN][MAXM];
LL mask[MAXN];

LL ajkc = 1;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	
	REP(k, m)
	{
		FOR(i, 1, n/2)
		{
			cin>>tab[i][k];

		}
		FOR(i, n/2+1, n)
		{
			cin>>tab[i][k];
			mask[tab[i][k]] += (1LL<<k);
		}
	}
	
	sort(mask+1, mask+n+1);
	
	bool flag = true;
	FOR(i, 2, n)
	{
		
		if(mask[i] == mask[i-1])
		{
			flag = false;
			break;
		}
	}
	
	if(flag) cout<<"TAK\n";
	else cout<<"NIE\n";
	
	return 0;
}
