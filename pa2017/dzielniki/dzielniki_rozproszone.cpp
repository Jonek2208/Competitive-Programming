#include "dzielniki.h"
#include "message.h"
#include <iostream>

using namespace std;

int main() {
  long long N, ile_dzielnikow = 0;
  N = DajN();
  for (long long d = 1 + MyNodeId(); d * d <= N; d += NumberOfNodes()) {
    if (N % d == 0) {
      ++ile_dzielnikow;
      if (N / d != d)
        ++ile_dzielnikow;
    }
  }
  if (MyNodeId() > 0) {
    PutInt(0, ile_dzielnikow);
    Send(0);
  } else {
    for (int instancja = 1; instancja < NumberOfNodes(); ++instancja) {
      Receive(instancja);
      ile_dzielnikow += GetInt(instancja);
    }
    cout << ile_dzielnikow << endl;
  }
}
