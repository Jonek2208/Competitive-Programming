/*Niemalejace zdjecie*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAXN = 200001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define SIZE(c) (int)(c.size())

#define DEBUG(s) 

int tab[MAXN], sorted[MAXN];
int n, rmc;
int res;

unordered_map<int, int> mapa;
int dp[MAXN];
VI g[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n) cin>>tab[i];
	
	FOR(i, 1, n) if(tab[i] != tab[i-1]) sorted[++rmc] = tab[i];
	FOR(i, 1, n) tab[i] = sorted[i];
	
	sort(sorted+1, sorted+rmc+1);
	
	int mpcnt = 0;
	FOR(i, 1, rmc) if(sorted[i] != sorted[i-1]) mapa[sorted[i]] = ++mpcnt;
	FOR(i, 1, rmc) tab[i] = mapa[tab[i]];

	/******************************************************************************************/
	
	DEBUG( FOR(i, 1, rmc) cout<<tab[i]<<" "; cout<<endl;)
	DEBUG( FOR(i, 1, rmc) cout<<sorted[i]<<" "; cout<<endl;)
	
	FOR(i, 1, rmc) g[tab[i]].PB(i);
	
	int mx1 = 0, mx2 = 0;
	
	FOR(i, 2, rmc)
	{
		for(auto j: g[i])
		{
			if(tab[j] == tab[j-1] + 1)
			{
				DEBUG(cout<<"j: "<<j<<endl;)
				dp[j] = max(dp[j], dp[mx1] + (mx1 != j-1 || SIZE(g[i-1]) == 1));
				dp[j] = max(dp[j], dp[mx2] + (mx2 != j-1 || SIZE(g[i-1]) == 1));
			}
		}
		
		for(auto j: g[i])
		{
			if(dp[j] > dp[mx2])
			{
				if(dp[j] > dp[mx1])
				{
					mx2 = mx1;
					mx1 = j;
				}
				else
				{
					mx2 = j;
				}
			}
		}
	}
	
	FOR(i, 1, rmc) res = max(res, dp[i]);
	res = rmc-1-res;
	
	cout<<res<<"\n";
	return 0;
}

/*

12
1 2 2 3 3 1 2 3 4 1 2 3

11
4 5 6 1 2 3 4 5 6 1 2

13
3 4 5 6 1 2 3 4 5 6 1 2 3

7
1 2 3 1 2 3 4

11
3 6 12 7 7 7 7 8 10 5 5  

14
3 4 5 1 2 3 4 5 6 7 6 7 8 9

6
4 5 6 1 2 3

*/
