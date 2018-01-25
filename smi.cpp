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
#define MAXN 500000

char stos[MAXN];
int it = 0;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin>>s;
	
	REP(i, s.length())
	if(stos[it] == '(' && s[i] == ')' && it > 0)
	it--;
	else
	{
		stos[++it] = s[i];
	}
	
	cout<<it<<endl;
	
	return 0;
}
