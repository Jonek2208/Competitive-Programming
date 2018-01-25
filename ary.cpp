#include <bits/stdc++.h>
using namespace std;
#define FOR(i, b, e) for (int i = b; i <= e; i++)
#define FORD(i, b, e) for (int i = b; i >= e; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define REV(i, n) FOR(i, n - 1, 0)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define RANGE 1000000000
#define MAXN 7000

long long n, k, tab[MAXN];
unordered_set<int> rmc;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    REP(i, n)
    {
        cin >> tab[i];
        rmc.insert(tab[i]);
    }

    int maks = ((n == 1) ? 1 : 2), poprz, dl;

    FOR(i, 0, n - 3)
    {
        FOR(j, i + 1, n - 2)
        {
            poprz = j;
            dl = 2;
            int k = tab[j];
            k += tab[j] - tab[i];

            if (rmc.find(2 * tab[i] - tab[j]) == rmc.end() && tab[j] > tab[i])
                while (rmc.find(k) != rmc.end())
                {
                    dl++;
                    k += tab[j] - tab[i];
                    //cout<<i<<" "<<j<<endl;
                }

            maks = max(maks, dl);
        }
    }

    int mb = 0, mp = 1;

    FOR(i, 1, n - 1)
    {
        if (tab[i] == tab[i - 1])
            mp++;
        else
            mp = 0;

        mb = max(mb, mp);
    }

    maks = max(maks, mb);

    cout << maks;

    return 0;
}
