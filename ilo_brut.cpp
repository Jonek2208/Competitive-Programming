#include<bits/stdc++.h>
using namespace std;
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORD(i, b, e) for(int i = b; i >= e; i++)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FOR(i, n-1, 0)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define RANGE 1000001
#define MAXN 1000000

long long n, k, tab[MAXN], licznik;

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    REP(i, n)
    cin>>tab[i];

       cout<<"n:"<<n<<"|";
    REP(i, n)
    cout<<tab[i]<<"_";
    return 0;
}
