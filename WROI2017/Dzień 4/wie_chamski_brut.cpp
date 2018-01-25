#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 100001;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, k, a, b;
int tab[MAXN];
int pref[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n) cin>>tab[i];
	
	int res = 0;
	int rmc;
	
	for(int mask = 0; mask < (1<<n); mask++)
	{
		int pop = INF, poc = 0, sum = 0;
		bool dasie = true;
		for(int i = 1; i <= n; i++)
		{
			sum+=tab[i];
			if(sum > pop) 
			{
				dasie = false;
				break;
			}
			
			if(mask&(1<<i))
			{
				
				poc = i+1;
				pop = sum;
				sum = 0;
			}
		}
		if(dasie) 
		{
			printf("%x \n", rmc);
			cout<<res<<endl;
			if(res < __builtin_popcountl(mask))
			{
				res = __builtin_popcountl(mask);
				rmc = mask;
			}
		}
	}
	
	cout<<res<<endl;
	printf("%x \n", rmc);
	return 0;
}

/*
3
1 2 3

6
2 3 1 2 4 5

15
17 9 16 19 20 16 15 16 4 20 10 18 2 14 14 


*/
