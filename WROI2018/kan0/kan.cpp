/*Kanciara*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int MAXM = 1e5+2;
const int MAXN = 1e7+2;

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

int tab[MAXM], per[MAXM], stos[MAXM], kon[MAXM];
int cnt;
bool odw[MAXM];
vector<VI> cykle;
int n, m, q, a, t, s;

int query(int x)
{
	x =  n-x+1;
	int res = 0;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	
	FOR(i, 1, m) cin>>tab[i];
	
	FOR(i, 1, m) per[i] = (tab[i] - 1 + m)%(m+1)+1;
	per[m+1] = m;
	
	DEBUG(FOR(i, 1, m+1) cout<<per[i]<<" "; cout<<endl;)
	
	FORD(i, m+1, 1)
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
	t = n-m+1;
	s = SIZE(cykle[0]);
	
	FOR(i, 1, s-2)
	{
		stos[cykle[0][i]] = n-i+1;
	}
	
	FOR(i, 1, SIZE(cykle)-1)
	{
		REP(j, SIZE(cykle[i]))
		{
			stos[(cykle[i][j] + t - 1)%s+1] = cykle[i][j];
		}
	}
	
	FOR(i, 1, n) kon[n-i+1] = stos[i];
	
	DEBUG(FOR(i, 1, n) cout<<stos[i]<<" "; cout<<endl;)

	while(q--)
	{
		cin>>a;
		cout<<query(a)<<"\n";
	}
	
	
	
	return 0;
}

/*

5 3 5
3
1
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

20 5 0
4 
5 
1 
2 
3

12 4 0
4
1
2
3


*/
