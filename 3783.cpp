#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

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
#define MAXN 1001
#define MXT (1<<20)

int tab[MAXN][MAXN];
int M;

//struct query
//{
	//int x, y, z;
	
//};


struct Tree
{
	int *load, s, k;
	
	Tree(int x)
	{
		k = x;
		s = (1<<k);
		load = new int[2*s];
		REP(i, 2*s)
		load[i]=0;
	}
	
	~Tree()
	{
		delete[] load;
	}
	
	void insert(int a, int b, int v)
	{
		a+=s-1; b+=s-1;
		
		while(a < b)
		{
			if(a % 2 == 1)
			load[a] = max(load[a++], v);
			if(b % 2 == 0)
			load[b] = max(load[b--], v);
			a >>= 1;
			b >>= 1;
		}
		
		if(a==b)
		load[a] = max(load[a], v);
		
	}
	
	int query(int a)
	{
		int mx = 1;
		a+=s-1;
		while(a>=1)
		{
			mx = max(mx, load[a]);
			a>>=1;		
		}
		
		return mx;
	}	
};


int n, q, x, y, k;
char z;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	
	M = (int)log2(n-1) + 1;
	Tree TX(M);
	Tree TY(M);
	
	REP(it, q)
	{
		cin>>x>>y>>z;
		
		if(z == 'U')
		{
			k = y - TX.query(x) + 1;
			TY.insert(y-k+1, y, x+1);
			TX.insert(x, x, y+1);
			cout<<k<<endl;
		}
		else
		{
			k = x - TY.query(y) + 1;
			TX.insert(x-k+1, x, y+1);
			TY.insert(y, y, x+1);
			cout<<k<<endl;
		}
		
	}
	
	
	return 0;
}
