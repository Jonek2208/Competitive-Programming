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

int n, x, y;

int gcdw(int a, int b, LL &l, LL &k)
{
	if(!a)
	{
		l = 0;
		k = 1;
		return b;
	}
	
	int d = gcdw(b%a, a, k, l);
	l-=(b/a)*k;
	return d;
}

int main()
{
	cin>>x>>y;
	LL k, l;
	n = gcdw(x, y, l, k);
	
	cout<<"gcd("<<x<<", "<<y<<") = "<<n<<" = "<<l<<"*"<<x<<" + "<<k<<"*"<<y<<endl;
	

	return 0;
}


