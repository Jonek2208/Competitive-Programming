#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 3001;
const LL MOD = 1000000007;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

const int mv = 4;
const int xx[mv] = {0, 0, 1, -1};
const int yy[mv] = {1, -1, 0, 0};

int tab[MAXN][MAXN], dist[MAXN][MAXN], odw[MAXN][MAXN];
int n, k;
char c;
LL res;

inline bool inside(int a, int b)
{
	return (1 <= a) && (a <= n) && (1 <= b) && (b <= n);
}




struct Vdata
{
	int a, b;
	Vdata(){}
	Vdata(int _a, int _b) : a(_a), b(_b) {}
};

vector<Vdata> kol;

void BFS()
{
	FOR(i, 1, n)
	FOR(j, 1, n)
	{
		if(tab[i][j] == 1)
		{
			odw[i][j] = true;
			kol.PB(Vdata(i, j));
		}
	}
	
	REP(i, SIZE(kol))
	{
		Vdata v = kol[i];
		
		REP(j, mv)
		{
			int a1 = xx[j] + v.a, b1 = yy[j] + v.b;
			
			if(!odw[a1][b1] && inside(a1, b1))
			{
				odw[a1][b1] = true;
				dist[a1][b1] = dist[v.a][v.b] + 1;
				kol.PB(Vdata(a1, b1));
			}
		}
	}
}

const LL modinv[] = {0, 1, 500000004, 333333336, 250000002};

LL binom(LL x, int _kk)
{
	LL kk = (LL)_kk;
	if(x < kk) return 0LL;
	
	LL wyn = 1;
	
	FOR(i, x-kk+1, x)
	{
		wyn *= (LL)i;
		wyn %= MOD;
	}
	
	FOR(i, 1, kk)
	{
		wyn *= modinv[i];
		wyn %= MOD;
	}
	
	return wyn;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	FOR(i, 1, n)
	FOR(j, 1, n)
	{
		cin>>c;
		tab[i][j] = (c == '#' ? 1 : 0);
	}	
	
	//wypisywanie
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			cout<<tab[i][j]<<" ";
		}	
		cout<<"\n";
	}
	cout<<endl;
	
	BFS();
	
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			cout<<dist[i][j]<<" ";
		}	
		cout<<"\n";
	}
	
	//zliczanie 1
	
	LL f = 0;
		
	FOR(i, 1, n)
	FOR(j, 1, n)
	{
		if(dist[i][j] == 1) f++;
	}
	
	if(k == 1)
	{
		res = f;
	}
	else
	{
		LL p12 = 0;
		
		FOR(i, 1, n)
		FOR(j, 1, n)
		{
			if(dist[i][j] == 1) f++;
		}
		
		res += binom(f, 2);
		res %= MOD;
		
		res += 
		
	}
	
	cout<<res<<"\n";
	return 0;
}

/*
Test przykladowy:

3  2
.#.
##.
#..

*/

/*
Testy moje

12 1
............
............
............
............
..##.#......
.#.###......
.#.###......
######......
######......
.#####......
..##.#......
..####......

12 2
............
............
............
............
..##.#......
.#.###......
.#.###......
######......
######......
.#####......
..##.#......
..####......

12 3
............
............
............
............
..##.#......
.#.###......
.#.###......
######......
######......
.#####......
..##.#......
..####......

12 4
............
............
............
............
..##.#......
.#.###......
.#.###......
######......
######......
.#####......
..##.#......
..####......














*/
