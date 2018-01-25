#include<bits/stdc++.h>

using namespace std;

const int INF = -1000000001;
const int MAXN = 1000001;

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

struct punkt
{
	int x, y;
	bool operator <(const punkt &a) const
	{
		return (y == a.y ? x < a.x : y < a.y);
	}
};

int det(punkt A, punkt B, punkt C)
{
	return  (B.x-A.x) * (C.y-B.y) - (B.y-A.y) * (C.x-B.x);
}

punkt tab[MAXN];
int n, m, a, b;
vector<punkt> otoczka;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	REP(i, n)
	{
		cin>>tab[i].x>>tab[i].y;
	}
	
	sort(tab, tab+n);
	
	int m = 1;

	REP(i, n)
	{
		while(otoczka.size() > m && det(otoczka[otoczka.size()-2], otoczka[otoczka.size()-1], tab[i])<=0)
			otoczka.PP();
		otoczka.PB(tab[i]);	
	}

	m = otoczka.size();

	FORD(i, n-2, 0)
	{
		while(otoczka.size() > m && det(otoczka[otoczka.size()-2], otoczka[otoczka.size()-1], tab[i])<=0)
			otoczka.PP();
		otoczka.PB(tab[i]);
	}
	
	otoczka.PP();


	REP(i, n)
	cout<<tab[i].x<<" "<<tab[i].y<<endl;
	cout<<endl;
	FOREACH(it, otoczka)
		cout<<it->x<<" "<<it->y<<endl;

	return 0;
}
