/*Meteory XVIII OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 3e5+1;

const int M = 1<<20;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) 

int n, m, k, a, b, c;

int o[MAXN], p[MAXN];
VI stacje[MAXN];
struct{int a, b; LL v;} zap[MAXN];
struct Country{int poc, kon, pan;};
Country bs[MAXN];
bool fin[MAXN];
int res[MAXN];

int Tree[2*M];

void insert(int a, int b, int v)
{
	a+=M; b+=M;
	
	while(a <= b)
	{
		if(a % 2 == 1) 
		{
			Tree[a] = min(Tree[a], INF);
			Tree[a++] += v;
		}
		if(b % 2 == 0) 
		{
			Tree[b] = min(Tree[b], INF);
			Tree[b--] += v;
		}
		a/=2; b/=2;
	}
	
}

LL query(int a)
{
	a+=M;
	LL res = 0;
	while(a >= 1)
	{
		res+=Tree[a];
		if(res > INF) res = INF;
		a/=2;
	}
	
	return res;
}

void simulate(int nr)
{
	if(zap[nr].a <= zap[nr].b)
	{
		insert(zap[nr].a, zap[nr].b, zap[nr].v);
	}
	else
	{
		insert(zap[nr].a, m, zap[nr].v);
		insert(1, zap[nr].b, zap[nr].v);
	}
}

bool cmp(const Country &c1, const Country &c2)
{
	return ((c1.poc+c1.kon)/2) < ((c2.poc+c2.kon)/2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	FOR(i, 1, m) cin>>o[i];
	FOR(i, 1, m) stacje[o[i]].PB(i);
	FOR(i, 1, n) cin>>p[i];
	
	cin>>k;
	FOR(i, 1, k) cin>>zap[i].a>>zap[i].b>>zap[i].v;
	
	/*kraje do binsearcha*/
	REP(i, n)
	{
		bs[i].poc = 1;
		bs[i].kon = k;
		bs[i].pan = i+1;
	}
	
	DEBUG(
	REP(i, n) cout<<"<"<<bs[i].poc<<", "<<bs[i].kon<<", "<<bs[i].pan<<", "<<p[bs[i].pan]<<">\n";
	)
	
	FOR(i, 1, n) res[i] = -1;
	
	int active = n;
	
	while(active)
	{
		sort(bs, bs+n, cmp);
		REP(i, 2*M) Tree[i] = 0;
		int sim = 0;
		REP(i, n)
		{
			if(bs[i].poc <= bs[i].kon)
			{
				int sr = (bs[i].poc + bs[i].kon)/2;
				while(sim < sr) simulate(++sim);
				LL sum = 0;
				for(auto it: stacje[bs[i].pan]) 
				{
					if(sum < INF)
					sum+=query(it);
				}
				DEBUG(cout<<bs[i].pan<<" "<<sum<<"\n";)
				if(sum < p[bs[i].pan])
				{
					bs[i].poc = sr+1;
				}
				else 
				{
					res[bs[i].pan] = sr;
					bs[i].kon = sr-1;
				}
			}
			else if(!fin[bs[i].pan]) 
			{
				--active;
				fin[bs[i].pan] = true;
			}	
		}
		DEBUG(
		REP(i, n) cout<<"<"<<bs[i].poc<<", "<<bs[i].kon<<", "<<bs[i].pan<<", "<<p[bs[i].pan]<<">\n";
		)
	}
	
	FOR(i, 1, n) if(res[i] == -1) cout<<"NIE\n";
	else cout<<res[i]<<"\n";
	

	return 0;
}
/*
3 5
1 3 2 1 3
10 5 7
3
4 2 4
1 3 1
3 5 2

4 8 
1 3 2 1 3 4 4 1
11 3 10 8
5
5 1 2
1 4 3
2 6 2
8 3 4
3 6 1







*/
