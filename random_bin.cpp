#include<bits/stdc++.h>
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
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define MAXN 200000

int rnd(int a, int b)
{
	return rand()%(b-a) + a;
}

int main()
{
	srand(time(NULL));
	int n = 6;
	int m = rnd(1, 5);
	int q = rnd(1, 2*n);
	cout<<n<<endl;
	REP(i, n) cout<<(rnd(1, 10))<<" ";
	
	
	
	return 0;
}
