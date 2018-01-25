#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 1000001;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

LL n, m, k;
LL ak[MAXN], bk[MAXN];
LL num[MAXN];
LL last[MAXN];

vector<LL> res;
LL cnt;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>m;
	FOR(i, 1, m) cin>>bk[i];
	cin>>n;
	FOR(i, 1, n) cin>>ak[i];
	
	FOR(i, 1, n)
	{
		LL curr = max(ak[i], last[ak[i]]);
		
		LL tcnt = 1;
		
		while(curr < MAXN && tcnt <= ak[i])
		{
			last[ak[i]] = curr;
			if(!num[curr])
			{
				num[curr] = cnt + tcnt++;
			}
			curr+=ak[i];
		}
		
		
		
		cnt+=ak[i];
	}
	
	FOR(i, 1, m) if(num[bk[i]] != 0) res.PB(num[bk[i]]);
	sort(ALL(res));
	
	cout<<SIZE(res)<<"\n";
	for(LL it: res) cout<<it<<"\n";
	
	return 0;
}

/*

4
1
6
8
16
3
4
2
4

*/
