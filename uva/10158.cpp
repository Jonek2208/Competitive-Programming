#include<bits/stdc++.h>
using namespace std;

const int INF = -1000000001;
const int MAXN = 1000001;

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

int n, m, a, b, c;

int p[MAXN], r[MAXN], zlicz[MAXN], en[MAXN];

void Init()
{
	REP(i, n)
	{
		p[i] = i;
		en[i] = -1;
	}
}

int Find(int x)
{
	if(p[x] != x)
		p[x] = Find(p[x]);
	return p[x];
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x == y) return;
	if(r[x] > r[y]) p[y] = x;
	else p[x] = y;
	if(r[x] == r[y]) r[y]++;
}

void Print()
{
	REP(i, n)
	cout<<Find(i)<<" ";
	cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);

	cin>>n;
	Init();
	
	while(true)
	{
		cin>>c>>a>>b;
		if(a==0 && b==0 && c==0) break;
		
		switch(c)
		{
			case 1:
				a = Find(a);
				b = Find(b);
				if(en[Find(en[a])] == a || en[Find(en[b])] == b) cout<<-1<<endl;
				else
				{
					Union(a, b);
				}
			break;
			case 2:
				a = Find(a);
				b = Find(b);
				if(a == b) cout<<-1<<endl;
				else
				{
					if(en[a] == -1)
					{
						if(en[b] == -1)
						{
							en[a] = b;
							en[b] = a;		
						}
						else
						{
							en[a] = b;
							Union(a, en[b]);
						}
					}
					else if(en[b] == -1)
					{
						en[b] = a;
						Union(b, en[a]);
					}
					else
					{
						Union(en[a], b);
						Union(en[b], a);
					}
				}
			break;
			case 3:
				a = Find(a);
				b = Find(b);
				cout<<(a == b ? 1 : 0)<<endl;
			break;
			case 4:
				a = Find(a);
				b = Find(b);
				cout<<(a!=b && en[a] != -1 && en[b] != -1 && (en[Find(en[a])] == a || en[Find(en[b])] == b) ? 1 : 0)<<endl;
			break;
		}
		//Print();
	} 
	
	return 0;
}

