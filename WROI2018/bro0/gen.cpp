/*Choinka Wzglednie Pierwsza*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1000000007;
const int MAXN = 1000001;
const int Ml = 1 << 21;
const int M = 1 << 20;

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

#define DEBUG(s) 


int main()
{
	ios::sync_with_stdio(0);
	
	srand( (long long) new int);
	
	int n = rand()%5+5;
	
	cout<<n<<endl;
	
	FOR(i, 2, n)
	{
		int a = rand()%(i-1)+1;
		cout<<a<<" "<<i<<endl;;
	}

	return 0;
}

