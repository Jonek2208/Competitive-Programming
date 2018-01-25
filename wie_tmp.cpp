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
#define MAXN 200000

int n, wynik = 1, mb, poprz, mx_lng, k;
int tab[MAXN], lng[MAXN], unt[MAXN], res[MAXN], tree[1<<18];
set<int> S;

unordered_map<int, int> mapa;

void insert(int a, int b)
{
	a += k;
	
	tree[a] = max(tree[a], b);
	a>>=1;
	
	while(a>=1)
	{
		tree[a] = max(tree[2*a], tree[2*a + 1]);
		a>>=1;
	}	
}

int query(int a, int b)
{
	a += k; b += k;
	
	int mx = 0;
	
	while(a<b)
	{
		if(a%2==1) mx = max(mx, tree[a++]);
		if(b%2==0) mx = max(mx, tree[b--]);
		
		a>>=1;
		b>>=1;
	}
	if(a==b) mx = max(mx, tree[a]);
	
	return mx;	
}



int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	REP(i, n)
	{
		cin>>tab[i];
		S.insert(tab[i]);
	}
	
	//obliczanie wartosci
	
	unt[0] = lng[n-1] = 1;
	FOR(i, 1, n-1)
	unt[i] = tab[i-1] < tab[i] ? unt[i-1] + 1 : 1;
	FORD(i, n-2, 0)
	lng[i] = tab[i] < tab[i+1] ? lng[i+1] + 1 : 1;
	
	//REP(i, n)
	//{
		//cout<<unt[i]<<" "<<lng[i]<<endl;
	//}
	
	//mapowanie
	
	int cnt = 0;
	FOREACH(it, S)
	{
		mapa[*it] = cnt++;
	}
	
	k = (int)log2(cnt-1) + 1;
	k = 1<<k;
	//cout<<k<<endl;
	
	//REP(i, k)
	//cout<<tree[i+k]<<" ";
	//cout<<endl;
	
	insert(mapa[tab[n-1]], lng[n-1]); 
	
	//REP(i, n)
	//{
		//cout<<tab[i]<<" "<<mapa[tab[i]]<<endl;
	//}
	
	//REP(i, k)
	//cout<<tree[i+k]<<" ";
	//cout<<endl;
	
	//brutalny maks
	FORD(i, n-2, 0)
	{
			int mx = query(mapa[tab[i]]+1, cnt);
			wynik = max(wynik, unt[i] + mx);
			
			insert(mapa[tab[i]], lng[i]);
			
			//zREP(i, k)
			//cout<<tree[i+k]<<" ";
			//cout<<endl;
	}
	
	REP(i, n)
	wynik = max(wynik, res[i]);
	
	cout<<wynik;
	
	
	return 0;
}

/*
	10
	1 4 5 2 7 6 8 9 8 3
	
	9
	5 3 4 9 2 8 6 7 1

 */

