#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef set<int> SI;

const int INF = 1000000007;
const LD eps = 0.00000001;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PP pop_back
#define MP make_pair
#define ST first
#define ND second


LD side(LD x1, LD y1, LD x2, LD y2){
    LD res;

    res = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

    return res;
}


LD ratio(LD x1, LD y1, LD x2, LD y2){
    LD res;

    res = (y1 - y2)/(x1 - x2);

    if(!(y1 == y2 || x1 == x2))
        return res;

    return 0;
}


int main(){

    //wspolrzedne
    LD x1,x2,x3,x4;
    LD y1,y2,y3,y4;

    //wczytanie
    cin>>x1>>y1
       >>x2>>y2
       >>x3>>y3
       >>x4>>y4;

    //pomocne
    LD a1,a2,a3,a4;
    LD d1,d2,d3,d4;

    //stosunki
    a1 = ratio(x1,y1,x2,y2);
    a2 = ratio(x2,y2,x3,y3);
    a3 = ratio(x3,y3,x4,y4);
    a4 = ratio(x4,y4,x1,y1);

    //boki
    d1 = side(x1,y1,x2,y2);
    d2 = side(x2,y2,x3,y3);
    d3 = side(x3,y3,x4,y4);
    d4 = side(x4,y4,x1,y1);

    //czesc wlasciwa
    if(a1 == a3 && a2 == a4){
        if((a1 == 0 && a2 == 0) || a1*a2 ==  - 1){
            if(d1 == d2)
                cout<<"SQUARE"<<"\n";
            else
                cout<<"RECTANGLE"<<"\n";
        }

        else if(d1 == d2)
            cout<<"RHOMBUS"<<"\n";

        else
            cout<<"PARALLELOGRAM"<<"\n";

    }
    else if(a1 == a3 || a2 == a4)
        cout<<"TRAPEZIUM"<<"\n";
    else if((d2 == d3 && d4 == d1) || (d1 == d2 && d3 == d4))
        cout<<"DELTOID"<<"\n";
    else
        cout<<"OTHER"<<"\n";

    return 0;
}
