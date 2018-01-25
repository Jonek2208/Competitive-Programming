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
#define RANGE 1000001
#define MAXN 1000000

LL n, k, tab[MAXN], licznik, kubelki[MAXN], konce[MAXN], pref[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>k;
    REP(i, n)
    cin>>tab[i];

    //ujemne
	
	int licznik = 0;
	
    REV(i, n)
    if(tab[i] < 0)
        ujemne.PB(i);
    else if(!tab[i])
        zera.PB(i);

    REV(i, n)
    {
		if(tab[i] < 0) 
		{
			licznik++;
		}
		
		konce[licznik] = i-1;
		
        kubelki[i] = licznik;
    }
    
    int dl = 0;
    
    REV(i, n)
    {
		if(tab[i] < 0)
		dl = 1;
		dl++;
	}


    REP(i, n)
    cout<<kubelki[i]<<" ";
    cout<<endl;



//
//    long long iloczyn;
//
//    int poc = 0, kon, dl = 0;
//    iloczyn = 1;
//
//
//    for(kon = 0; kon < n; kon++)
//    {
//        while(poc < n && tab[poc] <= k/iloczyn)
//        {
//            dl++;
//            iloczyn *= tab[poc];
//            poc++;
//            licznik+=dl;
//        }
//        iloczyn /= tab[kon];
//        dl--;
//
//    }
//
//    cout << licznik;
    return 0;
}

/*
10 40
1 3 5 8 7 8 9 6 4 2

*/


