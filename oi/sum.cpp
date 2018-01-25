/*Sumy Fibonacciego XII OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 1e6+10;

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

int na, nb, nc;
int a[MAXN], b[MAXN], c[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin>>na;
	FOR(i, 1, na) cin>>a[i];
	cin>>nb;
	FOR(i, 1, nb) cin>>b[i];
	nc = max(na, nb);
	FOR(i, 1, nc) c[i] = a[i] + b[i];
	
	DEBUG(
	
	FOR(i, 1, nc) cout<<c[i]<<" ";
	
	)
	
	return 0;
}

/*

3
2 3 5
2 2 1
10


*/

