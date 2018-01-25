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

struct Square
{
	int x, y, nr, a;
	
	Square(){}
	Square(int _x, int _y, int _nr, int _a = 1) : x(_x), y(_y), nr(_nr), a(_a) {}
	
	bool operator<(const Square &s1) const
	{
		return (y == s1.y ? x < s1.x : y < s1.y);
	}
};

vector<Square> tab;

int t, n, x, y;

int main()
{
	ios::sync_with_stdio(0);
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		tab.clear();
		FOR(i, 1, n)
		{
			cin>>x>>y;
			tab.PB(Square(x, y, i));
		}
		
		sort(ALL(tab));
		
		for(auto it: tab)
		{
			cout<<it.x<<" "<<it.y<<" "<<it.nr<<" "<<it.a<<"\n";
		}
	}
	
	return 0;
}
