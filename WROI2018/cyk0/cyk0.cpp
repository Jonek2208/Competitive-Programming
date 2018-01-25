/*Kolorowanie cyklu*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
const int K = 1420;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define SIZE(c) (int)(c.size())
#define DEBUG(s) s

int n, ajkc;
int kol[K]; //0MB
short odw[K][K]; //8MB
int pom[MAXN][2];//8MB
vector<short> g[K]; //8MB
short cykl[MAXN]; //8MB
int cnt = 0;

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

void pomcalc()
{
	int it = 2, last = 2;
	FOR(i, 2, n)
	{
		if(kol[it] > last && ( ( (i - kol[it]) >= 2) || (it%2==0) ) ) last = kol[it];
		pom[i][0] = last;
		pom[i][1] = i - last;
		
		if(kol[it+1] == i)
		{
			pom[i][0] = ++it;
			pom[i][1] = 0;
		}
	}
}

void DFS(int v)
{
	
	vector<int> stos;
	stos.PB(v);
	
	while(!stos.empty())
	{
		v = stos.back();
		//~ cout<<"v"<<" "<<v<<endl;;
		if(!g[v].empty())
		{
			int w = g[v].back();
			//~ cout<<"w"<<" "<<w<<endl;;
			g[v].PP();
			if(odw[v][w] && odw[v][w])
			{
				odw[v][w]--;
				odw[w][v]--;
				stos.PB(w);
			}
			
		}
		else
		{
			cykl[cnt++] = v;
			stos.PP();
		}
	}	
		
	
}

void cyklcalc(int s, bool rmc = false)
{
	//~ cout<<"s"<<" "<<s<<endl;
	/*tworzenie grafu*/
	FOR(i, 1, s) g[i].clear();
	FOR(i, 1, s) FOR(j, 1, s) odw[i][j] = 0;
	
	if(s % 2 == 0)
	{
		for(int i = 1; i < s; i+=2)
		{
			if(rmc && i == s-1)
			{
				g[1].PB(i);
				g[i].PB(1);
				odw[1][i]++;
				odw[i][1]++;
				g[1].PB(i+1);
				g[i+1].PB(1);
				odw[1][i+1]++;
				odw[i+1][1]++;
			}
			else
			{
				g[i].PB(i+1);
				g[i+1].PB(i);
				odw[i][i+1]++;
				odw[i+1][i]++;
			}
		}

	}
	
	FOR(i, 1, s)
	FOR(j, i+1, s)
	{		
		g[i].PB(j);
		g[j].PB(i);
		odw[i][j]++;
		odw[j][i]++;
	}
	
	DEBUG(
	FOR(i, 1, s)
	{
		FOR(j, 1, s) cout<<odw[i][j]<<" ";
		cout<<"\n";
	} )
	
	DFS(1);
	cnt--;
}



int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	kolcalc();
	pomcalc();
	DEBUG(cout<<"wynik:\n";)
	/*wypisywanie wyniku*/
	cout<<(kol[ajkc] == n ? ajkc : pom[pom[n][0]][0])<<"\n";
	
	int curr = n;
	while(curr)
	{
		//~ cout<<curr<<endl;
		if(pom[curr][1] == 0) cyklcalc(pom[curr][0]);
		else if(pom[curr][1] == 1) cyklcalc(pom[curr][0], 1);
		else cyklcalc(pom[pom[curr][0]][0]);
		curr = pom[curr][1];
	}
	
	REP(i, n) cout<<cykl[i]<<" ";
	DEBUG(cout<<"\n"; FOR(i, 1, n) cout<<pom[i][0]<<" "<<pom[i][1]<<"\n";)
	DEBUG(FOR(i, 1, ajkc) cout<<i<<" "<<kol[i]<<endl;)
	return 0;
}
