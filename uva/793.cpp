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

int n, m, a, b, z;

string c;

int p[MAXN], r[MAXN], zlicz[MAXN];

void Init()
{
	FOR(i, 1, n)
	{
		p[i] = i;
		r[i] = 0;
		zlicz[i] = 0;
	}
}



int Find(int x)
{
	if(p[x] != x)
		p[x] = Find(p[x]);
	return p[x];
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x == y) return;
	if(r[x] > r[y]) p[y] = x;
	else p[x] = y;
	if(r[x] == r[y]) r[y]++;
}

int GetMax()
{
	FOR(i, 1, n)
		zlicz[Find(i)]++;
	int res = 0;
	FOR(i, 1, n)
		res = max(res, zlicz[i]);
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	
	cin>>z;
	cin>>n;
	REP(i, z)
	{
		int yes = 0, no = 0;
		
		Init();
		while(cin>>c)
		{
			if(c == "c")
			{
				cin>>a>>b;
				Union(a, b);
			}
			else if(c == "q")
			{
				cin>>a>>b;
				if(Find(a) == Find(b)) yes++;
				else no++;
			}
			else
			{
				n = stoi(c);
				break;
			}
		}
		
		cout<<yes<<","<<no<<endl;
		if(i != z-1) cout<<endl;
		
	}
	
	return 0;
}
