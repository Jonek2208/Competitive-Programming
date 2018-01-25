#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

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
#define MAXN 1000

int n, q, x, y, zz;
char z;

int main()
{
	srand(time(NULL));
	n = rand()%1000000000+1;
	q = rand()%1000+1;
	cout<<n<<" "<<q<<endl;
	
	REP(i, q)
	{
		x = rand()%(n-1)+1;
		y = n - x + 1;
		zz = rand()%2;
		
		z = zz ? 'U' : 'L';
		cout<<x<<" "<<y<<" "<<z<<endl;	
	}
	
	
	return 0;
}
