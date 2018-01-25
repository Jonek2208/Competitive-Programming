#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAXN = 100001;
const int MX = 1000001;
const int SQ = 320;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c.size())
#define DEBUG(s) 

int ajkc[MAXN];
int zlicz[MX], pi[MX];
pair<PII, int> zap[MAXN];
LL res[MAXN];
vector< pair<PII, int> > kub[SQ+2];
int n, q, sq;

inline LL pot(int s)
{
	return (LL)zlicz[s]*(LL)zlicz[s]*(LL)s;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	
	sq = ceil(sqrt(n));
	
	FOR(i, 1, n) cin>>ajkc[i];
	FOR(i, 1, q)
	{
		cin>>zap[i].ST.ST>>zap[i].ST.ND;
		zap[i].ND = i;
	}
	
	FOR(i, 1, q) kub[(zap[i].ST.ND-1)/sq+1].PB(zap[i]);
	
	FOR(i, 1, sq)
	{
		sort(ALL(kub[i]));
		DEBUG(for(auto it: kub[i]) cout<<"("<<it.ST.ST<<", "<<it.ST.ND<<") "; cout<<"\n";)
	}
		
	LL tmp = 0;
	int l = 1, r = 0;
	FOR(i, 1, sq)
	{
		for(auto it: kub[i])
		{
			int a = it.ST.ST;
			int b = it.ST.ND;			
			
			while(r > b)
			{
				
				tmp -= pot(ajkc[r]);
				zlicz[ajkc[r]]--;
				tmp += pot(ajkc[r]);
				r--;
				DEBUG(cout<<r<<" r-- "<<tmp<<"\n";)
			}

			while(l < a)
			{
				
				tmp -= pot(ajkc[l]);
				zlicz[ajkc[l]]--;
				tmp += pot(ajkc[l]);
				l++;
				DEBUG(cout<<l<<" l++ "<<tmp<<"\n";)
			}
			while(l > a)
			{
				l--;
				tmp -= pot(ajkc[l]);
				zlicz[ajkc[l]]++;
				tmp += pot(ajkc[l]);
				
				DEBUG(cout<<l<<" l-- "<<tmp<<"\n";)
			}
			
			while(r < b)
			{
				r++;
				tmp -= pot(ajkc[r]);
				zlicz[ajkc[r]]++;
				tmp += pot(ajkc[r]);
				DEBUG(cout<<r<<" r++ "<<tmp<<"\n";)
			}
			
			res[it.ND] = tmp;
		}
	}
	
	FOR(i, 1, q) cout<<res[i]<<"\n";
	
	return 0;
}
