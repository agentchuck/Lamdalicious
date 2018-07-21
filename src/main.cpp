#include <iostream>

#include "commands.hh"
#include "tools.hh"

using namespace std;

int main()
{
#if 0
  Coord a (1,2,3);
  Coord b (4,5,6);

  a.dump();
  b.dump();

  Coord c(a+b);
  c.dump();
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

  if (r1 == r2) 
  {
    cout << "r1 and r2 are equal" << endl;
  }

  if (r2 == r3) 
  {
    cout << "r2 and r3 are equal" << endl;
  }
  Coord my(0,1,0);
  my.dump();
#endif

  cout << endl << " Generate test file " << endl;
  CommandList myCommands;

  std::shared_ptr<Command> flip(new Flip);
  std::shared_ptr<Command> wait(new Wait);
  std::shared_ptr<Command> smove(new SMove(Coord(-15,0,0)));
  std::shared_ptr<Command> fill(new Fill(Coord(0,-1,0)));
  std::shared_ptr<Command> fill2(new Fill(Coord(1,0,0)));
  std::shared_ptr<Command> halt(new Halt);
  std::shared_ptr<Command> lmove(new LMove(Coord(0,0,-1),Coord(0,2,0)));

  myCommands.addCommand(flip);
  myCommands.addCommand(wait);
  for (int cnt = 0; cnt < 10; cnt++)
  {
    myCommands.addCommand(smove);
    myCommands.addCommand(lmove);
    myCommands.addCommand(fill);
    myCommands.addCommand(fill2);
  }
  myCommands.addCommand(flip);
  //myCommands.addCommand(halt);
  myCommands.dumpToFile("test.nbt");

  return 0;
}
