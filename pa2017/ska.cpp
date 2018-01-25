#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 1000000;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

LL n, m, a, b;
LL zlicz[MAXN], tab[MAXN];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	m = n;
	REP(i, n) cin>>tab[i];
	
	REP(i, n) zlicz[tab[i]]++;
	
	LL it = 0, mx = 0;
	
	while(m>0)
	{
		mx = it;
		a = zlicz[it] / 2;
		b = zlicz[it] % 2;
		m -= a+b;
		zlicz[it] = b;
		zlicz[++it] += a;
	}
	
	cout<<mx<<"\n";
	
	return 0;
}
