/*************************************************************************
 *                                                                       *
 *                    XXV Olimpiada Informatyczna                        *
 *                                                                       *
 *   Zadanie:              Plan metra                                    *
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
const int MAXN = 500001;

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

int n;
vector<PII> g[MAXN];
bool possible = true;

struct Station
{
	int nr;
	int d, l, r, s;
	bool operator<(const Station &a)const
	{
		return (r == a.r ? s < a.s : r < a.r);
	}
};

Station tab[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	
	if(n == 2)
	{
		cout<<"TAK\n1 2 1\n";
		return 0;
	}
	
	FOR(i, 2, n-1) cin>>tab[i].d;
	FOR(i, 2, n-1) cin>>tab[i].l;
	
	int minsum = INF;
	
	FOR(i, 2, n-1)
	{
		tab[i].nr = i;
		tab[i].s = tab[i].d + tab[i].l;
		minsum = min(minsum, tab[i].s);
		tab[i].r = tab[i].d - tab[i].l;
	}
	
	tab[1].nr = 1;
	tab[1].r = INF;
	tab[n].nr = n;
	tab[n].r = INF;
	
	//przypadek gdy n jest polaczony z 1
	
	int k = abs(tab[2].r);
	bool nto1 = (k != 0);
	
	//roznica rozna od 0
	if(nto1)
	{
		FOR(i, 2, n-1)
		{
			if(abs(tab[i].r) != k)
			{	
				nto1 = false;
				break;
			}
		}
	}
	
	if(nto1)
	{
		FOR(i, 2, n-1)
		{
			if(tab[i].r == k)
			{
				g[n].PB(MP(tab[i].nr, tab[i].l));
			}
			else
			{
				g[1].PB(MP(tab[i].nr, tab[i].d));
			}
		}
		g[n].PB(MP(1, k));
	}
	//cos jest na sciezce 1->n
	else
	{
		//sortuj
		sort(tab+2, tab+n);
		int k = minsum;
		
		if(tab[2].r < -k || k < tab[n-1].r)
		{
			cout<<"NIE\n";
			return 0;
		} 
		
		vector<PII> ojce;
		ojce.PB(MP(0, 1));
		
		FOR(i, 2, n-1)
		{
			if(tab[i].r != tab[ojce.back().ND].r && tab[i].r > -k && tab[i].r < k)
			{
				ojce.PB(MP(tab[i].s, i));
			}
		}		
		
		FOR(i, 1, SIZE(ojce)-2) 
		{
			if(ojce[i].ST != ojce[i+1].ST) 
			{
				cout<<"NIE\n";
				return 0;
			}
		}
		
		int it1 = 0;
		FOR(i, 2, n-1)
		{
			//doczepiamy poddrzewo do 1
			if(tab[i].r == -k) g[1].PB(MP(tab[i].nr, tab[i].d));
			//doczepiamy na sciezce 1->n
			else if(tab[i].r != tab[i-1].r && tab[i].r < k)
			{
				g[tab[ojce[it1].ND].nr].PB(MP(tab[i].nr, tab[i].d - tab[ojce[it1].ND].d));
				it1++;
			}
			//doczepiamy do poddrzewa na sciezce
			else if(tab[i].r < k)
			{
				g[tab[ojce[it1].ND].nr].PB(MP(tab[i].nr, tab[i].d - tab[ojce[it1].ND].d));
			}
			//doczepiamy do poddrzewa n
			else
			{
				g[n].PB(MP(tab[i].nr, tab[i].l));
			}
		}
		
		//doczepiamy n do ostatniego ojca
		g[tab[ojce[it1].ND].nr].PB(MP(n, tab[ojce[it1].ND].l));
		
		FOR(i, 1, n)
		FOREACH(it, g[i])
		{
			if(it->ND == 0)
			{
				cout<<"NIE\n";
				return 0;
			}
		}
	}

	cout<<"TAK\n";
	FOR(i, 1, n)
	{
		FOREACH(it, g[i])
		{
			cout<<i<<" "<<it->ST<<" "<<it->ND<<"\n";
		}
	}
	return 0;
}
