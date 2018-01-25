/*Oceny XXIV OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 1e6+1;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) 

int n, z, a, b;

int tab[MAXN], place[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>z;
	FOR(i, 1, n) cin>>tab[i];
	
	FOR(i, 1, n) place[tab[i]] = i;
	
	REP(i, z)
	{
		if(i > 0)
		{
			cin>>a>>b;
			int a1 = tab[a], b1 = tab[b];
			swap(place[a1], place[b1]);
			swap(tab[a], tab[b]);
		}
		
		DEBUG(
		FOR(i, 1, n) cout<<tab[i]<<" "; cout<<endl;
		FOR(i, 1, n) cout<<place[i]<<" "; cout<<endl;
		)
		int mxpl = 0;
		int res = 0;
		FOR(i, 1, n)
		{
			mxpl = max(mxpl, place[i]);
			if(mxpl <= i) res++;
		}
		
		cout<<res<<"\n";
	}	
	return 0;
}

/*
12 5
1 2 4 3 6 5 8 7 12 10 11 9

12 5
1 2 4 3 6 5 8 7 10 11 12 9

12 5
9 2 4 3 6 5 8 7 12 10 11 1

3 4
1 2 3
1 3
1 2
2 3

*/
