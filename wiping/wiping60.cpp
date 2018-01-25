#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 3001;
const LL MOD = 1000000007;
const LD eps = 0.00000001;

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
#define EQUAL(x, y) fabs( (x) - (y) <= eps)

const int vcount = 4;

struct Point
{
	LL x, y;
	Point(){}
	Point(LL _x, LL _y) : x(_x), y(_y) {}
};

LL lsq(Point a, Point b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

LL lsq(Point a)
{
	return (a.x)*(a.x) + (a.y)*(a.y);
}

LD len(Point a)
{
	return sqrt((a.x)*(a.x) + (a.y)*(a.y));
}

LL cross(Point a, Point b)
{
	return a.x*b.y - a.y*b.x;
}

LL dot(Point a, Point b)
{
	return a.x*b.x + a.y*b.y;
}

Point operator-(const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y);
}

Point polygon[vcount];
Point edges[vcount];

int main()
{
	ios::sync_with_stdio(0);
	REP(i, vcount)
	cin>>polygon[i].x>>polygon[i].y;
	
	REP(i, vcount)
	{
		edges[i] = polygon[(i+1)%vcount] - polygon[i];
	}
	
	if( len(edges[0]) + len(edges[2]) == len( edges[1]) + len(edges[3]) )
	cout<<"True\n";
	else cout<<"False\n";
	
	LL sinx = cross(edges[0], edges[1]), siny = cross(edges[2], edges[3]);
	LL cosx = dot(edges[0], edges[1]), cosy = dot(edges[2], edges[3]);
	
	LL pom = sinx*cosy + siny*cosx;
	
	if(pom == 0)
	cout<<"True\n";
	else
	cout<<"False\n";
	
	return 0;
}

/*
1 -4 5 2 2 4 -2 -2
*/
