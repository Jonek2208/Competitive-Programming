#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
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
#define INF 1000000000
#define MAXN 1000000
#define A 26

int n, zlicz[MAXN+1];
bool znaki[A];
string s;

inline int wartosc(char c1, char a1, char a2)
{
	if(c1 == a1) return 1;
	if(c1 == a2) return -1;
	return 0;	
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
	cin>>s;
	int res = 0;
	
	REP(i, n)
	znaki[s[i]-'a'] = true;
	
	
	REP(i, A)
	REP(j, A)
	{
		char x = i+'a', y = j+'a';
		int v;
		int wynik = 0, suma = 0, suma_pop = 0, mini = INF;
		
		REV(k, n)
		{
			v = wartosc(s[k], x, y);
			suma += v;
			if(v == -1)
			{
				mini = min(mini, suma_pop);
				suma_pop = suma;
			}
			
			wynik = max(wynik, suma - mini);
			res = max(res, wynik);
		}
	}
	cout<<res;

    return 0;
}
