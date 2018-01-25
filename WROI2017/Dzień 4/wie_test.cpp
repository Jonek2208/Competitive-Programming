#include<bits/stdc++.h>

using namespace std;

const int INF = -1000000001;
const int MAXN = 1000001;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, a;

int rnd(int x, int y)
{
	return rand()%(y-x+1) + x;
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	ios::sync_with_stdio(0);
	n = atoi(argv[1]);
	cout<<n<<"\n";
	FOR(i, 1, n)
	{
		a = rnd(1, 20);
		cout<<a<<" ";
	}
	
	return 0;
}
