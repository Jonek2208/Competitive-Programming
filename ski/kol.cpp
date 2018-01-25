#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000007;
const int MAXN = 100001;
const int A = 26;

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

int pref[A][MAXN];
int n, m, a, b;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	
	REP(i, n)
	{
		REP(j, A) pref[j][i+1] = pref[j][i];
		pref[s[i]-'a'][i+1]++;
	}
	
	//~ REP(j, A)
	//~ {
		//~ REP(i, n+1) cout<<pref[j][i]<<" ";
		//~ cout<<"\n";
	//~ }
	
	REP(i, m)
	{
		cin>>a>>b;
		char c;
		int mx = 0, wmx = 0, kmx = 0;
		
		REP(j, A)
		{
			kmx = pref[j][b] - pref[j][a-1];
			
			if(kmx > mx)
			{
				c = j + 'a';
				wmx = mx;
				mx = kmx;
			}
			else if(kmx > wmx)
			{
				wmx = kmx;
			}
		}
		if(mx > wmx)
		cout<<c<<"\n";
		else cout<<"NIE MA\n";
	}
	
	return 0;
}

/*
6 4
ababba
1 3
2 5
1 5
1 6
*/
