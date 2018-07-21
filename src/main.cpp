#include <iostream>

#include "tools.hh"

using namespace std;

int main(int argc, char **argv)
{
  Coord a (1,2,3);
  Coord b (4,5,6);

  a.dump();
  b.dump();

  dist(a,b).dump();
  dist(b,a).dump();
  Coord distab = dist(a,b);
  Coord distba = dist(b,a);

  cout << endl << "Manhattan length" << endl;
  cout << "a: " << a.mlen() << endl;
  cout << "b-a: " << distab.mlen() << endl;
  cout << "a-b: " << distba.mlen() << endl;

  cout << endl << "Adjacent check" << endl;
  Coord adja(1,2,3);

  for (int idx = 0; idx < 5; idx++)
  {
    Coord ca(idx,2,3);
    adja.dump();
    ca.dump();
    if (adj(adja, ca))
    {
      cout << " - adjacent" << endl;
    }
    cout << endl;

    Coord cb(1, idx, 3);
    adja.dump();
    cb.dump();
    if (adj(adja, cb))
    {
      cout << " - adjacent" << endl;
    }
    cout << endl;

    Coord cc(1,2,idx);
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
  Coord cha(10,20,30);
  Coord chb(19,-32,22);
  Coord chc(-19,18,-17);
  cha.dump();
  cout << cha.clen() << endl;
  chb.dump();
  cout << chb.clen() << endl;
  chc.dump();
  cout << chc.clen() << endl;


  cout << endl << "Regions" << endl;
  Region r1;
  r1.dump();

  Region r2(Coord(4,2,6), Coord(1,5,3));
  r2.dump();

  Region r3(Coord(1,5,3), Coord(4,2,6));
  r3.dump();

  return 0;
}
