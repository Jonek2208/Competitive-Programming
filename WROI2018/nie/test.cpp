#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int MAXN = 200001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c.size())

int tab[MAXN];
int n;

//~ int main()
//~ {
	//~ ios::sync_with_stdio(0);
	//~ cin>>n;
	//~ cout<<n<<"\n";
	//~ FOR(i, 1, n) cin>>tab[i];
	
	
	
	//~ return 0;
//~ }

set< pair<int, int> > pary;

int rnd(int a, int b)
{
	return rand()%(b-a+1)+a;
}
int a, b;
int main()
{
    vector<int> v;
    cin>>n;
    srand(time(0));
    FOR(i, 1, n) 
    {
		do{
			a = rnd(1, 16);
			b = rnd(a, 16);
		} while(pary.find(make_pair(a,b)) != pary.end());
		pary.insert(make_pair(a, b));	
		cout<<a<<" "<<b<<"\n";
	}
 
    cout << "\n";
}
