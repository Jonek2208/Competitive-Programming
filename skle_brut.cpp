#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

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
#define MAXN 2001

int n, k;
int tab[MAXN];

SI kwoty;

int suma1 = 0, suma2 = 0;

void sprawdz(int x)
{
	
	suma1+=tab[x];
	FOR(i, x+1, n)
	sprawdz(i);
	
	if(suma1 + suma2 == k)
	{
		kwoty.insert(suma1);
		kwoty.insert(suma2);
	}
	
	suma1-=tab[x];
	suma2+=tab[x];

	FOR(i, x+1, n)
	sprawdz(i);
	
	if(suma1 + suma2 == k)
	{
		kwoty.insert(suma1);
		kwoty.insert(suma2);
	}
	
	suma2-=tab[x];
	
}

int main()
{
	ios::sync_with_stdio(0);
	
	cin>>n>>k;
	
	FOR(i, 1, n)
		cin>>tab[i];
		
	FOR(i, 1, n)
	{
		sprawdz(i);
	}	
	
	//wynik
	
	cout<<kwoty.size()<<endl;
	
	FOREACH(it, kwoty)
	{
		cout<<*it<<" ";
	}
	
	cout<<endl;
	
	
	
	return 0;
}
