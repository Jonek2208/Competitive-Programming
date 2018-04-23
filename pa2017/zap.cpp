#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const LL INFL = 100000000ll * 100000000ll + 5;
const int MX = 200005;

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
#define CEIL(x, y) ((x-1ll)/y+1ll)

#define DEBUG(s) //cout<<"<DEBUG\n"; s   cout<<"DEBUG>\n";

int n, m;
LL t[MX];
pair<LL, int> d[MX];
LL res[MX];

LL sum, poc_sum, ile_sum;

struct blok
{
	LL poc;
	LL ile;
	LL kiedy;
	int nr, pop, nast;
	blok (){}
	blok(LL _poc, LL _ile, int _nr, int _pop, int _nast) : poc(_poc), ile(_ile), nr(_nr), pop(_pop), nast(_nast) {}
	
	bool operator <(const blok &a) const
	{
		return (kiedy == a.kiedy ? nr < a.nr : kiedy < a.kiedy);
	}
	
	void merge();
	void wypisz()
	{
		cout<<"( {"<<nr<<"} "<<poc<<", "<<ile<<", "<<kiedy<<", "<<pop<<", "<<nast<<")\n";
	}
};

blok tab[MX];
set<blok> kolejka;

LL wynik(LL d)
{
	return poc_sum + d*ile_sum - sum;
}

void blok::merge()
{
	blok *ajkc = &tab[pop], *rmc = &tab[nast];
	
	ile_sum -= ile*(ile-1ll)/2ll + ajkc->ile*(ajkc->ile-1ll)/2ll;
	poc_sum -= poc*ile + ajkc->poc * ajkc->ile;
	
	kolejka.erase(*ajkc);
	kolejka.erase(*rmc);
	DEBUG(this->wypisz();)
	ajkc->ile += ile; //zwieksza ile
	rmc->pop = pop; //wskazniki
	ajkc->nast = nast; // wskazniki
	rmc->kiedy = CEIL(rmc->poc-ajkc->poc, ajkc->ile); //aktualizuje kiedy
	kolejka.insert(*rmc);
	kolejka.insert(*ajkc);
	
	ile_sum += ajkc->ile*(ajkc->ile-1ll)/2ll;
	poc_sum += ajkc->poc * ajkc->ile;
}


int main()
{
	//~ ios::sync_with_stdio(0);
	cin>>n>>m;
	tab[0] = blok(0, 1, 0, 0, 1); //blok zerowy
	FOR(i, 1, n) 
	{
		cin>>t[i];
		tab[i] = blok(t[i], 1, i, i-1, i+1); //bloki podstawowe
	}
	
	//sortuje w kolejnosci rosnacej zapytania
	REP(i, m) 
	{
		cin>>d[i].ST;
		d[i].ND = i;
	}
	sort(d, d+m);
	
	DEBUG(
		REP(i, m) cout<<"("<<d[i].ST<<", "<<d[i].ND<<") ";
		cout<<endl;
	)
	
	//oblicza i merguje dla d=0
	tab[0].kiedy = INFL;
	tab[n+1] = blok(INFL, 1, n+1, n, n+2);
	tab[n+1].kiedy = INFL;
	kolejka.insert(tab[0]);
	kolejka.insert(tab[n+1]);
	FOR(i, 1, n)
	{
		tab[i].kiedy = CEIL(tab[i].poc - tab[i-1].poc, tab[i-1].ile);
		kolejka.insert(tab[i]);
	}
	
	REP(i, m)
	{
		DEBUG(
		for(auto it: kolejka) it.wypisz();
		FOR(i, 0, n+1) tab[i].wypisz();
		)
		while(kolejka.begin()->kiedy <= d[i].ST)
		{
			blok pom = *kolejka.begin();
			kolejka.erase(kolejka.begin());
			pom.merge();
		}
		
		res[d[i].ND] = wynik(d[i].ST);
		DEBUG(cout<<"d: "<<d[i].ST<<", wynik: "<<res[i];)
	}
	
	REP(i, m) cout<<res[i]<<"\n";
	return 0;
}

/*
7 18
3 10 10 10 10 10 23
1 2 3 5 6 7 8 4 9 10 11 12 13 14 15 16 17 18
7 18
3 6 9 14 18 23 25
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18

4 10
3 10 11 23
0 1 2 3 4 5 6 7 8 9

10 4
1000000000000 1000000000000 1000000000000 1000000000000 1000000000000 1000000000000 1000000000000 1000000000000 1000000000000 1000000000000 
1000 50 1000000 123



*/
