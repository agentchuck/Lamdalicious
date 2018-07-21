#ifndef TOOLS_HH
#define TOOLS_HH


class coord {
 public:
  int x;
  int y;
  int z;

  coord();
  coord(int x_, int y_, int z_); 
  void dump();

  // Chessboard length
  int clen();

  // Manhattan length
  int mlen();
};


bool adj(coord const& from, coord const& to);
coord dist(coord const& from, coord const& to);

#endif

