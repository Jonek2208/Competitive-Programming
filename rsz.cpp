/*Przemytnicy X OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 5002;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FOR(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) s

int n, m, a, b, c;


int main()
{
	ios::sync_with_stdio(0);
	
	srand((LL)(new int));
	int n;
	cin>>n>>a;
	while(cin.get())
	{
		int b = rand()%a+1;
		cout<<n<<" x "<<b<<" = "<<n*b;
	}

	return 0;
}


