#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000001;
const int MAXN = 11;

typedef long long LL;
typedef unsigned int UI;
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

int n, m, z, a, b;

struct rmc
{
	int n, m, p;
	LL il = 1;
};

rmc dp[MAXN][MAXN];

VI g[MAXN]; 

int main()
{
	ios::sync_with_stdio(0);
	do
	{
		cin>>z;
		FOR(i, 1, z)
		{
			cin >> dp[1][i].n >> dp[1][i].m;
		}
		
		//pierszy poziom
		FOR(i, 1, z-1)
		{
			dp[2][i].il = dp[1][i].n * dp[1][i].m * dp[1][i+1].m;
		}
		
		//dp
		FOR(i, 3, z)
		{
			
		}
		
		FOR(i, 1, z)
		{
			FOR(j, 1, z-i+1)
			{
				cout<<dp[i][j].n<<" "<<dp[i][j].n<<" "<<dp[i][j].il<<" | ";
			}
			cout<<"\n";
		}
	} while(z != 0);
	return 0;
}





