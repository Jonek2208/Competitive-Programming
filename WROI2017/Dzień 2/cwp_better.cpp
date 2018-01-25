#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 41;
const int MOD = 1000000007;

#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i--)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); i++)
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, m, a, b;
LL silnia[MAXN];
string s1, s2;
unordered_map<string, int> mapa;
vector<PII> deps;
VI order;
LL res;

//topo
VI g[MAXN];
int indeg[MAXN];
VI wor;
int pom[MAXN];
int zlicz[MAXN];


void Init()
{
	LL r = 1;
	
	FOR(i, 0, n)
	{
		silnia[i] = r;
		r*=i+1;
		r%=MOD;
	}
}

bool Toposort()
{
	
	int cnt = 0;
	
	FOR(i, 1, n)
	FOREACH(it, g[i])
		indeg[*it]++;
		
	//~ FOR(i, 1, n) cout<<indeg[i]<<" ";
	//~ cout<<endl;	
	
	FOR(i, 1, n)
	{
		if(indeg[i] == 0 && g[i].size() > 0)
		{
			wor.PB(i);
			pom[i] = 1;
		}
	}	
	
	while(cnt < SIZE(wor))
	{
		int v = wor[cnt];
		//~ cout<<v<<endl;
		FOREACH(it, g[v])
		{
			indeg[*it]--;
			if(indeg[*it] == 0)
			{
				wor.PB(*it);
			}
		}
		cnt++;
	}
	
	return (cnt==SIZE(wor));
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	FOR(i, 1, n)
	{
		cin>>s1;
		mapa[s1] = i;
		order.PB(i);
	}
	
	Init();
	
	//~ FOR(i, 0, n) cout<<silnia[i]<<endl;

	cin>>m;
	REP(i, m)
	{
		cin>>s1>>s2;
		a = mapa[s1];
		b = mapa[s2];
		g[a].PB(b);
		deps.PB(MP(mapa[s1], mapa[s2]));
	}
	
	if(Toposort())
	{
		int t = wor.size();
		res = 1;
		FOR(i, t+1, n)
		{
			res*=(LL)i;
			res%=MOD;
		}
		
		LL res1 = 0;
		do{
			bool flag = true;
			FOREACH(it, deps)
			{
				int it1 = 0, it2 = 0;
				
				while(wor[it1]!=it->ST) it1++;
				while(wor[it2]!=it->ND) it2++;
				
				if(it1<it2)
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				res1++;
				res1%=MOD;
			}

    } while(std::next_permutation(wor.begin(), wor.end()));
    //~ cout<<res<<" "<<res1<<endl;
		res*=res1;
		res%=MOD;
		cout<<res<<endl;
	}
	
	else cout<<0<<"\n";

	return 0;
}

/*
20
a b c d e f g h i j k l m n o p q r s t
10
a b
b c
a c
d c 
e c 
f c 
g c 
h c 
j c
i c


*/
