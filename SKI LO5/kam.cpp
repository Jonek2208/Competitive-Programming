#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 1001;

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

int u, a, n;
int tab[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin>>u;
	
	while(u--)
	{
		cin>>n;
		FOR(i, 1, n) cin>>tab[i];
		int nimber = 0;
		FOR(i, 1, n) nimber ^= tab[i];
		cout<<nimber<<"\n";
		//~ if(nimber == 0) cout<<"NIE\n";
		//~ else cout<<"TAK\n";
	}
	return 0;
}

