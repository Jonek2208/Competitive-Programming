/*Sciezki*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef vector<int> VI;

const int INF = 1000000007;
const int MAXN = 1001;
const int ER = 1000000;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define SIZE(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

#define DEBUG(s) s

int n, k;

int M[MAXN][MAXN];

int sito[ER+1];

VI g[MAXN];

void edge(int a, int b)
{
	g[a].PB(b);
	g[b].PB(a);
}

VI factors, primes;

void sitocalc(int x)
{
	for(int i = 2; i * i <= x; ++i)
	if(!sito[i]) for(int j = i * i; j <= x; j+=i) if(!sito[j]) sito[j] = i;
	
	FOR(i, 2, x) if(!sito[i]) primes.PB(i);
}

bool factcalc(int x)
{
	for(auto p: primes)
	{
		
		while(x % p == 0)
		{
			factors.PB(p);
			x /= p;
		}
		if(x == 1) break;
	}
	
	return x == 1;
}



int logarytm(int x)
{
	int cnt = 0;
	while(x>1)
	{
		if(x % 2 == 1) return -1;
		x/=2;
		++cnt;
	}
	
	return cnt;
}

bool flag = true;

int main()
{
	ios::sync_with_stdio(0);
	cin>>k;
	
	int lg = logarytm(k);
	if(lg != -1)
	{
		n = 3*lg+1;
		
		int last = 1;
		
		for(int i = 3; i <= n; i+=3)
		{
			edge(last, i);
			edge(last, i+1);
			last = i+2;
			if(last <= n)
			{
				edge(last, i);
				edge(last, i+1);
			}
		}
		
		edge(2, n);
		edge(2, n-1);
	}
	else
	{
		sitocalc(min(ER, k));
		flag = factcalc(k);
		if(flag)
		{
			int s = SIZE(factors)+1;
			for(auto p: factors) s+=p;
			
			if(s <= 1000)
			{
				n = s;
				int curr = 3, last = 1;
				
				for(auto p: factors)
				{
					REP(i, p)
					{
						edge(last, curr + i);
					}
					
					last = curr+p;
					
					if(last > n) last = 2;
					
					REP(i, p)
					{
						edge(last, curr + i);
					}
					
					curr+=p+1;
				}
				
			}
			else flag = false;
		}
	}
	
	//~ FOR(i, 1, n)
	//~ {
		//~ cout<<i<<" : ";
		//~ for(auto j: g[i]) cout<<j<<" ";
		//~ cout<<endl;
	//~ }
	
	FOR(i, 1, n) for(auto j: g[i]) M[i][j] = 1;
	
	/*listy na macierz*/
	if(!flag) cout<<"NIE\n";
	else
	{
		cout<<n<<"\n";
		FOR(i, 1, n)
		{
			FOR(j, 1, n) cout<<(M[i][j] ? "T" : "N");
			cout<<"\n";
		}
	}
	return 0;
}

