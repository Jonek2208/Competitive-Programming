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

vector<PII> kol;

void BFS()
{
	FOR(i, 1, n)
	FOR(j, 1, n)
	{
		if(tab[i][j] == 1)
		{
			odw[i][j] = true;
			kol.PB(MP(i, j));
		}
	}
	
	REP(i, SIZE(kol))
	{
		PII v = kol[i];
		
		REP(j, mv)
		{
			int a1 = xx[j] + v.ST, b1 = yy[j] + v.ND;
			
			if(!odw[a1][b1] && inside(a1, b1))
			{
				odw[a1][b1] = true;
				dist[a1][b1] = dist[v.ST][v.ND] + 1;
				kol.PB(MP(a1, b1));
			}
		}
	}
}

set<PII> sciezka;

void Search(int aa, int bb)
{
	if(SIZE(sciezka) == k)
	{
		res++;
		res%=MOD;
		return;
	}
	
	FOR(i, aa, n)
	FOR(j, (i == aa ? bb : 1), n)
	{
		if(dist[i][j] > 0 && (sciezka.find(MP(i, j)) == sciezka.end()))
		{
			bool connected = false;
			
			if(dist[i][j] == 1) 
				connected = true;
			else
			{
				REP(x1, mv)
				{
					int a1 = i+xx[x1], b1 = j+yy[x1];
					if(inside(a1, b1) && sciezka.find(MP(a1, b1)) != sciezka.end()) connected = true;
				}
			}
			
			if(connected) 
			{
				sciezka.insert(MP(i, j));
				//~ cout<<"("<<i<<", "<<j<<", "<<SIZE(sciezka)<<")\n";
				Search(i, j);
				sciezka.erase(MP(i, j));
			}
		}
	}
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
	//~ FOR(i, 1, n)
	//~ {
		//~ FOR(j, 1, n)
		//~ {
			//~ cout<<tab[i][j]<<" ";
		//~ }	
		//~ cout<<"\n";
	//~ }
	//~ cout<<endl;
	
	BFS();
	
	//~ FOR(i, 1, n)
	//~ {
		//~ FOR(j, 1, n)
		//~ {
			//~ cout<<dist[i][j]<<" ";
		//~ }	
		//~ cout<<"\n";
	//~ }
	
	Search(1, 1);
	
	cout<<res<<"\n";
	return 0;
}

/*
Test przykladowy:

3  2
.#.
##.
#..
* 
3  4
.#.
##.
#..

*/

/*
Testy moje



4 4
....
####
#.#.
#.#.

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

