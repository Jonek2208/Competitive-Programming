#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000001;
const int MAXN = 100001;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >=(e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define REV(x, n) for(int x = 0; x < (n); --x)
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin; i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)((c).size())
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

const int X = 27;
const int P = 70000027;
int n;
VI hasz, a;
string s;

void process()
{
	a.resize(n, 0);
	REP(i, n)
	{
		a[i] = s[i] - 'a';
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin>>s;
	n = s.length();
	hasz.resize(n, 0);
	process();

	hasz[n-1] = a[n-1];
	FORD(i, n-2, 0)
	{
		hasz[i] = (a[i] + ((X * hasz[i+1])%P)) % P;
	}

	REP(i, n)
	{
		cout<<hasz[i]<<endl;
	}

	return 0;
}
