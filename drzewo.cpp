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
		sub = new int[2*s];
		REP(i, 2*s) load[i] = sub[i] = 0;	
	}
	
	~Tree()
	{
		delete[]load;
		delete[]sub;		
	}
	
	void insert(int a, int b, int v)
	{
		a+=s; b+=s;
		int len = 1;
		
		load[a]+=v;
		sub[a]+=v;
		
		if(a!=b)
		{
			load[b]+=v;
			sub[b]+=v;
		}
		
		while(a>=1)
		{
			if(a < b-1)
			{
				if(a%2 == 0)
				{
					load[a+1]+=v;
					sub[a+1]+=v*len;
				}
				if(b%2 == 1)
				{
					load[b-1]+=v;
					sub[b-1]+=v*len;
				}
			}
			
			if(a < s)
			{
				sub[a] = sub[2*a] + sub[2*a+1] + load[a]*len;
				sub[b] = sub[2*b] + sub[2*b+1] + load[b]*len;
			}
			
			a/=2; b/=2;
			len*=2;	
		}
	}
	
	int query(int a, int b)
	{
		a+=s; b+=s;
		int alen = 1, blen = (a==b ? 0 : 1), len = 1, res = 0;
		
		while(a>=1)
		{
			res+=load[a]*alen + load[b]*blen;
			
			if(a < b-1)
			{
				if(a%2 == 0)
				{
					res+=sub[a+1];
					alen+=len;
				}
				if(b%2 == 1)
				{
					res+=sub[b-1];
					blen+=len;
				}
			}
			
			a/=2; b/=2;
			len*=2;	
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
			cin >> b >> c >>d;
			drzewo.insert(b,c,d);
			printf("insert %d on (%d %d)\n", d, b, c);
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
