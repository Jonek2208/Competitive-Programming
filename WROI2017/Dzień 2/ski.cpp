#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 500001;

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

int n;

struct Planet
{
	int x, y, z;
};

Planet tab[MAXN];
LL mx[MAXN][2][2][2];
LL ajkc[2][2][2];
LL pom[2] = {1, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n)
	{
		cin>>tab[i].x>>tab[i].y>>tab[i].z;
	}
	
	//ustawienie ajkc
	FOR(x, 0, 1)
	FOR(y, 0, 1)
	FOR(z, 0, 1)
		ajkc[x][y][z] = -6*(LL)INF;
	
	//maksima wartosci dla wszystkich i ajkc
	FOR(i, 1, n)
	{
		FOR(x, 0, 1)
		FOR(y, 0, 1)
		FOR(z, 0, 1)
		{
			mx[i][x][y][z] = tab[i].x*pom[x] + tab[i].y*pom[y] + tab[i].z*pom[z];
			ajkc[x][y][z] = max(ajkc[x][y][z], mx[i][x][y][z]);
		}
	}
	
	FOR(i, 1, n)
	{
		LL res = 0;
		FOR(x, 0, 1)
		FOR(y, 0, 1)
		FOR(z, 0, 1)
		{
			res = max(res, mx[i][x][y][z] + ajkc[(x+1)%2][(y+1)%2][(z+1)%2]);
		}
		
		cout<<res<<"\n";
	}
	return 0;
}
