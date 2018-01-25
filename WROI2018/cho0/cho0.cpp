/*Choinka Wzglednie Pierwsza*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1000000007;
const int A = 10000001;
const int MAXN = 100001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FOR(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

#define DEBUG(s) s
int n;
int tab[MAXN];
int ojce[MAXN];
int lewy[MAXN], prawy[MAXN];
int sito[MAXN];
int ajkc;

void sitocalc()
{
	for(int i = 2; i * i <= ajkc; ++i)
	if(!sito[i]) for(int j = i*i; j <= ajkc; j+=i) if(!sito[j]) sito[j] = i;
}

int gcd(int a, int b)
{
	while(b) swap(a%=b, b);
	return a;
}

bool DFSx(int a, int b, int u)
{
	DEBUG(cout<<a<<" "<<b<<" "<<u<<"\n";)
	
	int v = -1;
	
	FOR(i, a, b)
	{
		bool wzgl = true;
		FOR(j, a, b)
		{
			if(j!=i && gcd(tab[i], tab[j]) != 1)
			{
				wzgl = false;
				break;
			}
			
		}
		if(wzgl)
		{
			v = i;
			break;
		}
	}
		
	if(v == -1) return false;
	
	
	DEBUG(cout<<v<<endl;)
	ojce[v] = u;
	if(a < v)
	DFSx(a, v-1, v);
	if(v < b)
	DFSx(v+1, b, v);
	
	
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n) 
	{
		cin>>tab[i];
		ajkc = max(ajkc, tab[i]);
	}
	
	sitocalc();
	
	DEBUG(FOR(i, 1, ajkc) cout<<sito[i]<<" "; cout<<endl;)

	bool dasie = DFSx(1, n, 0);
	if(!dasie) cout<<"NIE\n";
	else
	{
		FOR(i, 1, n) cout<<ojce[i]<<" ";
	}
	return 0;
}

/*

7
7 3 11 2 13 5 17

6
2 7 15 8 9 5

*/
