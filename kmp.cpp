#include<bits/stdc++.h>

using namespace std;

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
#define MAXN 1001

int pi[MAXN];

int main()
{
	string s;
	
	cin>>s;
	int n = s.length();
	s = " " + s;
	
	int c = pi[1] = 0;
	
	FOR(i, 2, n)
	{
		while(c>0 && s[i] != s[c+1])
		c = pi[c];
		if(s[i] == s[c+1])
		c++;
		pi[i] = c;		
	}
	
	
	FOR(i, 1, n)
	cout<<pi[i]<<" ";

	
	
	return 0;
}
