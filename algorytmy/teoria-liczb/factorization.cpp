#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 1000001;

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

int sito[MAXN];
int czynniki[MAXN];
int n, m, x;

int main()
{
	cin>>n>>m;
	
	/*sito, w ktorym spamietujemy najmniejszy dzielnik pierwszy liczby, rozny od niej*/
	for(int i = 2; i*i <= n; i++)
	{
		if(!sito[i])
		{
			for(int k = i*i; k <= n; k+=i)
			if(!sito[k]) sito[k] = i;
		}
	}
	
	//~ FOR(i, 1, n) cout<<i<<" : "<<sito[i]<<"\n"; 
	
	REP(i, m)
	{
		cin>>x;
		int k = 0;
		while(sito[x] > 0)
		{
			czynniki[k++] = sito[x];
			x /= sito[x];
		}
		
		czynniki[k++] = x;
		
		REP(j, k) cout<<czynniki[j]<<" ";
		cout<<"\n";
	}
	
	return 0;
}
