#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 1000001;

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

int n, q, a, b;

int tab[MAXN];
int pref[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	FOR(i, 1, n) cin>>tab[i];
	FOR(i, 1, n) pref[i] = pref[i-1] xor tab[i];
	
	//~ FOR(i, 1, n) cout<<tab[i]<<" ";
	//~ cout<<"\n";
	//~ FOR(i, 1, n) cout<<pref[i]<<" ";
	//~ cout<<"\n";
	
	
	REP(i, q)
	{
		cin>>a>>b;
		int res = pref[n] xor (pref[b] xor pref[a-1]);
		cout<<(res ? "NIE" : "TAK")<<"\n";
	}
	return 0;
}
/*
5 2
1 3 4 1 2
2 4
3 4

*/
