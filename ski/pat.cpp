#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 5e5+1;
const int M = 2e6+1;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FOR(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) 

int n, e;
int tab[MAXN];
int nimber[M];

int sito[M];
int fact[MAXN];

void sitocalc(int m)
{
	for(int i = 2; i*i <= m; ++i)
	if(!sito[i]) for(int j = i*i; j <= m; j+=i) if(!sito[j]) sito[j] = i;
}

inline int nimcalc(int x)
{
	if(x <= 1) return 0;
	if(nimber[x]) return nimber[x];
	
	int tmp = x;
	
	int cnt = 0;
	while(sito[tmp])
	{
		fact[cnt++] = sito[tmp];
		tmp/=sito[tmp];
	}
	fact[cnt++] = tmp;
	nimber[x] = 1;
	FOR(i, 1, cnt-1) if(fact[i]%2) nimber[x]++;
	return nimber[x];
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n) cin>>tab[i];
	int ajkc = 0;
	FOR(i, 1, n) ajkc = max(ajkc, tab[i]);
	sitocalc(ajkc);
	
	int res = 0;
	
	FOR(i, 1, n) res ^= nimcalc(tab[i]);
	
	cout<<(res == 0 ? ":(" : ":)" )<<"\n";
	
	
	return 0;
}


