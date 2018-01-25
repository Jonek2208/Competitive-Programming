/*************************************************************************
 *                                                                       *
 *                    XXV Olimpiada Informatyczna                        *
 *                                                                       *
 *   Zadanie:              Roznorodnosc                                  *
 *   Autor:                Jonatan Hrynko                                *
 *                                                                       *
 *************************************************************************/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 3001;
const int C = 100001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

LL n, m, k;
LL tab[MAXN][MAXN];
LL zlicz[C];
LL mx, sum;
LL rozn;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>m>>n>>k;
	FOR(i, 1, m)
	FOR(j, 1, n)
		cin>>tab[i][j];
	
	//zliczenie pierwszego k*k
	FOR(i, 1, k)
	FOR(j, 1, k)
	{
		if(zlicz[tab[i][j]]==0) rozn++;
		zlicz[tab[i][j]]++;
	}
	
	for(int i = 1; i <= m-k+1; i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1; j <= n-k+1; j++)
			{
				if(j!=1)
				{
					for(int x = i; x <= i+k-1; x++)
					{
						zlicz[tab[x][j-1]]--;
						if(zlicz[tab[x][j-1]] == 0) rozn--;
						if(zlicz[tab[x][j+k-1]] == 0) rozn++;
						zlicz[tab[x][j+k-1]]++;	
					}
				}
				mx = max(rozn, mx);
				sum += rozn;
			}		
			for(int x = n-k+1; x <= n; x++)
			{
				zlicz[tab[i][x]]--;
				if(zlicz[tab[i][x]] == 0) rozn--;
				if(zlicz[tab[i+k][x]] == 0) rozn++;
				zlicz[tab[i+k][x]]++;
			}
		}
		else
		{
			for(int j = n-k+1; j >= 1; j--)
			{
				if(j!=n-k+1)
				{
					for(int x = i; x <= i+k-1; x++)
					{
						zlicz[tab[x][j+k]]--;
						if(zlicz[tab[x][j+k]] == 0) rozn--;
						if(zlicz[tab[x][j]] == 0) rozn++;
						zlicz[tab[x][j]]++;
					}
				}
				mx = max(rozn, mx);
				sum += rozn;
			}
			for(int x = 1; x <= k; x++)
			{
				zlicz[tab[i][x]]--;
				if(zlicz[tab[i][x]] == 0) rozn--;
				if(zlicz[tab[i+k][x]] == 0) rozn++;
				zlicz[tab[i+k][x]]++;
			}
		}
	}
	
	cout<<mx<<" "<<sum<<"\n";
	
	return 0;
}
