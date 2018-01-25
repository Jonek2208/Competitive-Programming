#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
const int MAXN = 10000001;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int t;
LL n, a;

int sito[MAXN];
int czynniki[MAXN];
int tmp[MAXN];
vector<int> primes;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>t;
	
	for(int i = 2; i*i <= n; i++)
	{
		if(!sito[i])
		{
			for(int k = i*i; k <= n; k+=i)
			if(!sito[k]) sito[k] = i;
		}
	}
	
	FOR(i, 2, n) if(!sito[i]) primes.PB(i);
	
	FOR(i, 2, n)
	{
		LL x = i;
		LL k = 0;
		while(sito[x] > 0)
		{
			tmp[k++] = sito[x];
			x /= sito[x];
		}
		
		tmp[k++] = x;
		
		//~ REP(j, k) cout<<tmp[j]<<" ";
		//~ cout<<"\n";
		REP(j, k) czynniki[tmp[j]]++;
	}
	
	REP(j, t)
	{
		cin>>a;
		if(a < 0) a = -a;
		int k = 0;
		
		for(int p: primes)
		{
			while(a % (LL)p == 0)
			{
				a /= (LL)p;
				tmp[k++] = (LL)p;
				//~ cout<<p<<endl;
			}
			
			if(a == 1) break;
		}
		tmp[k] = 0;
		
		int cnt = 1;
		bool res = (a==1);
		if(res)
		{
			FOR(i, 1, k)
			{
				if(tmp[i] == tmp[i-1])
				{
					cnt++;
				}
				else
				{
					//~ cout<<"("<<cnt<<", "<<tmp[i-1]<<")\n";
					if(czynniki[tmp[i-1]] < cnt)
					{
						res = false;
						break;
					}
					cnt = 1;
				}
			}
		}
		
		if(res) cout<<"TAK\n";
		else cout<<"NIE\n";
	}
	
	//~ for(int it: primes) cout<<it<<endl;
	
	
	
	//~ cout<<gcd(n, m)<<"\n";

	return 0;
}

/*
6 3
2
6
34

5490644 2
-2817835836533845005
2817835836533845005
*/
