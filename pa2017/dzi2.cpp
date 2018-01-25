#include "dzialka.h"
#include "message.h"
#include<bits/stdc++.h>


using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MX = 75002;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

const int pack = 40000;
bool tab[MX][MX];
int n, m, k, e, len, buf;
int g1[MX], g2[MX], rg1[MX], rg2[MX];
LL sum, rsum, curr;
int h, rh;

struct Krotka
{
	int k, g1, g2;
	LL val;
	Krotka(){}
	Krotka(int _k, int _g1, int _g2, LL _val) : k(_k), g1(_g1), g2(_g2), val(_val){}
	Krotka(int _k, int _g1, LL _val) : k(_k), g1(_g1), val(_val){}
};

int main()
{
	ios::sync_with_stdio(0);
	
	n = GetFieldHeight();
	m = GetFieldWidth();
	k = NumberOfNodes();
	e = MyNodeId();
	len = (n-1)/k + 1;
	h = min( (e+1)*len, n) - e*len;
	
	FOR(i, e*len+1, e*len+h)
	FOR(j, 1, m)
	{
		buf = IsUsableCell(i-1, j-1);
		tab[i][j] = buf;
	}	
	
	stack<Krotka> stos;
	bool pop;
	Krotka tmp;
	
	FOR(i, e*len+1, e*len+h)
	{
		curr = 0;
		FOR(j, 1, m+1)
		{
			pop = false;
			if(!tab[i][j]) g1[j] = 0;
			g1[j] += tab[i][j];
			//~ cout<<g[j]<<" ";
			while(!stos.empty() && stos.top().g1 > g1[j])
			{
				tmp = stos.top();
				//~ cout<<"("<<tmp.k<<", "<<tmp.g1<<", "<<tmp.val<<") ";
				curr-=tmp.val;
				stos.pop();
				pop = true;
			}
			
			if(g1[j] > 0)
			{
				if(pop) 
				{	
					stos.push(Krotka(tmp.k, g1[j], (LL)(j-tmp.k+1)*(LL)g1[j]));
				}
				else 
				{
					stos.push(Krotka(j, g1[j], (LL)g1[j]));
				}
				curr+=(LL)stos.top().val;
			}
			
			sum+=(LL)curr;
		}
		//~ cout<<sum<<endl;
	}
	
	FORD(i, e*len+h, e*len+1)
	{
		FOR(j, 1, m+1)
		{
			if(!tab[i][j]) g2[j] = 0;
			g2[j] += tab[i][j];
		}
	}
	
	int pot = 1;
	while(e%(pot*2) == 0 && (pot*2) <= m)
	{
		if(e+pot < m)
		{
			Receive(e+pot);
			rh = GetInt(e+pot);
			rsum = GetLL(e+pot);
			FOR(j, 1, m+1)
			{
				if((j-1)%pack == 0) Receive(e+pot);
				g1[j] = GetInt(e+pot);
			}
			FOR(j, 1, m+1)
			{
				if((j-1)%pack == 0) Receive(e+pot);
				g2[j] = GetInt(e+pot);
			}
			
			curr = 0;
			FOR(j, 1, m+1)
			{
				pop = false;
				while(!stos.empty() && (stos.top().g1 > g2[j] || stos.top().g2 > rg1[j]))
				{
					tmp = stos.top();
					curr = tmp.val;
					stos.pop();
					pop = true;
				}
				if(g2[j] > 0 && rg1[j] > 0)
				{
					if(pop) 
					{	
						stos.push(Krotka(tmp.k, g2[j], rg1[j], (LL)(j-tmp.k+1)*(LL)g2[j]*(LL)rg1[j]));
					}
					else 
					{
						stos.push(Krotka(j, g2[j], rg1[j], (LL)g2[j] * (LL)rg1[j]));
					}
					
					curr+=(LL)stos.top().val;
				}
				
				sum+=curr;
			}
			
			FOR(j, 1, m+1)
			{
				g2[j] = (rg2[j] == rh ? g2[j] + rh : rg2[j]);
				g2[j] = (g1[j] == h ? rg1[j] + h : g1[j]);
			}
			h+=rh;
		}
	}
	
	if(e>0)
	{
		PutInt(e/pot - 1, h);
		PutLL(e/pot - 1, sum);
		Send(e/pot-1);
		
		FOR(j, 1, m+1)
		{
			PutInt(e/pot-1, g1[j]);
			if(j%pack == 0) Send(e/pot-1);
		}
		
		FOR(j, 1, m+1)
		{
			PutInt(e/pot-1, g2[j]);
			if(j%pack == 0) Send(e/pot-1);
		}
	}
	else if(e == 0)
	{
		cout<<sum<<endl;	
	}	
	
	return 0;
}

/*
20 20
1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 1 1 
1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 0 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 0 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 0 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 
*/

/*
8 8
1 1 1 1 0 1 1 1 
0 1 1 0 1 1 1 1 
1 1 1 1 1 0 1 1
1 0 1 1 1 1 0 0 
1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1
1 1 1 1 1 0 1 1
*/
/*
8 4
1 1 1 1 0 1 1 1 
0 1 1 0 1 1 1 1 
1 1 1 1 1 0 1 1
1 0 1 1 1 1 0 0 
8 4 
1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1
1 1 1 1 1 0 1 1
*/

/*
3 3
1 1 1
0 1 0
1 1 1 
*/

