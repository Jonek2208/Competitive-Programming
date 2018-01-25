#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000007;
const int MAXN = 10000001;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

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

int n;

const int A = 10;
const int MA = 30;

int tab[3][A];
int num[] = {2, 3, 5};

SI ajkc;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	
	REP(j, 3)
	{
		int cnt = 1;
		REP(i, A)
		{
			tab[j][i] = cnt;
			cnt *= num[j];
		}
	}
	
	REP(i, A)
	{
		REP(j, A)
		{
			REP(k, A)
			{
				ajkc.insert(tab[0][i] * tab[1][j] * tab[2][k]);
			}
		}
	}
	
	REP(j, 3)
	{
		REP(i, A) cout<<tab[j][i]<<" ";
		cout<<endl;
	}
	
	FOREACH(it, ajkc) if(*it>0) cout<<*it<<" ";
	
	return 0;
}
