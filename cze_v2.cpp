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
#define MAXQ 200000
#define MXT (1<<20)


int M;

struct query
{
	int x, y;
	char z;
};


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
		
		while(a <= b)
		{
			if(a % 2 == 1)
			{
				load[a] = max(load[a], v);
				a++;
			}
			if(b % 2 == 0)
			{
				load[b] = max(load[b], v);
				b--;
			}
			a >>= 1;
			b >>= 1;
		}
		
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

unordered_map<int, int> mapaX, mapaY;

query zapytania[MAXQ];
set<int> posX, posY;

int n, q, x, y, k;
char z;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	
	M = (int)log2(2*q) + 1;
	Tree TX(M);
	Tree TY(M);
	
	posX.insert(1);
	posY.insert(1);	
	
	REP(i, q)
	{
		cin>>zapytania[i].x>>zapytania[i].y>>zapytania[i].z;
		posX.insert(zapytania[i].x);
		posX.insert(zapytania[i].x+1);
		posY.insert(zapytania[i].y);
		posY.insert(zapytania[i].y+1);
	}
	
	//przenumerowanie wartosci
	
	int cntX = 1, cntY = 1;
	
	FOREACH(it, posX)
	{
		mapaX[*it] = cntX++;
	}
	
	FOREACH(it, posY)
	{
		mapaY[*it] = cntY++;
	}
	
	//zapytania
	
	REP(it, q)
	{
		x = zapytania[it].x;
		y = zapytania[it].y;
		z = zapytania[it].z;
		
		if(z == 'U')
		{
			k = y - TX.query(mapaX[x]) + 1;
			TY.insert(mapaY[y-k+1], mapaY[y], x+1);
			TX.insert(mapaX[x], mapaX[x], y+1);
		}
		else
		{
			k = x - TY.query(mapaY[y]) + 1;
			TX.insert(mapaX[x-k+1], mapaX[x], y+1);
			TY.insert(mapaY[y], mapaY[y], x+1);
			
		}
		
		cout<<k<<endl;
	}
	
	return 0;
}
