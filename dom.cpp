#include "dom.h"
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
#define MAXN 1002

int kasta[MAXN], zlicz[MAXN];
bool zepsuty[MAXN];

SI odw;
bool wynik = false;

int main()
{
	int n = init();
	
	int curr = 1, cnt = 1;
	kasta[1] = true;
	
	FOR(i, 2, n)
	{
		if(equal(curr, i)) cnt++;
		else 
		{
			cnt--;
			zepsuty[i] = true;
		}
		
		if(!cnt)
		{
			curr = ++i;
			kasta[curr] = true;
			cnt = 1;
		}
	}
	
	//cout<<cnt<<" "<<curr<<endl;
	
	int w = 1;
	bool res = false;
	
	//cout<<n+1<<endl;
	
	//FOR(i, 1, n)
	//cout<<zepsuty[i]<<" ";
	//cout<<endl;
	
	int kk = 1;
	
	if(cnt > 0 && curr != n+1)
	{
		FOR(i, 1, n)
		{
			if(i != curr)
			{
				
				if(zepsuty[i] == true || kasta[i] == true)
				{
					kk++;
					if(equal(i, curr))
					{
						w++;
						//cout<<w<<" "<<i<<endl;
					}
				}
			}
		}
		
		//cout<<w<<endl;
		
		if(w+n-kk>n/2)
		res = true;		
	}
	
	if(res) answer(curr);
	else answer(0);
		
	return 0;
}
