#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 500002;

const LL P = 31;
const LL MOD = 533600747;

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

#define DEBUG(s) 

int n, q, a, b;
string s;

LL h[MAXN];
LL mods[MAXN];
VI divs[MAXN];
bitset<MAXN> odw;

inline LL nr(char c)
{
	return c - 'a' + 1;
}

void hasz()
{
	mods[0] = 1;
	FOR(i, 1, n) mods[i] = (mods[i-1] * P) % MOD;
	
	h[n-1] = nr(s[n-1]);
	FORD(i, n-2, 0)
	{
		h[i] = (nr(s[i]) + h[i+1] * P) % MOD;
	}
	
	DEBUG(
	FOR(i, 0, n) cout<<mods[i]<<" "; cout<<endl;
	REP(i, n) cout<<h[i]<<" "; cout<<endl;
	)
}

inline LL gethasz(int a, int len)
{
	LL tmp = (h[a+len]*mods[len] - h[a]) % MOD;
	return (tmp >= 0 ? tmp : tmp+MOD);
}

inline bool compare(int a, int b, int len)
{
	int ok = b-a+1-len;
	DEBUG(cout<<gethasz(a, len)<<" "<<gethasz(a+ok, len)<<endl;)
	return (gethasz(a, len) == gethasz(a+ok, len));
}

void divscalc(int x)
{
	if(odw[x]) return;
	odw[x] = 1;
	for(int i = 1; i*i<=x; i++)
	{
		if(x%i==0) divs[x].PB(i);
	}
	int k = SIZE(divs[x]);
	FORD(i, k-1, 1) divs[x].PB(x/divs[x][i]);
}


int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	cin>>s;
	
	hasz();
	
	cin>>q;
	FOR(it, 1, q)
	{
		cin>>a>>b;
		a--; b--;
		int k = b-a+1;
		int res = k;
		divscalc(k);
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

