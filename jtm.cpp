#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 1e5+1;

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

int n, m;

int gcd(int a, int b)
{
	while(b) swap(a%=b, b);
	return a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	int res = 0;
	for(int i = 0; i < (1<<n); ++i)
	{
		int s = 0;
		FOR(j, 1, n)
		{
			if(i & (1<<(j-1))) s++;
		}
		if(2*s == n) res++;
			DEBUG(cout<<s<<" ";)
	}
	
	n = 1<<n;
	int c= gcd(res, n);
	n/=c;
	res/=c;
	cout<<endl<<res<<"/"<<n<<"\n";

	return 0;
}
