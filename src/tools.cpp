#include "tools.hh"
#include <iostream>

coord::coord()
  : x(0),y(0),z(0)
{
}


coord::coord(int x_, int y_, int z_)
  : x(x_), y(y_), z(z_)
{
}

void
coord::dump()
{
  std::cout << x << ", " << y << ", " << z << std::endl;
}

int
coord::mlen()
{
  return (abs(x) + abs(y) + abs(z));
}

int
coord::clen()
{
  int temp = std::max(abs(x), abs(y));
  return std::max(abs(z), temp);
}

bool adj(coord const& from, coord const& to)
{
  return (dist(from, to).mlen() == 1);
}

coord dist(coord const& from, coord const& to)
{
  coord ret(0,0,0);
  ret.x = to.x - from.x;
  ret.y = to.y - from.y;
  ret.z = to.z - from.z;

  return ret;
}

