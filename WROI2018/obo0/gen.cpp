#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef vector<int> VI;

const int INF = 1000000007;
const int MAXN = 10001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define SIZE(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

#define DEBUG(s) s

int rnd(int a, int b)
{
	return rand()%(b-a+1)+a;
}

int main()
{
	ios::sync_with_stdio(0);
	srand((LL)new int);
	
	int n = rnd(40, 70), m = rnd(40, 70), t = rnd(1, m*n);
	cout<<m<<" "<<n<<" "<<t<<"\n";
	
	FOR(i, 1, m)
	{
		FOR(j, 1, n) cout<<rnd(1,100)<<" ";;
		cout<<"\n";
	}
	FOR(i, 1, m)
	{
		FOR(j, 1, n) cout<<rnd(0,1)<<" ";;
		cout<<"\n";
	}
	
	
	return 0;
}

