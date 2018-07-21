#include <iostream>

#include "tools.hh"

using namespace std;

int main(int argc, char **argv)
{
  coord a (1,2,3);
  coord b (4,5,6);

  a.dump();
  b.dump();

  dist(a,b).dump();
  dist(b,a).dump();
  coord distab = dist(a,b);
  coord distba = dist(b,a);

  cout << endl << "Manhattan length" << endl;
  cout << "a: " << a.mlen() << endl;
  cout << "b-a: " << distab.mlen() << endl;
  cout << "a-b: " << distba.mlen() << endl;

  cout << endl << "Adjacent check" << endl;
  coord adja(1,2,3);

  for (int idx = 0; idx < 5; idx++)
  {
    coord ca(idx,2,3);
    adja.dump();
    ca.dump();
    if (adj(adja, ca))
    {
      cout << " - adjacent" << endl;
    }
    cout << endl;

    coord cb(1, idx, 3);
    adja.dump();
    cb.dump();
    if (adj(adja, cb))
    {
      cout << " - adjacent" << endl;
    }
    cout << endl;

    coord cc(1,2,idx);
    adja.dump();
    cc.dump();
    if (adj(adja, cc))
    {
      cout << " - adjacent" << endl;
    }
    cout << endl;
  }


  cout << "a: " << a.mlen() << endl;
  cout << "b-a: " << distab.mlen() << endl;
  cout << "a-b: " << distba.mlen() << endl;


  cout << endl << "Chessboard length" << endl;
  coord cha(10,20,30);
  coord chb(19,-32,22);
  coord chc(-19,18,-17);
  cha.dump();
  cout << cha.clen() << endl;
  chb.dump();
  cout << chb.clen() << endl;
  chc.dump();
  cout << chc.clen() << endl;

  return 0;
}
