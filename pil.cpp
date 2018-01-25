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
int n, wyn = 1;

struct kmax
{
	deque<pair<LL, LL> > D;
	
	void push(LL x)
	{
		LL ile = 0;
		while(!D.empty() && D.front().ST <= x)
		{
			ile += 1 + D.front().ND;
			D.pop_front();
		}
		D.push_front(MP(x, ile));
		
	}
	
	void pop()
	{
		if(!D.empty())
		{
			if(D.back().ND > 0)
				D.back().ND--;
			else
			D.pop_back();
			//cout<<"popped\n";
		}
	}
	
	LL max()
	{
		if(D.empty())
			return 1;
		else
			return D.back().ST;
	}
};

struct kmin
{
	deque<pair<LL, LL> > D;
	
	void push(LL x)
	{
		int ile = 0;
		while(!D.empty() && D.front().ST >= x)
		{
			ile += 1 + D.front().ND;
			D.pop_front();
		}
		D.push_front(MP(x, ile));
	}
	
	void pop()
	{
		if(!D.empty())
		{
			if(D.back().ND > 0)
				D.back().ND--;
			else
			D.pop_back();
			//cout<<"popped\n";
		}
	}
	
	LL min()
	{
		if(D.empty())
			return 1;
		else
			return D.back().ST;
	}
};


int main()
{
    ios::sync_with_stdio(0);
    cin>>t>>n;
    FOR(i, 1, n)
    cin>>tab[i];
    
    kmax MX;
    kmin MN;
    
    
    
    int poc = 1, kon = 1;
    
    MX.push(tab[1]);
	MN.push(tab[1]);
	
    for(kon = 1; kon <= n; kon++)
    {	
		poc = max(poc, kon);
		cout<<"yyy "<<MN.min()<<" "<<MX.max()<<endl;
		while(poc < n && (max(MX.max(), tab[poc+1]) - min(MN.min(), tab[poc+1]) <= t))
		{
			poc++;
			MX.push(tab[poc]);
			MN.push(tab[poc]);
		}

		cout<<kon<<" "<<poc<<endl;
		
		wyn = max(wyn, poc-kon+1);
		
		MN.pop();
		MX.pop();	
	}
	
	cout<<wyn;

    
    return 0;
}


