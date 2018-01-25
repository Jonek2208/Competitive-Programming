#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 30001;
const long long MOD = 123456789;
const int A = 26;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, k, a, b; 
char c1, c2;
LL res;
#define NUM(c) (int)(c-'a'+1)

#define GDRAW(kk) FOR(i, 0, A){ FOR(j, 0, A) cout<<(kk)[i][j]<<" "; cout<<"\n";} cout<<"\n";

LL g[A+1][A+1];

//~ LL pot(LL a, LL b)
//~ {
	//~ LL p = 1;
	//~ while(b)
	//~ {
		//~ if(b%2 == 1) p *=a;
		//~ a *= a; 
		//~ b/=2;
	//~ }
	//~ return p;
//~ }

void mnoz(LL m1[A+1][A+1], LL m2[A+1][A+1], LL mres[A+1][A+1])
{
	FOR(i, 0, A) 
	{
		FOR(j, 0, A)
		{
			LL temp = 0;
			FOR(x, 0, A)
			temp = (temp + (m1[i][x] * m2[x][j]) % MOD) % MOD;
			mres[i][j] = temp;
		}
	}
}

void pot(int wyk)
{
	LL g1[A+1][A+1], gres[A+1][A+1];
	FOR(i, 0, A) FOR(j, 0, A) g1[i][j] = g[i][j];
	FOR(i, 1, A) g[i][i] = 1;
	//~ GDRAW(g);
	
	while(wyk>0)
	{
		if(wyk%2 == 1)
		{
			//~ FOR(i, 0, A) FOR(j, 0, A) gres[i][j] = 0;
			mnoz(g, g1, gres);
			FOR(i, 0, A) FOR(j, 0, A) g[i][j] = gres[i][j];
		}
		
		//~ FOR(i, 0, A) FOR(j, 0, A) gres[i][j] = 0;
		mnoz(g1, g1, gres);
		FOR(i, 0, A) FOR(j, 0, A) g1[i][j] = gres[i][j];
		//~ GDRAW(g1);
		wyk/=2;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	
	FOR(i, 1, A) FOR(j, 1, A) g[i][j] = 1;
	FOR(i, 1, A) g[0][i] = 1;
	
	REP(i, k)
	{
		cin>>c1>>c2;
		a = NUM(c1);
		b = NUM(c2);
		
		g[a][b] = 0;
	}
	
	//~ GDRAW(g);
	pot(n-1);
	//~ GDRAW(g);
	
	FOR(i, 1, A) res = (res + g[0][i])%MOD;
	cout<<res<<endl;
	
	
	
	return 0;
}

/*

4 4
a b
b c
c a
f g

449033

*/
