#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int MAXN = 100001;

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

int n, k;

struct LINE
{
	LL A, B, C;
	LINE(): A(0), B(0), C(0) {}
};

struct POINT
{
	LL x, y;
	double dist;
	POINT(): x(0), y(0), dist(0) {}
	
	void distcalc(LINE l)
	{
		dist = fabs( ( (double)(l.A*x) + (double)(l.B*y) + (double)(l.C) ) / sqrt( (double)(l.A*l.A + l.B*l.B) ) ); 
	}
};



POINT tab[MAXN];
LINE prosta;


struct 
{
	bool operator()(const POINT &a, const POINT &b)
	{   
		return a.dist < b.dist;
	}   
} cmp;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	cin>>prosta.A>>prosta.B>>prosta.C;
	
	REP(i, n) cin>>tab[i].x>>tab[i].y;
	
	REP(i, n) tab[i].distcalc(prosta);
	
	sort(tab, tab+n, cmp);
	
	DEBUG(REP(i, n) cout<<setprecision(11)<<tab[i].dist<<" "; cout<<endl;)
	
	cout<<setprecision(11)<<tab[k-1].dist<<"\n";
	
	
	return 0;
}

/*

3 1
1 -1 0
10 2
2 9
15 1

4 2
0 2 -4
1 1
10 3
3 5
2 0

*/
