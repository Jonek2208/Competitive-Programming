#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int MAXN = 1001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) s

int n, t;

struct POINT
{
	LL x, y;
	POINT(): x(0), y(0){}
	POINT(LL _x, LL _y): x(_x), y(_y){}
	
	POINT operator+(const POINT &b) const
	{
		return POINT(x+b.x, y+b.y);
	}
	POINT operator-(const POINT &b) const
	{
		return POINT(x-b.x, y-b.y);
	}
};

LL det(POINT a, POINT b)
{
	return a.x * b.y - a.y * b.x;
}


pair<POINT, POINT> tab[MAXN];

int visible[MAXN][MAXN];

VI dag[MAXN], rdag[MAXN];
int dp[MAXN][MAXN];
int last[MAXN];
pair<PII, PII> pom[MAXN][MAXN];

int mx;

VI res;

void reku(int a, int b)
{
	if(a == b) 
	{
		res.PB(a);
		return;
	}
	
	reku(pom[a][b].ST.ST, pom[a][b].ST.ND);
	if(pom[a][b].ST != pom[a][b].ND)
	reku(pom[a][b].ND.ST, pom[a][b].ND.ND);
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	FOR(i, 1, n) cin>>tab[i].ST.x>>tab[i].ST.y;
	cin>>t;
	
	DEBUG(FOR(i, 1, n) cout<<"("<<tab[i].ST.x<<", "<<tab[i].ST.y<<") "; cout<<endl;)
	
	
	FOR(i, 2, n-1) tab[i].ND = tab[i+1].ST-tab[i].ST;
	
	DEBUG(FOR(i, 1, n) cout<<"("<<tab[i].ND.x<<", "<<tab[i].ND.y<<") "; cout<<endl;)
	
	FOR(i, 2, n)
	{
		FOR(j, i+1, n)
		{
			if(det(tab[i].ND, tab[j].ST-tab[i].ST) >= 0) 
			{
				visible[i][j] = 1;
				tab[i].ND = tab[j].ST-tab[i].ST;
			}
		}
	}
	
	DEBUG(
	FOR(i, 1, n)
	{
		FOR(j, 1, n) cout<<visible[i][j]<<" ";
		cout<<endl;
	}
	)
	
	FOR(i, 2, n) dp[i][i] = 1;
	FOR(i, 2, n) pom[i][i] = MP(MP(i, i), MP(i, i));
	
	FOR(k, 1, n-2)
	{
		FOR(i, 2, n-k)
		{
			int j = i+k;
			
			if(visible[i][j]) 
			{
				last[i] = j;
			}
			
			dp[i][j] = dp[i][j-1];
			pom[i][j] = pom[i][j-1];
			
			if(dp[i+1][j] > dp[i][j-1])
			{
				dp[i][j] = dp[i+1][j];
				DEBUG(cout<<"zmiana poczatku "<<k+1<<" "<<i<<" -> "<<i+1<<"\n";)
				pom[i][j] = pom[i+1][j];
			}
			
			if(dp[i][last[i]-1] + dp[last[i]+1][j] > dp[i][j])
			{
				dp[i][j] = dp[i][last[i]-1] + dp[last[i]+1][j];
				DEBUG(cout<<"doklejenie nowego "<<k+1<<" "<<i<<" -> "<<last[i]+1<<"\n";)
				pom[i][j].ST = MP(pom[i][last[i]-1].ST.ST, pom[i][last[i]-1].ND.ND);
				pom[i][j].ND = MP(pom[last[i]+1][j].ST.ST, pom[last[i]+1][j].ND.ND);
			}
			
			
		}
	}
	
	DEBUG(
	cout<<endl;
	FOR(i, 1, n)
	{
		FOR(j, 1, n) cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	)
	
	DEBUG(
	cout<<endl;
	FOR(i, 1, n)
	{
		FOR(j, 1, n) cout<<"("<<pom[i][j].ST.ST<<", "<<pom[i][j].ST.ND<<") ";
		cout<<endl;
		FOR(j, 1, n) cout<<"("<<pom[i][j].ND.ST<<", "<<pom[i][j].ND.ND<<") ";
		cout<<endl<<endl;
	}
	)
	
	cout<<dp[2][n]<<endl;
	reku(2, n);
	for(auto i: res) cout<<i<<" ";
	
	return 0;
}

/*

in:

9
0 0
4 0
4 1
3 1
3 2
2 3
1 3
1 4
0 4
0

out:

3
3 6 8


in:

4
0 0
1 0
1 1
0 1
0

out:

1
4

14
0 0
5 -5
11 -7
11 -4
17 -4
14 2
14 4
13 4
10 5
7 4
5 4
5 6
4 7
2 5
0



*/
