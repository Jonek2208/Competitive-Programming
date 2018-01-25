#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 1000001;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, k, m, l;
int kol[MAXN], zlicz[MAXN], dm[MAXN], dl[MAXN], odw[MAXN];
int kdomu;
set<int> koncowe;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
	FOR(i, 1, n)
	cin >> kol[i];
	cin >> m >> l;
	
	REP(i, m)
	{
		cin >> dm[i];
		odw[dm[i]] = 1;
	}
		
	REP(i, l)
	{
		cin >> dl[i];
		odw[dl[i]] = 1;
	}
	
	kdomu = dl[l-1];
	
	//~ FOR(i, 1, k) cout<<odw[i]<<" ";


	FOR(i, 1, n-1)
	FORD(j, n, i)
	{
		if(!odw[kol[i]] && kol[i] == kol[j])
		{
		//~ cout<<kol[i]<<" "<<kol[j]<<endl;	
		int it1 = i;
		int it2 = j;
		
		REP(k, m)
		while(kol[it1] != dm[k] && it1 < j)
			it1++;

		REP(k, l)
		while(kol[it2] != dl[k] && it2 > i)
			it2--;
			
		FOR(k, it1, it2)
		if(kol[k] == kdomu)
		koncowe.insert(k);
		}
	}
	
	cout<<koncowe.size()<<endl;
	FOREACH(it, koncowe)
	cout<<*it<<" ";
	
	return 0;
}
