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

LL tab[MAXN];
int n, k, res;

int main()
{
	cin>>n>>k;
	FOR(i, 1, n)
	{
		cin>>tab[i];
	}
	
	FOR(i, 1, n)
	{
		FOR(j, i+1, n)
		{
			if(tab[i]*tab[j] % k == 0) res++;
		}
	}
	cout<<res<<"\n";
	return 0;
}



