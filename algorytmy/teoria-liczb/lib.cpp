#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 10000001;

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

/*gcd*/
LL gcd(LL a, LL b)
{
	while(b) swap(a%=b, b);
	return a;
}

/*gcd rozszerzony*/
LL gcdr(LL a, LL b, LL &k, LL &l)
{
	if(b == 0)
	{
		k = 1;
		l = 0;
		return a;
	}
	
	LL d = gcdr(b, a%b, l, k);
	l -= (a/b) * k;
	return d;
}

/*odwrotnosc modularna*/

LL invmod(LL a, LL m)
{
	LL x, y, d = gcdr(a, m, x, y);
	if(d == 1) return (x%m+m)%m;
	else return -1;
}

/*potegowanie*/
LL pot(LL a, LL b)
{
	LL p = 1;
	while(b)
	{
		if(b%2 == 1) p *=a;
		a *= a; 
		b/=2;
	}
	return p;
}

/*potegowanie modularne*/
LL potmod(LL a, LL b, LL m)
{
	LL p = 1;
	while(b)
	{
		if(b%2 == 1) p = (p * a) % m;
		a = (a * a) % m;
		b/=2;
	}
	return p;
}


LL a, b;

int main()
{
	cin>>a>>b;
	cout<<gcd(a, b)<<"\n";
	LL x, y, m = gcdr(a, b, x, y);
	cout<<m<<" = "<<x<<"*"<<a<<" + "<<y<<"*"<<b<<"\n";
	cout<<invmod(a, b)<<"\n";
	cout<<potmod(a, b, 200);
	
	return 0;
}
