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
#define INF -1000000001
#define MAXN 1000001

int n;
PII tem[MAXN];
multiset<int, greater<int> > maksima;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	FOR(i, 1, n)
	cin >> tem[i].ST >> tem[i].ND;
	
	int mx = 1;
	
	int poc = 1;
	
	FOR(kon, 1, n)
	{
		while(tem[poc].ND >= *(maksima.begin())   && poc <= n)
		{
			maksima.insert(tem[poc++].ST);
			
		}
		mx = max(mx, poc-kon);
		
		maksima.erase(maksima.find(tem[kon].ST));
	}
	
	cout<<mx;
	
	return 0;
}

