#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 500001;
const int LOG = 20;

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

int n, q, a, b;
string s;

int dict[LOG][MAXN];
int logs[MAXN];
VI divs[MAXN];
bitset<MAXN> odw;

void build_KMR(string &s)
{
	pair<PII, int> pairs[n];
	
	REP(i, n) dict[0][i] = s[i];
	for(int l = 1; (1<<l) <= n; l++)
	{
		REP(i, n-(1<<l)+1) pairs[i] = MP(MP(dict[l-1][i], dict[l-1][i+(1<<(l-1))]), i);
		sort(pairs, pairs + n - (1<<l)+1);
		int nr = 1;
		REP(i, n-(1<<l)+1)
		{
			if(i > 0 && pairs[i].ST != pairs[i-1].ST) nr++;
			dict[l][pairs[i].ND] = nr;
		}
	}
}

void logcalc()
{
	int lg = 0;
	FOR(i, 1, n)
	{
		if((1<<(lg+1)) < i) lg++;
		logs[i] = lg;
	}
}

bool compare(int a, int b, int len)
{
	int ok = b-a+1-len;
	int lg = logs[len], dl = 1<<lg;
	//~ cout<<"ok: "<<ok<<" len: "<<len<<" lg: "<<lg<<" dl: "<<dl<<"\n";
	//~ cout<<"a1: "<<a<<" a2: "<<a+ok<<" b1: "<<(b-ok)-(dl-1)<<" b2: "<<b-(dl-1)<<"\n";
	//~ cout<<dict[lg][a]<<" "<<dict[lg][a+ok]<<" "<<dict[lg][b-ok-(dl-1)]<<" "<<dict[lg][b-(dl-1)]<<"\n";
	return (dict[lg][a] == dict[lg][a+ok]) && (dict[lg][b-ok-(dl-1)] == dict[lg][b-(dl-1)]);
}

void divscalc()
{
	FOR(i, 1, n)
	{
		for(int j = i; j <= n; j+=i) divs[j].PB(i);
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	cin>>s;
	
	divscalc();
	logcalc();
	build_KMR(s);
	
	//~ FOR(i, 1, n) cout<<logs[i]<<" ";
	//~ cout<<"\n";
	
	//~ for(int i = 0; (1 << i) <= SIZE(s); i++)
	//~ {
		//~ REP(j, SIZE(s)/*-(1<<i)+1*/) cout<<dict[i][j]<<" ";
		//~ cout<<"\n";
	//~ }
	
	cin>>q;
	FOR(it, 1, q)
	{
		cin>>a>>b;
		a--; b--;
		int k = b-a+1;
		int res = k;
		//~ cout<<"t: "<<it<<endl;
		for(int i: divs[k])
		{
			int okr = i;
			if(k % okr == 0)
			{
				if(compare(a, b, k-okr))
				{
					res=min(res, okr);
					break;
				}
			}
		} 
		
		cout<<res<<"\n";
	}
	
	
	return 0;
}


/*
8
aaabcabc
3
1 3
3 8
4 8

15
ykdyykdyykdyykd
9
3 10
9 12
7 14
3 14
1 4
2 9
3 6
1 12
1 8

*/

