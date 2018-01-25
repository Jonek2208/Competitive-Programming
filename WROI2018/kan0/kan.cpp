/*Kanciara*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int MAXM = 1e5+2;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define ST first
#define ND second
#define SIZE(c) (int)(c.size())

#define DEBUG(s) s

int per[MAXM], tmp[MAXM], stos[MAXM], kon[MAXM];
bool odw[MAXM];
vector<VI> cykle;
int n, m, q, a;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	
	FOR(i, 1, m) cin>>per[i];
	FOR(i, 1, n) stos[i] = i;
	
	
	FOR(i, 1, m)
	{
		if(!odw[i])
		{
			cykle.PB(VI());
			int tmp = i;
			
			while(!odw[tmp]) 
			{
				odw[tmp] = true;
				cykle.back().PB(tmp = per[tmp]);
			}
		}
	}
	
	DEBUG(
	for(auto i: cykle)
	{
		for(auto j: i) cout<<j<<" ";
		cout<<endl;
	}
	)
	
	/*tasowanie*/

	while(q--)
	{
		cin>>a;
		cout<<kon[a]<<"\n";
	}
	
	
	
	return 0;
}

/*

5 3 5
3
15 3 0
3
1
2

2
1
2
3
4
5

5 3 0
3
1
2

10 6 0
3 
4 
5 
6 
1 
2

10 5 0
4 
5 
1 
2 
3

*/
