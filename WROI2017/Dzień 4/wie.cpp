#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 100001;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, k, a, b;
int tab[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	REP(i, n) cin>>tab[i];
	
	int before = 0, current = 0, level = 0;
	REV(i, n)
	{
		current += tab[i];
		if(current >= before)
		{
			level++;
			before = current;
			current = 0;
		}
	}
	
	cout<<level<<"\n";
	
	return 0;
}

/*
3
1 2 3

6
2 3 1 2 4 5

*/
