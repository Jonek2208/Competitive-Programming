#include<bits/stdc++.h>
using namespace std;

const int INF = -1000000001;
const int MAXN = 1000001;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

struct Tree
{
	int *load, M;
	Tree(int n)
	{
		M = 1 << ((int)log2(n-1)+1);
		load = new int[2*M];
		
		REP(i, 2*M)
		{
			load[i] = -1;
		}
	}
	
	~Tree() 
	{ 
		delete [] load;
	}
	
	void insert(int a, int b, int u, int x, int y, int v)
	{
		if(y < a || b < x) return;
		if(a <= x && y <= b)
		{
			load[u] = v;
			return;
		}
		int d = (x+y)/2;
		if(load[u] != -1)
		{
			load[2*u] = load[u];
			load[2*u+1] = load[u];
			load[u] = -1;
		}
		insert(a, b, 2*u, x, d, v);
		insert(a, b, 2*u+1, d+1, y, v);
	}
	
	void insert(int a, int b, int v)
	{
		insert(a, b, 1, 0, M-1, v);
	}

	int query(int a)
	{
		int res = -1;
		a+=M;
		
		while(a>=1)
		{
			res = (load[a] == -1 ? res : load[a]);
			a/=2;
		}
		return res;
	}
	
	void wypisz()
	{
		//~ cout<<M<<endl;
		for(int i = 1; i < 2*M; i*=2)
		{
			for(int j = 0; j < i; j++)
			{
				cout<<load[i+j]<<" ";
			}
			cout<<"\n";
		}
	}
};

int n, a, b, c, d;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	Tree drzewo(n);
	
	while(cin>>a)
	{
		switch(a)
		{
			case 0:
			cin>>b>>c>>d;
			drzewo.insert(b, c, d);
			printf("insert(%d, %d, %d)\n", b, c, d);
			break;
			
			case 1:
			cin>>b;
			printf("query(%d) = %d\n", b, drzewo.query(b));
			break;
			
			case 2:
			drzewo.wypisz();
			break;
		}
	}
	return 0;
}
