#ifndef TOOLS_HH
#define TOOLS_HH


class Coord {
  public:
    int x;
    int y;
    int z;

    Coord();
    Coord(Coord const &rhs);
    Coord(int x_, int y_, int z_); 

    // Chessboard length
    int clen();

    // Manhattan length
    int mlen();

    // Linear distance
    // - Note 0 if it is not a linear distance
    int ld();

    // Short linear distance if ld in [1,5]
    bool sld();
    // Short linear distance if ld in [1,15]
    bool lld();

    // Near Coordinate distance
    // A Coordinate difference d is a near Coordinate difference (notated nd)
    // if 0 < mlen(d) ? 2 and clen(d) = 1. That is, a Coordinate difference is
    // a near Coordinate difference if at least one and at most two components
    // have the value -1 or 1 and the other components have the value 0. There
    // are exactly 18 near Coordinate differences.
    bool nd();

    // For encoding, get the axis and integer (distance)
    int a();
    int i();
    int nd_enc();

    bool operator==(Coord const &rhs);

    void dump();
};

bool adj(Coord const& from, Coord const& to);
Coord dist(Coord const& from, Coord const& to);

class Region {
  public:
    Coord c1;
    Coord c2;

    Region();
    Region(Coord const& a_, Coord const& b_);

    int dimension();

    bool contains(Coord const &coord);
    bool operator==(Region const &rhs);

    void dump();
};

#endif

