#include "tools.hh"
#include <iostream>

Coord::Coord()
  : x(0),y(0),z(0)
{
}


Coord::Coord(int x_, int y_, int z_)
  : x(x_), y(y_), z(z_)
{
}

void
Coord::dump()
{
  std::cout << x << ", " << y << ", " << z << std::endl;
}

int
Coord::mlen()
{
  return (abs(x) + abs(y) + abs(z));
}

int
Coord::clen()
{
  int temp = std::max(abs(x), abs(y));
  return std::max(abs(z), temp);
}

int
Coord::ld()
{
  int temp = mlen();
  if (temp == clen())
  {
    return temp;
  }
  return 0;
}

bool
Coord::sld()
{
  int temp = ld();
  if ((temp > 0) && (temp <= 5))
  {
    return true;
  }
  return false;
}

bool
Coord::lld()
{
  int temp = ld();
  if ((temp > 0) && (temp <= 15))
  {
    return true;
  }
  return false;
}

bool
Coord::nd()
{
  int temp = mlen();
  if ((temp > 0) && (temp <= 2))
  {
    return (clen() == 1) ;
  }
  return false;
}

bool adj(Coord const& from, Coord const& to)
{
  return (dist(from, to).mlen() == 1);
}

Coord dist(Coord const& from, Coord const& to)
{
  Coord ret(0,0,0);
  ret.x = to.x - from.x;
  ret.y = to.y - from.y;
  ret.z = to.z - from.z;

  return ret;
}


Region::Region() :
  c1(0,0,0),
  c2(0,0,0)
{
}

Region::Region(Coord a_, Coord b_) :
  c1(std::min(a_.x, b_.x), std::min(a_.y, b_.y), std::min(a_.z, b_.z)),
  c2(std::max(a_.x, b_.x), std::max(a_.y, b_.y), std::max(a_.z, b_.z))
{
}

void
Region::dump()
{
  std::cout << "Region coords:" << std::endl;
  c1.dump();
  c2.dump();
}
