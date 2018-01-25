#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
const int K = 1420;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define PB push_back
#define PP pop_back
#define DEBUG(s) s

int n, ajkc;
int kol[MAXN];

void kolcalc()
{
	FOR(i, 1, n)
	{
		if(i % 2 == 1) kol[i] = i*(i-1)/2;
		else kol[i] = (i*(i-1)+i)/2;
		ajkc = i;
		if(kol[i] >= n) break;
	}
}

void cyklcalc(int s)
{
	/*tworzenie grafu*/
	vector<int> cykl;
	int g[s+1][s+1];	
	
	FOR(i, 1, s) FOR(j, 1, s) g[i][j] = 0;

	if(s % 2 == 0) 
	for(int i = 1; i < s; i+=2)
	{
		g[i][i+1]++;
		g[i+1][i]++;
	}
	
	FOR(i, 1, s)
	FOR(j, i+1, s)
	{
		g[i][j]++;
		g[j][i]++;
	}
	
	DEBUG(
	FOR(i, 1, s)
	{
		FOR(j, 1, s) cout<<g[i][j]<<" ";
		cout<<"\n";
	} )
	
	//~ return cykl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	kolcalc();
	cyklcalc(ajkc);
	
	//~ DEBUG(FOR(i, 1, ajkc) cout<<i<<" "<<kol[i]<<endl;)
	return 0;
}

