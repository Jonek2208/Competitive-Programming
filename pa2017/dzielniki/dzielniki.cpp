#include "dzielniki.h"
#include <iostream>

using namespace std;

int main() {
  long long N, ile_dzielnikow = 0;
  N = DajN();
  for (long long d = 1; d * d <= N; ++d) {
    if (N % d == 0) {
      ++ile_dzielnikow;
      if (N / d != d)
        ++ile_dzielnikow;
    }
  }
  cout << ile_dzielnikow << endl;
}
