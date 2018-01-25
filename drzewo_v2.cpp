#include <bits/stdc++.h>
using namespace std;

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

struct Tree
{
	int s, *load, *sub;
	
	Tree(int k)
	{
		s = 1<<k;
		load = new int[2*s];
		REP(i, 2*s) load[i] = 0;	
	}
	
	~Tree()
	{
		delete[]load;		
	}
	
	void insert(int a, int v)
	{
		a+=s;
		
		while(a>=1)
		{
			load[a]+=v;
			a/=2;
		}
	}
	
	int query(int a, int b)
	{
		a+=s; b+=s;
		int res = 0;
		
		while(a<=b)
		{	
			if(a%2 == 1) res+=load[a++];
			if(b%2 == 0) res+=load[b--];

			a/=2; b/=2;
		}
		
		return res;	
	}

};

int main()
{
	int a, b, c, d;
	
	Tree drzewo(3);
	
	while(cin>>a)
	{
		if(!a)
		{
			cin >> b >> c;
			drzewo.insert(b,c);
			printf("insert %d on(%d)\n", c, b);
		}
		else
		{
			cin >> b >> c;
			d = drzewo.query(b, c);
			printf("query on (%d %d) = %d\n", b, c, d);
		}
		
		
	}
	return 0;
}
