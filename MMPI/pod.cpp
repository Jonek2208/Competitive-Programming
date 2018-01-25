#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 100001;
const int M = 1 << 17;

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

int n, m, rmc;
int tab[MAXN];
PII sorted[MAXN];
int Tree[2*M];

void insert(int a, int b, int v)
{
	a+=M; b+=M;
	
	while(a <= b)
	{
		if(a%2 == 1) Tree[a++] += v;
		if(b%2 == 0) Tree[b--] += v;
		a/=2; b/=2;
	}
}

int query(int a)
{
	int res = 0;
	while(a >= 1)
	{
		res+=Tree[a];
		a/=2;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	FOR(i, 1, n) 
	{
		cin>>tab[i];
		sorted[i] = MP(tab[i], i);
	}
	
	sort(tab+1, tab+n+1);
	
	FOR(i, 1, n) tab[sorted[i].ND] = i;
	//~ FOR(i, 1, n) cout<<sorted[i].ST<<" "<<sorted[i].ND<<endl;
	
	FOR(i, 1, n) insert(i, i, sorted[i].ST);
	FOR(i, 1, n) cout<<query(i)<<" ";
	REP(x, m)
	{
		cin>>rmc;
		
		int poc = 1, kon = n, sr, wyn = 0;
	
		while(poc <= kon)
		{
			sr = (poc + kon) / 2;
			if(query(sr) > rmc)
			{
				kon = sr - 1;
			}
			else
			{
				wyn = sr;
				poc = sr + 1;
			}
		}
		
		insert(1, wyn, 1);
	}
	
	FOR(i, 1, n) cout<<query(tab[i])<<" ";
	
	
	return 0;
}


