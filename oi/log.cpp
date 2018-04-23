/*Logistyka XXIV OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 1e6+1;

const int M = 1 << 20;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FOR(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) s

int n, m, a, b, c;
pair<int, LL> Tree[2*M];
int dist[MAXN];

pair<char, PII> zap[MAXN];
VI vals;
unordered_map<int, int> mapa;

void init()
{
	sort(ALL(vals));
	int cnt = 1;

	REP(i, SIZE(vals))
	{
		if(i > 0 && vals[i] != vals[i-1]) ++cnt;
		mapa[vals[i]] = cnt;
	} 
}

void insert(int a, int v)
{
	int a1 = mapa[a] + M;
	
	while(a1 >= 1)
	{
		Tree[a1].ST += v;
		Tree[a1].ND += LL(v) * a;
		a1/=2;
	}
}

void update(int k, int a)
{
	insert(dist[k], -1);
	insert(a, 1);
	dist[k] = a;
}

LL greq(int a)
{
	int a1 = mapa[a] + M, b1 = 2*M-1;
	
	LL res = 0;
	
	while(a1 <= b1)
	{
		if(a1 % 2 == 1) res+=Tree[a1++].ST;
		if(b1 % 2 == 0) res+=Tree[b1--].ST;
		a1/=2; b1/=2;
	}
	
	res*=a;
	return res;
}

LL le(int a)
{
	int a1 = M, b1 = mapa[a] - 1 + M;
	
	LL res = 0;
	
	while(a1 <= b1)
	{
		if(a1 % 2 == 1) res+=Tree[a1++].ND;
		if(b1 % 2 == 0) res+=Tree[b1--].ND;
		a1/=2; b1/=2;
	}
	return res;
}

bool answer(int c, int s)
{
	LL res = LL(c) * LL(s);
	res -= le(s);
	res -= greq(s);
	return res <= 0;
}

int main()
{
	//~ ios::sync_with_stdio(0);
	cin>>n>>m;
	FOR(i, 1, m) 
	{
		cin>>zap[i].ST>>zap[i].ND.ST>>zap[i].ND.ND;
		vals.PB(zap[i].ND.ND);
	}
	
	init();
	
	FOR(i, 1, m)
	{
		if(zap[i].ST == 'U')
		{
			update(zap[i].ND.ST, zap[i].ND.ND);
		}
		else
		{
			cout<<(answer(zap[i].ND.ST, zap[i].ND.ND) ? "TAK" : "NIE")<<"\n";
		}
	}

	return 0;
}

/*

3 8
U 1 5
U 2 7
Z 2 6
U 3 1
Z 2 6
U 2 2
Z 2 6
Z 2 1

*/
