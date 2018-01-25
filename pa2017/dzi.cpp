#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MX = 750;

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

const int k = 10;
int n, m, x;
bool tab[MX][MX];
int g[MX];

struct Krotka
{
	int k, g1;
	LL val;
	Krotka(){}
	//~ Krotka(int _k, int _g1, int _g2 = 0) : k(_k), g1(_g1), g2(_g2){}
	Krotka(int _k, int _g1, LL _val) : k(_k), g1(_g1), val(_val){}
	
};

int main()
{
	ios::sync_with_stdio(0);
	cin>>m>>n;
	FOR(i, 1, n)
	FOR(j, 1, m)
	{
		cin>>x;
		tab[i][j] = x;
	}	
	
	//wypisywanie
	//~ FOR(i, 1, n)
	//~ {
		//~ FOR(j, 1, m)
		//~ {
			//~ cout<<tab[i][j]<<" ";
		//~ }	
		//~ cout<<"\n";
	//~ }
	
	stack<Krotka> stos;
	bool pop;
	Krotka tmp;
	LL sum = 0, curr = 0;
	
	FOR(i, 1, n)
	{
		curr = 0;
		FOR(j, 1, m+1)
		{
			pop = false;
			if(!tab[i][j]) g[j] = 0;
			g[j] += tab[i][j];
			//~ cout<<g[j]<<" ";
			while(!stos.empty() && stos.top().g1 > g[j])
			{
				tmp = stos.top();
				//~ cout<<"("<<tmp.k<<", "<<tmp.g1<<", "<<tmp.val<<") ";
				curr-=(LL)tmp.val;
				stos.pop();
				pop = true;
			}
			
			if(g[j] > 0)
			{
				if(pop) 
				{	
					stos.push(Krotka(tmp.k, g[j], (LL)(j-tmp.k+1)*(LL)g[j]));
				}
				else 
				{
					stos.push(Krotka(j, g[j], (LL)g[j]));
				}
				curr+=(LL)stos.top().val;
			}
			
			sum+=(LL)curr;
		}
		//~ cout<<sum<<endl;
	}
	
	cout<<sum;
	
	
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
