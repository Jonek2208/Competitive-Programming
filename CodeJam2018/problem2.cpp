#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 1e5+1;

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

#define DEBUG(s) s

int z, n;
int tab[MAXN], tab0[MAXN], tab1[MAXN];


int main()
{
	ios::sync_with_stdio(0);
	cin>>z;
	
	FOR(test, 1, z)
	{
		int index = -1;
		int n0 = 0, n1 = 0;
		cin>>n;
		REP(i, n) cin>>tab[i];
		REP(i, n)
		{
			if(i % 2 == 0) 
			{
				tab0[i/2] = tab[i];
				n0++;
			}
			else 
			{
				tab1[i/2] = tab[i];
				n1++;
			}
		}
		sort(tab0, tab0 + n0);
		sort(tab1, tab1 + n1);
		
		int t1 = 0, t2 = 0;
		REP(i, n)
		{
			if(i % 2 == 0) 
			{
				t2 = tab0[i/2];
			}
			else 
			{
				t2 = tab1[i/2];
			}
			
			if(i > 0 && t1 > t2)
			{
				index = i-1;
				break;
			}
			t1 = t2;
		}
		
		

		cout<<"Case #"<<test<<": ";
		if(index < 0) cout<<"OK\n";
		else cout<<index<<"\n";
	}

	
	return 0;
}

/*
3
5
5 6 8 4 3
10
5 6 8 4 3 5 6 8 3 4
3
8 9 7

*/

