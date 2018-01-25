/*************************************************************************
 *                                                                       *
 *                    XXV Olimpiada Informatyczna          	             *
 *                                                                       *
 *   Zadanie:              Pionek										 *
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
const int MAXN = 500001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second

int n, x, y;

struct Vec
{
	LL x, y;
	Vec() {}
	Vec(LL _x, LL _y) : x(_x), y(_y) {}
	
	inline Vec operator+(const Vec &a) const
	{
		return Vec(x + a.x, y + a.y);
	}
	
	inline Vec operator-(const Vec &a) const
	{
		return Vec(x - a.x, y - a.y);
	}
};

inline LL Cross(Vec a, Vec b)
{
	return a.x * b.y - a.y * b.x;
}

inline LL Dot(Vec a, Vec b)
{
	return a.x * b.x + a.y * b.y;
}

inline LL lsq(Vec a)
{
	return a.x*a.x + a.y*a.y;
}

bool operator<(const Vec &a, const Vec &b)
{
	LL d = Cross(a, b);
	
	if(d == 0)
	{
		return lsq(a) < lsq(b);
	}
	else
	{
		return d > 0;
	}
}

bool operator==(const Vec &a, const Vec &b)
{
	LL d = Cross(a, b);
	LL s = Dot(a, b);
	
	return d == 0 && s > 0;
}

Vec tab[MAXN];
vector<Vec> h1, h2;
const Vec S(1, 0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	REP(i, n)
	{
		cin>>x>>y;
		tab[i] = Vec(x, y);
	}
	
	REP(i, n)
	{
		int d = Cross(S, tab[i]);
		if(d > 0 || (d == 0 && tab[i].x > 0))
			h1.PB(tab[i]);
		else
			h2.PB(tab[i]);
	}
	
	//sortowanie katowe
	sort(ALL(h1));
	sort(ALL(h2));
	
	FOREACH(it, h2)
	{
		h1.PB(*it);
	}
	
	//przepisywanie ze scaleniem takich samych
	int cnt = 0;
	REP(i, n)
	{
		if(i>0 && h1[cnt-1] == h1[i])
		{
			h1[cnt-1] = h1[cnt-1] + h1[i];
		}
		else
		{
			h1[cnt++] = h1[i];
		}
	}
	
	n = cnt;
	Vec ajkc(0,0);
	
	REP(i, n) 
	{
		tab[i] = h1[i];
		ajkc = ajkc + tab[i];
	}

	LL mx = 0;
	Vec res(0, 0);
	
	if(n <= 2000)
	{
		REP(i, n)
		{
			res = Vec(0,0);
			for(int j = i; j < i + n; j++)
			{
				res = res + tab[j%n];
				mx = max(mx, lsq(res));
			}
		}
	}
	else
	{
		int poc = 0;
		res = Vec(0,0);
		
		REP(kon, n)
		{
			while( ((poc < kon + n) && Cross(tab[kon], tab[poc%n]) > 0) || (poc == kon) )
			{
				res = res + tab[poc%n];
				mx = max(mx, lsq(res));
				mx = max(mx, lsq(ajkc - res));
				poc++;
			}
			res = res - tab[kon];
		}
		
		poc = n-1;
		res = Vec(0,0);
		
		REV(kon, n)
		{
			while( ((poc + n > kon) && Cross(tab[kon], tab[(poc+n)%n]) < 0) || (poc == kon) )
			{
				res = res + tab[(poc+n)%n];
				mx = max(mx, lsq(res));
				mx = max(mx, lsq(ajkc - res));
				poc--;
			}
			res = res - tab[kon];
		}
	}
	
	cout<<mx<<"\n";
	
	return 0;
}
