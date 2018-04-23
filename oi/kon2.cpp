#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int N = 5e5+1;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

#define DEBUG(s) s

int z, m, n;

struct trasa
{
	LL x, y;
	trasa(){}
	trasa(LL _x, LL _y) : x(_x), y(_y) {}
	bool operator <(const trasa &b) const
	{
		return y < b.y;
	}
};

trasa kon[N];
LL pom[2*N];
vector<trasa> prz;
LL dp[2*N][2];

int main()
{
	ios::sync_with_stdio(0);
	cin>>z;
	while(z--)
	{
		cin>>m>>n;
		REP(i, n)
		{
			cin>>kon[i].x>>kon[i].y;
			pom[2*i] = kon[i].x;
			pom[2*i+1] = kon[i].y;
		}
		
		sort(pom, pom+2*n);
		sort(kon, kon+n);
		
		REP(i, 2*n) cout<<pom[i]<<" "; 
		cout<<"\n";
		REP(i, n) cout<<"("<<kon[i].x<<", "<<kon[i].y<<") ";
		
		REP(i, n)
		{
			
		}
		
	}
	return 0;
}
/*
1
11 4
1 4
6 8
2 7
9 10
*/
