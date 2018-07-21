#include "tools.hh"
#include <algorithm>
#include <iostream>

Coord::Coord()
  : x(0),y(0),z(0)
{
}


Coord::Coord(int x_, int y_, int z_)
  : x(x_), y(y_), z(z_)
{
}

Coord::Coord(Coord const &rhs)
  : x(rhs.x), y(rhs.y), z(rhs.z)
{
}

void
Coord::dump()
{
  std::cout << x << ", " << y << ", " << z << " a:" << a() << " i:" << i() << std::endl;
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

int
Coord::a()
{
  if (0 != x) {
    return 1;
  }
  if (0 != y) {
    return 2;
  }
  return 3;
}

int
Coord::i()
{
  if (0 != x) {
    return x;
  }
  if (0 != y) {
    return y;
  }
  return z;
}

int
Coord::nd_enc()
{
  //  (dx + 1) * 9 + (dy + 1) * 3 + (dz + 1).
  return ((x+1)*9) + ((y+1)*3) + (z+1);
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

bool 
Coord::operator==(Coord const &rhs)
{
  return ((x == rhs.x) &&
          (y == rhs.y) &&
          (z == rhs.z));
}

Coord 
Coord::operator+(Coord const &rhs)
{
  Coord retCoord(rhs);

  retCoord.x += x;
  retCoord.y += y;
  retCoord.z += z;

  return retCoord;
}


Region::Region() :
  c1(0,0,0),
  c2(0,0,0)
{
}

Region::Region(Coord const& a_, Coord const& b_) :
  c1(std::min(a_.x, b_.x), std::min(a_.y, b_.y), std::min(a_.z, b_.z)),
  c2(std::max(a_.x, b_.x), std::max(a_.y, b_.y), std::max(a_.z, b_.z))
{
}

int
Region::dimension()
{
  int ret = 0;
  if (c1.x != c2.x) ret++;
  if (c1.y != c2.y) ret++;
  if (c1.z != c2.z) ret++;

  return ret;
}

bool
Region::contains(Coord const &coord)
{
  return ((c1.x <= coord.x) &&
          (c2.x >= coord.x) &&
          (c1.y <= coord.y) &&
          (c2.y >= coord.y) &&
          (c1.z <= coord.z) &&
          (c2.z >= coord.z));
}

bool 
Region::operator==(Region const &rhs)
{
  return ((c1 == rhs.c1) &&
          (c2 == rhs.c2));
}

void
Region::dump()
{
  std::cout << "Region coords:" << std::endl;
  c1.dump();
  c2.dump();
}
