#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef vector<int> VI;

const int INF = 1000000007;
const int MAXN = 501;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define SIZE(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

#define DEBUG(s) s

int m, n, t;
LL res;
int val[MAXN][MAXN];
int state[MAXN][MAXN];
VI osr;
int dif[MAXN*MAXN];

inline bool inside(int i, int j)
{
	return (1 <= i && i <= m) && (1 <= j && j <= n);
}

const int dirc = 4;
int dirx[dirc] = {0, 0, -1, 1}, diry[dirc] = {1, -1, 0, 0};

bool odw[MAXN][MAXN];

int DFS(int i, int j, int d)
{
	int rozm = 1;
	odw[i][j] = 1;
	
	REP(k, dirc)
	{
		int i1 = i+dirx[k],  j1 = j + diry[k];
		if(inside(i1, j1) && !odw[i1][j1] && abs(val[i][j] - val[i1][j1]) <= d) rozm+=DFS(i1, j1, d);
	}
	
	return rozm;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>m>>n>>t;
	FOR(i, 1, m) FOR(j, 1, n) cin>>val[i][j];
	FOR(i, 1, m) FOR(j, 1, n) cin>>state[i][j];
	
	FOR(i, 1, m)
	{
		FOR(j, 1, n)
		{
			if(state[i][j])
			{
				int d = 0, r = 0;
				while(r < t)
				{
					FOR(i, 1, m) FOR(j, 1, n) odw[i][j] = 0;
					r = DFS(i, j, d);
					++d;
				}
				
				res+=d-1;
			}
		}
	}

	cout<<res<<"\n";
	
	
	return 0;
}




/*

3 5 10
20 21 18 99 5
19 22 20 16 17
18 17 40 60 80
1 0 0 0 0
0 0 0 0 0
0 0 0 0 1

3 5 10
20 21 18 99 5
19 22 20 16 17
18 17 40 60 80
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1


4 5 9
10 8 10 3 5 
10 4 4 2 7 
4 4 9 6 9 
9 6 2 1 7 
1 1 1 0 0 
0 1 1 0 0 
1 1 1 0 1 
1 0 1 0 1 


















*/
