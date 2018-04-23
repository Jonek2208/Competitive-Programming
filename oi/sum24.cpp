/*Suma cyfr XXIV OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const LL INF = 1000000000000000007;
const int MAXN = 201;
const int LEN = 200;
const int A = 10;

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

int s, m, q;
LL k;
LL dp[MAXN][MAXN][MAXN];

int mods[MAXN];

#define MOD(x) ((x)%m+m)%m

void draw(LL x, int len, int sum, int md)
{
	if (len == 0) return;
	int it = sum;
	FORD(i, sum, max(0, sum - 9))
	{
		it = i;
		if(dp[len-1][i][MOD(md-(sum-i)*mods[len])] >= x) break;
		x -= dp[len-1][i][MOD(md-(sum-i)*mods[len])];
	}
	cout<<sum-it;
	draw(x, len-1, it, MOD(md-(sum-it)*mods[len]));
}

void draw(LL x)
{
	int it = 1;
	while(it < LEN && dp[it][s][0] < x) ++it;
	DEBUG(cout<<"("<<it<<") ";)
	if(dp[it][s][0] < x) cout<<"NIE";
	else draw(x, it, s, 0);
	cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>s>>m>>q;
	
	FOR(i, 1, LEN) mods[i] = MOD(i == 1 ? 1 : mods[i-1] * 10);
	
	//~ DEBUG(FOR(i, 1, LEN) cout<<mods[i]<<" "; cout<<endl;)
	
	FOR(i, 0, 9) dp[1][i][MOD(i)] = 1;
	FOR(i, 2, LEN)
	{
		FOR(j, 0, s)
		{
			FOR(r, 0, m-1)
			{
				FOR(k, 0, min(9, j)) 
				{
					dp[i][j][r] += dp[i-1][j-k][MOD(r-k*mods[i])];
					dp[i][j][r] = min(dp[i][j][r], INF);
				}
			}
		}
	}
	
	DEBUG(
	//~ FOR(i, 1, LEN)
	//~ {
		//~ FOR(j, 1, s) cout<<dp[i][j]<<" "; 
		//~ cout<<endl;
	//~ }
	//~ cout<<endl;
	FOR(k, 0, m-1)
	{
		FOR(i, 1, LEN)
		{
			FOR(j, 0, s) cout<<dp[i][j][k]<<" "; 
			cout<<endl;
		}
		cout<<endl;
	}
	)
	
	while(q--)
	{
		cin>>k;
		draw(k);
	}

	return 0;
}

/*
15 1 0
*/
