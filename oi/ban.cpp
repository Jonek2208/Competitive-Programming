/*Banknoty XII OI*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1000000007;
const int MAXN = 201;
const int MAXK = 20001;

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

#define DEBUG(s) 

int n, k;
int b[MAXN], c[MAXN];

int dp[MAXN][MAXK];
int wart[MAXN][MAXK];
int res[MAXN];

deque<PII> kol;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n) cin>>b[i];
	FOR(i, 1, n) cin>>c[i];
	cin>>k;
	
	FOR(i, 1, k) dp[0][i] = INF;
	
	FOR(i, 1, n)
	{
		FOR(j, 1, k) dp[i][j] = dp[i-1][j];
		FOR(j, 0, b[i]-1)
		{
			kol.clear();
			for(int x = 0; j + x*b[i] <= k; ++x)
			{
				if(dp[i-1][j + x*b[i]] != INF) while(!kol.empty() && kol.back().ST >= dp[i-1][j + x*b[i]] - x) kol.pop_back();
				kol.push_back(MP(dp[i-1][j + x*b[i]] - x, x));
				while(!kol.empty() && x - kol.front().ND > c[i]) kol.pop_front();
				
				if(!kol.empty())
				{
					int val = kol.front().ST + x;
					if(dp[i][j + x*b[i]] > val)
					{
						dp[i][j + x*b[i]] = val;
						wart[i][j + x*b[i]] = x - kol.front().ND;
					}
				}
			}
		}
		
		
	}
	
	DEBUG(
	FOR(i, 0, n)
	{
		FOR(j, 0, k)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	)
	
	int v = k;
	FORD(i, n, 1)
	{
		res[i] = wart[i][v];
		v -= b[i] * wart[i][v];
	}
	
	cout<<dp[n][k]<<"\n";
	FOR(i, 1, n) cout<<res[i]<<" ";
	
	
	return 0;
}

/*

3
2 3 5
2 2 1
10


*/
