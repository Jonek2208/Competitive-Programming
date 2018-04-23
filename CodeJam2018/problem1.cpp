#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

#define DEBUG(s) 

int d, z, res, n;
string p;


int main()
{
	ios::sync_with_stdio(0);
	cin>>z;
	
	FOR(test, 1, z)
	{
		int cost = 0, curr = 1, num = 0;
		cin>>d>>p;
		n = SIZE(p);
		REP(i, n)
		{
			switch(p[i])
			{
				case 'C':
					curr<<=1;
				break;
				case 'S':
					cost+=curr;
					num++;
				break;
			}
		}
		DEBUG(cout<<num<<" "<<cost<<"\n";)
		
		if(cost > d)
		{
			res = 0;
			if(num <= d)
			{
				int lasts = -1;
				
				REP(i, n) if(p[i] == 'S') lasts = i;
				
				REV(i, n)
				{
					if(p[i] == 'C')
					{
						int j = i;
						while(cost > d && j < lasts)
						{
							cost -= curr/2;
							res++;
							swap(p[lasts], p[j]);
							
							if(j+1 == lasts) lasts--;
							j++;
						}
						curr>>=1;
					}
					
					
				}
			}
			else 
			{
				res = -1;
			}
		}
		else 
		{
			res = 0;
		}

		cout<<"Case #"<<test<<": ";
		if(res < 0) cout<<"IMPOSSIBLE\n";
		else cout<<res<<"\n";
	}

	
	return 0;
}

/*
6
1 CS
2 CS
1 SS
6 SCCSSC
2 CC
3 CSCSS

*/
