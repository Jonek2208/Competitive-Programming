#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI; 
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define MP make_pair
#define MAXN 
#define INF 1000000001

inline int rnd(int a, int b)
{
	return rand()%(b-a)+a;
}

int main(int argv, char **argc)
{
	ios::sync_with_stdio(0);

	int seed = (atoi(argc[1]) * 1000007) % 10009;
	srand(seed*time(NULL));
	int n = rnd(5, 10);
	cout<<n<<endl;

	REP(i, n)
	cout<<rnd(5, 10)<<" ";
	cout<<endl;
	
	return 0;
}

