#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int tab[26];

int main()
{
    int z;
    cin>>z;

    while(z--)
    {
        REP(i, 26) tab[i]=0;

        string s;
        cin>>s;

        long long int n = s.length();
        REP(i,n)
        tab[s[i]-'a']++;
        long long int wynik = n*(n-1)/2+1;
        long long int suma = 0;

        REP(i, 26)
        suma+=(long long)tab[i]*(long long)(tab[i]-1)/2;

        cout<<wynik-suma<<endl;
    }
}
