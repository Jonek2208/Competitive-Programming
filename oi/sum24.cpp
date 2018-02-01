/*Suma cyfr XXIV OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 201;
const int LEN = 20;
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

#define DEBUG(s) s

int s, m, q;
LL k;
LL dp[MAXN][MAXN][MAXN];
LL pref[MAXN][MAXN][MAXN];

int mods[MAXN];

#define MOD(x) ((x)%m+m)%m

void draw(LL x, int len, int sum, int md)
{
	if (len == 0) return;
	int it = sum;
	FORD(i, sum, max(0, sum - 9))
	{
		it = i;
		if(pref[len-1][i][MOD(md-(sum-i)*mods[len])] >= x) break;
		x -= pref[len-1][i][MOD(md-(sum-i)*mods[len])];
	}
	cout<<sum-it;
	draw(x, len-1, it, MOD(md-(sum-it)*mods[len]));
}

void draw(LL x)
{
	int it = 1;
	while(it <= LEN && pref[it][s][0] < x) ++it;
	if(pref[it][s][0] < x) cout<<"NIE";
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
	FOR(i, 1, LEN-1)
	{
		FOR(j, 0, s)
		{
			FOR(r, 0, m-1)
			{
				FOR(k, 0, min(9, s-j)) 
				{
					dp[i+1][j+k][MOD(r+k*mods[i+1])] += dp[i][j][r];
				}
			}
		}
	}
	
	FOR(i, 1, LEN)
	{
		FOR(j, 0, s)
		{
			FOR(r, 0, m-1)
			{
				pref[i][j][r] = pref[i-1][j][r] + dp[i][j][r];
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
