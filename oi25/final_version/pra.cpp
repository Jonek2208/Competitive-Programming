/*************************************************************************
 *                                                                       *
 *                    XXV Olimpiada Informatyczna                        *
 *                                                                       *
 *   Zadanie:              Prawnicy                                      *
 *   Autor:                Jonatan Hrynko                                *
 *                                                                       *
 *************************************************************************/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const int MAXN = 1000001;
const LL MOD = 1000000007;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define SIZE(c) (int)(c).size()
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, k, a, b;

struct Worker
{
	int nr;
	int a, b;
	bool operator<(const Worker &w) const
	{
		return (b == w.b ? (a == w.a ? nr < w.nr : a < w.a) : b < w.b);
	}
};

Worker tab[MAXN];
int state[MAXN];
PII mx;

struct Event
{
	int nr, x, type;
	Event(){}
	Event(int _nr, int _x, int _type): nr(_nr), x(_x), type(_type) {}

	bool operator<(const Event &e) const
	{
		return (x == e.x ? type < e.type : x < e.x);
	}
};

vector<Event> events;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i, 1, n)
	{
		cin>>a>>b;
		tab[i].a = a;
		tab[i].b = b;
		tab[i].nr = i;
		events.PB(Event(i, a, -1));
		events.PB(Event(i, b, 1));
	}
	
	sort(ALL(events));
	int S = 0;
	queue<Worker> Q;
	
	int poc = 0;
	
	FOREACH(it, events)
	{
		// state: 0 - nic, 1 - na kolejce, 2 - w zbiorze, 
		// 3 - wywalony z kolejki (nie byl w zbiorze), 4 - wywalony ze zbioru
		if(it->type == -1)
		{
			Q.push(tab[it->nr]);
			state[it->nr] = 1;
		}
		else
		{
			state[it->nr]+=2;
		}
		
		//wywalanie ze zbioru
		if(state[it->nr] == 4)
		{
			if(S == k && (tab[it->nr].b - poc) > (mx.ND - mx.ST))
			{
				mx.ST = poc;
				mx.ND = tab[it->nr].b;
			}
			S--;
		}
		
		//wrzucam z kolejki
		while(S < k && !Q.empty())
		{
			if(state[Q.front().nr] == 1)
			{
				S++;
				poc = Q.front().a;
				state[Q.front().nr] = 2;
			}
			Q.pop();
		}
	}
	
	//wypisywanie
	cout<<(mx.ND-mx.ST)<<"\n";
	int cnt = 0;
	FOR(i, 1, n)
	{
		if(tab[i].a <= mx.ST && mx.ND <= tab[i].b)
		{
			cnt++;
			cout<<tab[i].nr<<" ";
		}
		if(cnt == k) break;
	}
	
	return 0;
}
