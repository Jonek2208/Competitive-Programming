#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MX = 200001;

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

int n, m;
LL d[MX], t[MX];
LL pop[MX];

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, m) cin>>d[i];
	
	//~ FOR(i, 1, n) cout<<pop[i]<<" ";
	//~ cout<<endl;
	LL sum0 = 0, sum = 0, r;
	FOR(k, 1, m)
	{
		//~ cout<<d[k]<<endl;
		sum0 = sum;
		sum = 0;
		FOR(i, 1, n)
		{
			r = max(pop[i] + d[k], t[i]);
			//~ cout<<r<<endl;
			pop[i+1] = r;
			sum+= r - t[i];			
		}
		//~ cout<<d[k]<<" : "<<sum<<" "<<sum-sum0<<"\n";
		cout<<sum<<"\n";
	}
	return 0;
}

/*
7 18
3 10 10 10 10 10 23
1 2 3 5 6 7 8 4 9 10 11 12 13 14 15 16 17 18
7 18
3 6 9 14 18 23 25
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
*/
