#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 1000005;

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

#define DEBUG(s) 

int n, k, m, l, rmc, res;
PII mx;

int tab[MAXN], tabm[MAXN], tabl[MAXN]; /*dane wejsciowe*/
int nleft[MAXN], nright[MAXN], kleft[MAXN], kright[MAXN]; /*nastepny dom takiego samego koloru / tablice k[] pomocnicze*/
int cleft[MAXN], cright[MAXN]; /**/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	/*wczytywanie*/
	cin>>n>>k;
	FOR(i, 1, n) cin>>tab[i];
	cin>>m>>l;
	FOR(i, 1, m) cin>>tabm[i];
	FOR(i, 1, l) cin>>tabl[i];
	rmc = tabm[m];
	
	/*dom tego samego koloru po lewej i po prawej*/
	FOR(i, 1, n)
	{
		nright[kright[tab[i]]] = i;
		kright[tab[i]] = i;
	}
	
	FORD(i, n, 1)
	{
		nleft[kleft[tab[i]]] = i;
		kleft[tab[i]] = i;
	}
	
	DEBUG(
	cout<<"nastepny po prawej:\n";
	FOR(i, 1, n) cout<<nright[i]<<" ";
	cout<<"\nnastepny po lewej:\n";
	FOR(i, 1, n) cout<<nleft[i]<<" ";
	cout<<"\n";
	)	
	
	/****************************** dotad jest dobrze **************************/
	
	FOR(i, 1, m) kright[i] = 0;
	FOR(i, 1, l) kleft[i] = 0;

	int lastm = 1, lastl = n, itm = 1, itl = 1;
	
	/*od lewej do prawej*/

	while(itm < m && lastm <= n)
	{
		if(tab[lastm] == tabm[itm]) kright[itm++] = lastm;
		lastm++;
	}
	
	FOR(i, 1, n)
	{
		if(!cright[tab[i]])
		{
			kright[0] = i;
			itm = 1;
			
			while(kright[itm] != 0 && itm < m && kright[itm-1] >= kright[itm])
			{
				kright[itm] = nright[kright[itm]]; /*przejdz do nastepnego*/
				if(kright[itm-1] < kright[itm]) itm++; /*jest ok, i idzie do nastepnego koloru*/
			}
			cright[tab[i]] = kright[m-1]; /*niezmiennik*/
		}
	}
	
	
		
	/*od prawej do lewej*/
	
	while(itl < l && lastl >= 1)
	{
		if(tab[lastl] == tabl[itl]) kleft[itl++] = lastl;
		lastl--;
	}
	
	FORD(i, n, 1)
	{
		if(!cleft[tab[i]])
		{
			kleft[0] = i;
			itl = 1;
			while(kleft[itl] != 0 && itl < l && kleft[itl] >= kleft[itl-1])
			{
				kleft[itl] = nleft[kleft[itl]]; /*przejdz do nastepnego*/
				if(kleft[itl] < kleft[itl-1]) itl++; /*jest ok, i idzie do nastepnego koloru*/
			}

			cleft[tab[i]] = kleft[l-1]; /*niezmiennik*/
		}
	}
	
	
	DEBUG(
	FOR(i, 1, k)
	cout<<"{"<<i<<"} : "<< cright[i]<<"\n";
	cout<<"\n";
	FOR(i, 1, k)
	cout<<"{"<<i<<"} : "<< cleft[i]<<"\n";
	)
	
	
	mx = MP(n+1, 0);
	FOR(i, 1, k)
	{
		if(cright[i] && cleft[i] && cright[i]+1 <= cleft[i]-1)
		{
			//~ if(pref[cleft[i]-1] - pref[cright[i]] > res)
			//~ {
				//~ res = pref[cleft[i]-1] - pref[cright[i]];
				//~ mx = MP(cright[i]+1, cleft[i]-1);
			//~ }
			mx.ST = min(mx.ST, cright[i]+1);
			mx.ND = max(mx.ND, cleft[i]-1);
		}
	}
	
	VI ajkc;
	
	FOR(i, mx.ST, mx.ND)
	{
		if(tab[i] == rmc) ajkc.PB(i);
	}

	
	//~ cout<<res<<"\n";
	
	//~ FOR(i, mx.ST, mx.ND)
	//~ {
		//~ if(tab[i] == rmc) cout<<i<<" ";
	//~ }
	
	cout<<SIZE(ajkc)<<"\n";
	for(int i: ajkc) cout<<i<<" ";
	
	return 0;
}

/*

15 7
2 5 6 2 4 7 3 3 2 3 7 5 3 6 2
3 2
4 7 3
5 3

18 7
2 4 7 3 6 2 4 3 7 3 2 3 7 3 5 3 6 2
3 2
4 7 3
5 3

7 1
1 1 1 1 1 1 1
1 1 
1
1

5 2
1 2 2 1 2
1 2
2
1 2


*/
