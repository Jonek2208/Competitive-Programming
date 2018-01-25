#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define RANGE 1000001
#define MAXN 50001
#define MXSQRTN 1001
#define MOD 1000000007

int n, q, p, k, sqrt_n;

int fac[RANGE];
long long rvm[RANGE];
vector<pair<int, int> > res[RANGE];
vector<pair<int, int> > kubel[MXSQRTN];
set<pair<int, int> > buf;

int tab[MAXN];

struct cmp


long long PowMod(long long a, long long b)
{
    long long p = 1;
    while(b > 0)
    {
        if(b % 2) p = (a*p) % MOD;
        a = (a*a) % MOD;
        b /= 2;
    }
    return p;
}


int main()
{
    ios::sync_with_stdio(0);

    //wczytanie
    cin>>n;
    FOR(i, 1, n)
    cin>>tab[i];

    sqrt_n = (int)sqrt(n-1) + 1;

    //tablica do faktoryzacji

    for(int i = 2; i*i <= RANGE; i++)
        if(!(fac[i]))
        {
            for(int j = i*i; j <= RANGE; j+=i)
                if(!fac[j]) fac[j] = i;
        }

    //odwrotnosci
    FOR(i, 1, RANGE)
    rvm[i] = PowMod(i, MOD-2);


    //rozklad
    int x, y;

    FOR(i, 1, n)
    {
        x = y = tab[i];

        while(fac[x] > 0)
        {
            if(res[y].empty() || fac[x]!=res[y].back().ST) res[y].PB(MP(fac[x], 1));
            else res[y].back().ND++;

            x/=fac[x];
        }
        if(res[y].empty() || x!=res[y].back().ST) res[y].PB(MP(x, 1));
            else res[y].back().ND++;
    }

     FOR(i, 1, n)
    {
        cout<<tab[i]<<" : ";
        REP(j, res[tab[i]].size())
        cout<<res[tab[i]][j].ST<<"|"<<res[tab[i]][j].ND<<" ";
        cout<<endl;
    }

    //kubelki










    cin>>q;


    REP(x, q)
    {
        cin>>p>>k;

        long long wynik = 1;

        FOR(i, p, k)
        {


        }
    }




    return 0;
}
