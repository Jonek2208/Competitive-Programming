/*Zapiekanki XXIV OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const LL LLINF = 1000000000000000007LL;
const int MX = 3001;

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

LL k, z, d;
LL dp[MX][MX];
LL ti[MX][MX];
LL tab[MX];

LL poc;
bool flag;

int main()
{
	ios::sync_with_stdio(0);
	cin>>k>>z>>d;
	FOR(i, 1, k)
	{
		cin>>tab[i];
		if(!flag && tab[i] >= d)
		{
			poc = i-1;
			flag = true;
		}
	}
	
	DEBUG(cout<<poc<<endl;)
	
	LL czas = d;
	LL ile = 0;
	
	FOR(i, 1, k)
	{
		if(tab[i] <= czas && ile < z)
		{
			++ile;
		}
		else if(tab[i] <= czas)
		{
			czas+=d;
			ile = 1;
		}
		else
		{
			czas += ((tab[i] - czas - 1) / d + 1) * d;
			ile = 1;
		}
		ti[poc][i] = czas;
		dp[poc][i] = dp[poc][i-1] + czas - tab[i];
	}
	
	FOR(j, poc+1, k)
	{
		czas = tab[j];
		LL tczas = czas;
		ile = 0;
		LL tile = ile;
		
		FOR(i, 1, k)
		{
			dp[j][i] = LLINF;
			
			FOR(l, poc, j-1)
			{
				if(ti[l][i] <= tab[j] - d) 
				{
					if(dp[l][i] < dp[j][i])
					{
						dp[j][i] = dp[l][i];
						ti[j][i] = ti[l][i];
					}
				}
			}
			if(tab[i] <= czas && ile < z)
			{
				tile = ile + 1;
			}
			else if(tab[i] <= czas)
			{
				tczas = czas+d;
				tile = 1;
			}
			else
			{
				tczas = czas + ((tab[i] - czas - 1LL) / d + 1LL) * d;
				tile = 1;
			}
			if(dp[j][i-1] + czas - tab[i] < dp[j][i])
			{
				czas = tczas;
				ile = tile;
				ti[j][i] = czas;
				dp[j][i] = dp[j][i-1] + czas - tab[i];
				
			}
		}
	}
	
	DEBUG(
	
	FOR(i, 1, k)
	{
		FOR(j, 1, k)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	FOR(i, 1, k)
	{
		FOR(j, 1, k)
		{
			cout<<ti[i][j]<<" ";
		}
		cout<<endl;
	}
	)
	
	cout<<dp[k][k]<<"\n";
	
	return 0;
}


/*
9 2 4
3 7 10 12 12 13 13 24 25

*/
