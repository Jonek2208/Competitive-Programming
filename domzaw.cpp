#include <cstdio>
#include "dom.h"

namespace domns {
	const int N = 1001;
	int n, op;
	int tab[N];
	int occ[N];
	int dom;
}

int init()
{
	using namespace domns;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", tab + i);
        if(++occ[tab[i]] * 2 > n)
            dom = tab[i];
    }
    return n;
}

bool equal(int a, int b)
{
	using namespace domns;
    op++;
    return tab[a] == tab[b];
}

void answer(int k)
{
	using namespace domns;
    printf("odpowiedź: %d, wykonano %d zapytań\n", k, op);
    puts(dom == tab[k] ? "dobra odpowiedź" : "zła odpowiedź");
}
