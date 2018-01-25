/*Jonatan Hrynko*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 1000001;

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

bool MiRa(LL x, LL n)
{
	if(x >= n) return 0;
	LL d = 1, y;
	LL t = 0, l = n-1;
	while(!(l&1))
	{
		++t;
		l>>=1LL;
	}
	
	for(; l > 0 || t--; l >>= 1LL)
	{
		if(l&1) d = (d*x)%n;
		if(!l)
		{
			x = d;
			l = -1LL;
		}
		y = (x*x) % n;
		if(y == 1 && x != 1 && x != n-1) return 1;
		x = y;
	}
	
	return x != 1;
}

bool isPrime(LL x)
{
	return !(x < 2 || MiRa(2, x) || MiRa(3, x) || MiRa(5, x) || MiRa(7, x) || MiRa(11, x) || MiRa(13, x) || MiRa(17, x));
}

//~ bool isPrime(LL x)
//~ {
	//~ for(LL i = 2; i*i <= x; i++)
	//~ {
		//~ if(x>2 && x%i == 0) return false;
	//~ }
	//~ return true;
//~ }

LL m;
LL a, b;
LL k;

int main()
{
	ios_base::sync_with_stdio(0);
	while(cin>>m)
	{
		cout<<(isPrime(m) ? "TAK" : "NIE")<<"\n";
	}
	//~ cin>>m;
	//~ k = 10LL;
	//~ bool res = false;
	//~ bool flag;
	
	//~ while(k <= m)
	//~ {
		//~ flag = ((m/(k/10LL)) % 10 != 0);
		
		//~ a = m/k;
		//~ b = m%k;
		
		//~ if(flag)
		//~ {
			//~ cout<<a<<" "<<b<<"\n";
			//~ if(isPrime(a) && isPrime(b)) 
			//~ {
				//~ res = true;
				
			//~ }
		//~ }
		//~ k*=10;
	//~ }
	
	//~ cout<<(res ? "TAK" : "NIE");
	
	return 0;
}

/*
15485867533000389

10399999999999971
100000000710000007
*/

