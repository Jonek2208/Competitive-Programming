/*Oceny XXIV OI*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1e9+7;
const int MAXN = 1e6+1;
const int SQ = 5000;

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
#define SIZE(c) (int)(c).size()

#define DEBUG(s) 

int n, z, a, b;
int sq;

int pref[MAXN];
int val[MAXN];
int res;
int sum[210];
unordered_map<int, int> nums[210];

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>z;
	sq = sqrt(n);
	sq = SQ;
	DEBUG(cout<<sq<<endl;)
	FOR(i, 1, n) cin>>val[i];
	
	FOR(i, 1, n) val[i] -= i;
	FOR(i, 1, n) pref[i] = pref[i-1] + val[i];
	FOR(i, 1, n) nums[i/sq][pref[i]]++;
	
	DEBUG(
	FOR(i, 0, n/sq)
	{
		for(auto j: nums[i]) cout<<"("<<j.ST<<" "<<j.ND<<") ";
		cout<<endl;	
	}
	)
	
	FOR(i, 0, n/sq) res+=nums[i][0];
	
	REP(i, z)
	{
		if(i > 0)
		{
			cin>>a>>b;
			int ka = a/sq, kb = (b-1)/sq;
			int d = -val[a];
			int a1 = val[a] + a, b1 = val[b] + b;
			val[b] = a1 - b;
			val[a] = b1 - a;
			d += val[a]; 
			DEBUG(cout<<d<<endl;)
			
			FOR(i, ka+1, kb-1) 
			{
				res -= nums[i][-sum[i]];
				sum[i] += d;
				res += nums[i][-sum[i]];
			}
			
			FOR(i, a, min((ka+1)*sq-1, b-1))
			{
				if(pref[i] + sum[ka] == 0) res--;
				nums[ka][pref[i]]--;
				pref[i] += d;
				nums[ka][pref[i]]++;
				if(pref[i] + sum[ka] == 0) res++;
			}
			if(ka != kb)
			{
				FOR(i, kb*sq, b-1)
				{
					if(pref[i] + sum[kb] == 0) res--;
					nums[kb][pref[i]]--; 
					pref[i] += d;
					nums[kb][pref[i]]++; 
					if(pref[i] + sum[kb] == 0) res++;
				}
			}
				DEBUG(
				FOR(i, 0, n/sq)
				{
					cout<<sum[i]<<" ";
					for(auto j: nums[i]) cout<<"("<<j.ST<<" "<<j.ND<<") ";
					cout<<endl;	
				}
				)
		}
		
		DEBUG(
		FOR(i, 1, n) cout<<tab[i]<<" "; cout<<endl;
		)
		
		cout<<res<<"\n";
	}	
	return 0;
}

/*
12 5
1 2 4 3 6 5 8 7 12 10 11 9

12 5
1 2 4 3 6 5 8 7 10 11 12 9

12 5
9 2 4 3 6 5 8 7 12 10 11 1

3 4
1 2 3
1 3
1 2
2 3

*/
