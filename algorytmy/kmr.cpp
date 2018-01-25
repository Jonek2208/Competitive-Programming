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

int n, q, a, b, c;
string s;

int logs[MAXN];
int ids[LOG][MAXN];

void build_KMR(string &s)
{
	pair<PII, int> pairs[n];
	REP(i, n) ids[0][i] = s[i];
	
	for(int lg = 1; (1<<lg) <= n; lg++)
	{
		int dl = 1<<lg;
		REP(i, n - dl + 1) pairs[i] = MP(MP(ids[lg-1][i], ids[lg-1][i+dl/2]), i);
		
		sort(pairs, pairs+n-dl+1);
		int new_id = 1;
		REP(i, n - dl + 1)
		{
			if(i > 0 && pairs[i-1].ST != pairs[i].ST) ++new_id;
			ids[lg][pairs[i].ND] = new_id;
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

bool compare(int a1, int a2, int len)
{
	if(len == 0) return true;
	int lg = logs[len], dl = 1<<lg;
	int b1 = a1 + len - 1, b2 = a2 + len - 1;
	cout<<"len: "<<len<<" lg: "<<lg<<" dl: "<<dl<<"\n";
	cout<<"a1: "<<a1<<" a2: "<<a2<<" b1: "<<b1-dl+1<<" b2: "<<b2-dl+1<<"\n";
	cout<<ids[lg][a1]<<" "<<ids[lg][a2]<<" "<<ids[lg][b1-dl+1]<<" "<<ids[lg][b2-dl+1]<<"\n";
	return (ids[lg][a1] == ids[lg][a2]) && (ids[lg][b1-dl+1] == ids[lg][b2-dl+1]);
}

void findrep(int len)
{
	vector< pair<PII, int> > pairs;
	int lg = logs[len], dl = 1 << lg;
	REP(i, n-len+1) pairs.PB(MP(MP(ids[lg][i], ids[lg][i+len-dl]), i));
	sort(ALL(pairs));
	for(auto it: pairs) cout<<"("<<it.ST.ST<<", "<<it.ST.ND<<") ";
	//~ REP(i, SIZE(pairs))
	//~ {
		//~ if(i > 0 && pairs[i].ST == pairs[i-1].ST) cout<<pairs[i].ND<<" ";
	//~ }
	
}

//~ void divscalc(int x)
//~ {
	//~ if(odw[x]) return;
	//~ odw[x] = 1;
	//~ for(int i = 1; i*i<=x; i++)
	//~ {
		//~ if(x%i==0) divs[x].PB(i);
	//~ }
	//~ int k = SIZE(divs[x]);
	//~ FORD(i, k-1, 1) divs[x].PB(x/divs[x][i]);
	//~ for(int i: divs[x]) cout<<i<<" ";
	//~ cout<<endl;
//~ }


int main()
{
	ios::sync_with_stdio(0);
	//~ cin>>n;
	cin>>s;
	n = SIZE(s);
	logcalc();
	build_KMR(s);
	
	//~ FOR(i, 1, n) cout<<logs[i]<<" ";
	//~ cout<<"\n";
	
	for(int lg = 0; (1<<lg) <= n; lg++)
	{
		REP(i, n) cout<<ids[lg][i]<<" ";
		cout<<"\n";
	}
	
	cin>>q;
	FOR(it, 1, q)
	{
		cin>>a;//>>b>>c;
		findrep(a);
		//~ cout<<compare(a, b, c)<<"\n";
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

