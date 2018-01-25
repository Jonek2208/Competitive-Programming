#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 1001;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int h, w, n;
int tab[MAXN][MAXN];
int pref[MAXN+1][MAXN+1];

inline int block(int x, int y, int s)
{
	return pref[x][y] - pref[x-s][y] - pref[x][y-s] + pref[x-s][y-s];
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>h>>w;
	n = min(h, w);
	
	FOR(i, 1, h)
	FOR(j, 1, w)
		cin>>tab[i][j];
		
		
	FOR(i, 1, h)
	{
		int suma = 0;
		FOR(j, 1, w)
		{
			suma+=tab[i][j];
			pref[i][j] = pref[i-1][j] + suma;
		}
	}
	//~ FOR(i, 1, h)
	//~ {
		//~ FOR(j, 1, w)
		//~ {
			//~ cout<<pref[i][j]<<" ";
		//~ }
		//~ cout<<endl;
	//~ }
		
	int mn, mx, diff = 0;
	
	FOR(k, 1, n)
	{
		mn = INF;
		mx = 0;
		
		for(int i = k; i <= h; i+=k)
		for(int j = k; j <= w; j+=k)
		{
			int kk = block(i, j, k);
			mn = min(mn, kk);
			mx = max(mx, kk);
		}
		diff = max(diff, mx-mn);
	}
	cout<<diff<<endl;

	return 0;
}


