/*Kanciara*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int MAXM = 100001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define ST first
#define ND second
#define SIZE(c) (int)(c.size())
#define DEBUG(s) 

int per[MAXM], tmp[MAXM], stos[MAXM], kon[MAXM];
int n, m, q, a;

void tasuj(int x)
{
	//~ cout<<"rmc\n";
	if(n-x+1 < m) return;
	FOR(i, 1, m) tmp[per[i]] = stos[i+x-1];
	//~ DEBUG(FOR(i, 1, m) cout<<tmp[i]<<" "; cout<<"\n";)
	FOR(i, 1, m) stos[i+x-1] = tmp[i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	
	FOR(i, 1, m) cin>>per[i];
	FOR(i, 1, n) stos[i] = i;
	
	/*tasowanie*/
	FOR(i, 1, n)
	{
		tasuj(i);		
	}
	
	FOR(i, 1, n) kon[n-i+1] = stos[i];
	
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

12 6 12
3
4
5
6
1
2
1
2
3
4
5
6
7
8
9
10
11
12

*/
