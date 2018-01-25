#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, b, e) for(int i = b; i <= e; i++)

using namespace std;

int tab[10] = {5,6,4,1,3,7,8,9,2,10};

void quicksort(int *b, int *e)
{
        int roz = e-b;

        int pivot = *(b+roz/2);
        int *lewy = b;
        int *prawy = e;


        do
        {
            while(*lewy<pivot) lewy++;
            while(*prawy>pivot) prawy--;


            if(lewy<=prawy)
            {
                swap(*lewy, *prawy);
                lewy++;
                prawy--;
            }


        }while(lewy<=prawy);

        if(prawy>b)quicksort(b, prawy);
        if(lewy<e)quicksort(lewy, e);
}

int main()
{
    quicksort(tab, tab+9);
    REP(i, 10) cout<<tab[i]<<" ";


}
