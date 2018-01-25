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
#define INF 1000000001
#define MAXN 1000001
#define MAXQ 25

int n, k, q;

int td[MAXN], tk[MAXQ];
int DP[MAXN];

struct kmax
{
	deque<int> D;
	
	void push(int x)
	{
		while(!D.empty() && td[x] >= td[D.front()])
		{
			D.pop_front();
		}
		
		D.push_front(x);	
	}
	
	void pop(int kk)
	{
		if(!D.empty() && D.back() < kk)
			D.pop_back();
	}
	
	bool empty()
	{
		return D.empty();
	}
	
	int max()
	{
		if(D.empty())
			return INF;
		else
			return td[D.back()];
	}
	
	void clear()
	{
		D.clear();
	}
	
};

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;

    FOR(i, 1, n)
    cin>>td[i];

    cin>>q;
    REP(i, q)
    cin>>tk[i];
    
    kmax Q;
    int mn;

    //DP
    REP(x, q)
    {
		Q.clear();
        DP[1] = 0;
        mn = 0;
		Q.push(1);
		
        FOR(i, 2, n)
        {

            DP[i] = mn;
            //cout<<Q.max()<<endl;
            
            if(Q.max() <= td[i])
				DP[i]++;
			else
				Q.push(i);
			
            Q.pop(max(i - tk[x] + 1, 1));
            
            if(Q.empty())
            {
				mn++;
				FOR(j, max(i-tk[x], 1) + 1, i)
				if(DP[j] == mn)
				Q.push(j);
			}
		}
			
        //}

        //FOR(i, 1, n)
        //cout<<DP[i]<<" ";
        //cout<<endl;
		
        cout<<DP[n]<<endl;
        
        FOR(i, 1, n)
        DP[i] = 0;
    }

    return 0;
	}
