/*Swiadek nieokresowosci*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1000000007;
const int MAXN = 100001;
const int LOG = 18;

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

int n;
string s;

int logs[MAXN];
int dict[LOG][MAXN];

void makekmr(string &s)
{
	pair<PII, int> pairs[MAXN];
	
	REP(i, n) dict[0][i] = s[i];
	
	int dl;
	
	for(int lg = 1; (dl = (1 << lg) ) <= n; ++lg)
	{
		
		REP(i, n-dl+1) pairs[i] = MP(MP(dict[lg-1][i], dict[lg-1][i+dl/2]), i);
		
		sort(pairs, pairs + n-dl+1);
		
		int cnt = 1;
		
		REP(i, n-dl+1)
		{
			if(i > 0 && pairs[i-1].ST != pairs[i].ST) cnt++;
			dict[lg][pairs[i].ND] = cnt;
		}
	}
}

void logscalc()
{
	int lg = 0;
	FOR(i, 2, n-1)
	{
		logs[i] = lg;
		if(i == 1<<(lg+1)) ++lg;
	}
}

bool equal(int a, int b, int l)
{
	int lg = logs[l], dl = 1<<lg;
	return (dict[lg][a] == dict[lg][b]) && (dict[lg][a+l-dl] == dict[lg][b+l-dl]);
}


int main()
{
	ios::sync_with_stdio(0);
	cin>>s;
	n = SIZE(s);
	makekmr(s);
	logscalc();
	
	DEBUG(
	REP(k, LOG)
	{
		REP(i, n) cout<<dict[k][i]<<" ";
		cout<<endl;
	}
	cout<<endl;
	REP(i, n) cout<<logs[i]<<" ";
	cout<<endl;
	)
	
	
	FOR(k, 1, n)
	{
		int poc = 0, kon = n-k, sr, wyn = 0;
		
		while(poc <= kon)
		{
			
			sr = (poc+kon+1)/2;
			//~ cout<<k<<" "<<sr<<endl;
			if(equal(0, k, sr))
			{
				//~ cout<<"rowne: "<<k<<" "<<sr<<"\n";
				poc = sr+1;
				wyn = sr;
			}
			else
			{
				kon = sr-1;
			}
		}
		
		if(wyn+k == n) wyn = -1;
		//~ cout<<wyn<<" ";
			
		cout<<wyn+1<<" ";
	}
	
	
	return 0;
}
/*

abcbacabdcabdcabca

*/

