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
#define MAXN 3000002

LL tab[MAXN], t;
int n, wyn;


int main()
{
    ios::sync_with_stdio(0);
    cin>>t>>n;
    FOR(i, 1, n)
    cin>>tab[i];
    
    LL mn, mx;
    
    FOR(i, 1, n)
    {
		mn = mx = tab[i];
		int k = 0;
		while(i + k <= n && mx - mn <= t)
		{
			k++;
			mn = min((LL)mn, tab[i + k]);
			mx = max((LL)mx, tab[i + k]);
		}
		
		wyn = max(wyn, k);
				
	}
	
	cout<<wyn;

    
    return 0;
}

