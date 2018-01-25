#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int MAXN = 1001;

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

int n, t;

struct POINT
{
	LL x, y;
	POINT(): x(0), y(0){}
	POINT(LL _x, LL _y): x(_x), y(_y){}
	
	POINT operator+(const POINT &b) const
	{
		return POINT(x+b.x, y+b.y);
	}
	POINT operator-(const POINT &b) const
	{
		return POINT(x-b.x, y-b.y);
	}
};

LL det(POINT a, POINT b)
{
	return a.x * b.y - a.y * b.x;
}


pair<POINT, POINT> tab[MAXN];

int visible[MAXN][MAXN];

int odw[MAXN], wynik[MAXN], cnt = -1, mx;

void rekubrut(int v)
{
	
	cnt++;
	odw[v] = 1;
	DEBUG(cout<<"v "<<v<<" cnt "<<cnt<<endl;)
	if(cnt>mx)
	{
		mx = cnt;
		FOR(i, 1, n) wynik[i] = odw[i];
	}
	
	
	
	FOR(i, v+1, n)
	{
		bool flag = true;
		FOR(j, 1, n)
		if(odw[j] && visible[j][i])
		{
			flag = false;
			break;
		}
		if(flag)rekubrut(i);
	}
	
	cnt--;
	odw[v] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	FOR(i, 1, n) cin>>tab[i].ST.x>>tab[i].ST.y;
	cin>>t;
	
	DEBUG(FOR(i, 1, n) cout<<"("<<tab[i].ST.x<<", "<<tab[i].ST.y<<") "; cout<<endl;)
	
	
	FOR(i, 2, n-1) tab[i].ND = tab[i+1].ST-tab[i].ST;
	
	DEBUG(FOR(i, 1, n) cout<<"("<<tab[i].ND.x<<", "<<tab[i].ND.y<<") "; cout<<endl;)
	
	FOR(i, 2, n)
	{
		FOR(j, i+1, n)
		{
			if(det(tab[i].ND, tab[j].ST-tab[i].ST) >= 0) 
			{
				visible[i][j] = 1;
				tab[i].ND = tab[j].ST-tab[i].ST;
			}
		}
	}
	
	DEBUG(
	FOR(i, 1, n)
	{
		FOR(j, 1, n) cout<<visible[i][j]<<" ";
		cout<<endl;
	}
	)
	
	rekubrut(1);
	cout<<mx<<endl;
	FOR(i, 2, n) if(wynik[i]) cout<<i<<" ";
	
	return 0;
}

/*

in:

9
0 0
4 0
4 1
3 1
3 2
2 3
1 3
1 4
0 4
0

out:

3
3 6 8


in:

4
0 0
1 0
1 1
0 1
0

out:

1
4

*/
