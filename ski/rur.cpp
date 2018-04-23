/*Kucharz XXIV OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 1e5+1;

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

#define DEBUG(s) s

int n, s, w, x, y;
PII tx[2*MAXN], ty[2*MAXN];
LL sx, sy;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>s>>w;
	
	REP(i, n)
	{
		cin>>x>>y;
		tx[2*i] = MP(x, -1);
		tx[2*i+1] = MP(x+s, 1);
		ty[2*i] = MP(y, -1);
		ty[2*i+1] = MP(y+w, 1);
	}
	
	sort(tx, tx+2*n);
	sort(ty, ty+2*n);
	
	VI ros, mal;
	REV(i, 2*n) if(tx[i].ND == -1) mal.PB(tx[i].ST);
	REP(i, 2*n)
	{
		if(tx[i].ND == -1) mal.PP();
		else ros.PB(tx[i].ST);
		if(SIZE(mal) == SIZE(ros))
		{
			for(auto j: mal) sx += j - tx[i].ST;
			for(auto j: ros) sx += tx[i].ST - j;
		}
	}
	
	ros.clear();
	mal.clear();
	
	REV(i, 2*n) if(ty[i].ND == -1) mal.PB(ty[i].ST);
	REP(i, 2*n)
	{
		if(ty[i].ND == -1) mal.PP();
		else ros.PB(ty[i].ST);
		if(SIZE(mal) == SIZE(ros))
		{
			for(auto j: mal) sy += j - ty[i].ST;
			for(auto j: ros) sy += ty[i].ST - j;
		}
	}
	cout<<(sx+sy)<<endl;
	
	return 0;
}

/*

7 4 3
2 -4
1 1
-3 -2
-2 4
0 5
0 -4
-2 -1

5 10 10
3 -1
2 16
3 8
6 9
2 6








*/

